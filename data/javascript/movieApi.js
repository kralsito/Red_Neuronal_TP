var jwt = ''

$(document).ready(function () {
  $.ajax({
    url: 'https://gestionweb.frlp.utn.edu.ar/api/auth/local',
    method: 'POST',
    dataType: 'json',
    data: {
      identifier: 'api-user@example.com',
      password: '123456'
    },
    success: function (response) {
      jwt = response.jwt
      console.log(jwt)
    },
    error: function (error) {
      console.log(error);
    }
  });
});

var movieData;

function show() {
    if (document.getElementById('movieApi').style.display == "block") {
        document.getElementById('movieApi').style.display = "none";
    }
    else {
        document.getElementById('movieApi').style.display = "block";
        document.getElementById('movie-list').style.display = "none";
        document.getElementById('movie-chart').style.display = "none";
    }
}

function searchMovie() {
    stars.forEach(star => star.classList.remove("active")); //Se reinicia el puntaje de la película, en caso de haber puntuado otra antes.
    var searchQuery = document.getElementById('searchInput').value;
    const apiUrl = `http://www.omdbapi.com/?apikey=2d435d7a&t=${searchQuery}`;
    $.ajax({
        url: apiUrl,
        success: function(data) { 
            if (data.Response === "True") { //Si el texto ingresado en el input coincide con una película de la API
                document.getElementById('no-result').style.display = "none";
                document.getElementById('all-movie').style.display = "block";
                document.getElementById('movie-title').innerHTML = data.Title;
                document.getElementById('movie-year').innerHTML = data.Year + ' | ' + data.Genre ;
                document.getElementById('movie-director').innerHTML =  'Director: ' + data.Director;
                document.getElementById('movie-actors').innerHTML = 'Cast: ' + data.Actors;
                document.getElementById('movie-plot').innerHTML = data.Plot;
                document.getElementById('movie-poster').src = data.Poster;     
            }
            else if (searchQuery === '') { //Si se ingresó un input vacío
                document.getElementById('all-movie').style.display = "none";
                document.getElementById('no-result').style.display = "block";
            }
        },
        error: function() { //Si hubo otro error
            document.getElementById('allMovie').innerHTML = 'Ocurrió un error al realizar la búsqueda.';
    }
  });
  movieData = {                                                     //agregue yo
    "Title": document.getElementById('movie-title').innerHTML,
    "Poster": document.getElementById('movie-poster').src
  };
}


document.getElementById('rating-1').value='1';
document.getElementById('rating-2').value='2';
document.getElementById('rating-3').value='3';
document.getElementById('rating-4').value='4';
document.getElementById('rating-5').value='5';


//Rate para las películas

var movieData;
var movieRatings = {};

var stars = document.querySelectorAll(".stars i");
function getID() {
    var btnID = event.target.id;
}
stars.forEach((star, index1) => {
  star.addEventListener("click", () => {
    stars.forEach((star, index2) => {
      index1 >= index2 ? star.classList.add("active") : star.classList.remove("active");
    });
  });
});

function isMovieRated(movieTitle) {
  var storedMovieRatings = localStorage.getItem("movieRatings");
  if (storedMovieRatings) {
    var movieRatings = JSON.parse(storedMovieRatings);
    return movieRatings[movieTitle] && movieRatings[movieTitle].Rating;
  }
  return false;
}


function addRating() {
  var activeStar = document.querySelector(".stars .active");
  var activeStars = document.querySelectorAll(".stars .active");
  if (activeStar) {
    var ratingValue = activeStars.length.toString();
    var movieTitle = document.getElementById('movie-title').innerHTML;
    var moviePoster = document.getElementById('movie-poster').src;

    if (isMovieRated(movieTitle)) {
      console.log("Esta película ya ha sido puntuada. No se puede puntuar nuevamente.");
      Swal.fire({
        title: 'Esta pelicula ya se puntúo',
        icon: 'error',
      });
      return;
    }  
    else {
      movieRatings[movieTitle] = {
        "Title": movieTitle,
        "Poster": moviePoster,
        "Rating": ratingValue,
      };

      localStorage.setItem("movieRatings", JSON.stringify(movieRatings));

      $.ajax({
        url: 'https://gestionweb.frlp.utn.edu.ar/api/g15-peliculas',
        type: 'POST',
        dataType: 'json',
        headers: {
          'Content-Type': 'application/json',
          'Authorization': `Bearer ${jwt}`
        },
        data: JSON.stringify({
          "data": {
            "Title": movieTitle,
            "Poster": moviePoster,
            "Rating": ratingValue
          }
        }),
        success: function (response) {
          console.log(response);
          Swal.fire({
            title: 'Se puntuó correctamente',
            icon: 'success',
          });
          createPieChart();
        },
        error: function (error) {
          console.log(error);
          Swal.fire({
            title: 'Error al puntuar',
            text: 'Ocurrió un error al guardar la puntuación.',
            icon: 'error',
          });
        }
      });
      
    }
  } else {
    console.log("Por favor, seleccione un valor de rating antes de guardar.");
  }
}

function rateFuncion() {
  if (document.getElementById('movie-list').style.display == "block") {
    document.getElementById('movie-list').style.display = "none";
  }
  else {
    document.getElementById('movie-list').style.display = "block";
    document.getElementById('movieApi').style.display = "none";
    document.getElementById('movie-chart').style.display = "none";
}
  getPuntuaciones();
}

function getPuntuaciones() {
  $.ajax({
    url: 'https://gestionweb.frlp.utn.edu.ar/api/g15-peliculas',
    type: 'GET',
    dataType: 'json',
    headers: {
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${jwt}`
    },
    success: function (response) {
      console.log(response);

      if (Array.isArray(response.data)) {
        var movieList = document.getElementById('movie-list');
        movieList.innerHTML = '';

        // Actualizar el objeto movieRatings con los datos del localStorage
        var storedMovieRatings = localStorage.getItem("movieRatings");
        if (storedMovieRatings) {
          movieRatings = JSON.parse(storedMovieRatings);
        }

        response.data.forEach(function (movie) {
          var listItem = document.createElement('div');
          listItem.setAttribute("class", "movie-item");

          var movieTitle = movie.attributes.Title;
          // Verificar si la película está eliminada
          if (movieRatings[movieTitle] && movieRatings[movieTitle].deleted) {
            return; // Si está eliminada, saltar a la siguiente iteración
          }

          listItem.innerHTML = `
              <div class="movie-poster-rating"><img src="${movie.attributes.Poster}" alt="Movie Poster"></div>
              <div class="movie-title-rating">${movie.attributes.Title}</div>
              <div class="movie-rating-rating">${movie.attributes.Rating} estrellas</div>
              <button class="btn btn-primary deletebtn" onclick="eliminarPeliculaPuntuada('${movie.id}')">Eliminar</button>
          `;
          movieList.appendChild(listItem);
        });
      } else {
        console.log('La respuesta de la API no contiene datos válidos o está vacía.');
      }
    },
    error: function (error) {
      console.log(error);
      Swal.fire({
        title: 'Error al obtener puntuaciones',
        text: 'Ocurrió un error al obtener las puntuaciones.',
        icon: 'error',
      });
    }
  });
}


function eliminarPeliculaPuntuada(movieID) {
  $.ajax({
    url: `https://gestionweb.frlp.utn.edu.ar/api/g15-peliculas/${movieID}`,
    type: 'DELETE',
    dataType: 'json',
    headers: {
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${jwt}`
    },
    success: function (response) {
      console.log(response);
      var movieTitle = response.data.attributes.Title;

      // Eliminar la película del objeto movieRatings
      if (movieRatings[movieTitle]) {
        delete movieRatings[movieTitle].deleted;
        delete movieRatings[movieTitle].Rating; 
      }

      // Eliminar la película del localStorage
      localStorage.setItem("movieRatings", JSON.stringify(movieRatings));

      getPuntuaciones();
    },
    error: function (error) {
      console.log(error);
    }
  });
}


var movieRatings = {}; // Variable para almacenar las calificaciones de las películas

function pieChartBtn () {
  if (document.getElementById('movie-chart').style.display == "block") {
    document.getElementById('movie-chart').style.display = "none";
  }
  else {
    document.getElementById('movie-chart').style.display = "block";
    document.getElementById('movie-list').style.display = "none";
    document.getElementById('movieApi').style.display = "none";
  }
  createPieChart();
}

function createPieChart() { //Función para crear el gráfico de las películas rateadas
  var storedMovieRatings = localStorage.getItem("movieRatings");
  if (storedMovieRatings) {
    movieRatings = JSON.parse(storedMovieRatings);

    var ratingCounts = {}; // Objeto para almacenar la cantidad de películas por rating
    var totalMovies = 0; // Contador para el total de películas puntuadas

    // Contar la cantidad de películas por rating
    for (var movieTitle in movieRatings) {
      var rating = parseInt(movieRatings[movieTitle].Rating);
      if (!isNaN(rating)) {
        ratingCounts[rating] = (ratingCounts[rating] || 0) + 1;
        totalMovies++;
      }
    }

    // Preparar los datos para el gráfico de torta
    var pieData = [];
    for (var rating in ratingCounts) {
      var percentage = (ratingCounts[rating] / totalMovies) * 100;
      pieData.push({
        rating: rating,
        count: ratingCounts[rating],
        percentage: percentage.toFixed(2) + "%",
      });
    }

    // Obtener el contexto del elemento canvas donde se mostrará el gráfico
    var ctx = document.getElementById("pieChart").getContext("2d");

    // Configurar los datos y opciones del gráfico de torta
    var data = {
      labels: pieData.map((data) => data.rating),
      datasets: [{
        data: pieData.map((data) => data.count),
        backgroundColor: ["#78f39d", "#d89ae7", "#f58766", "#ffa7b6", "#a5dee0"],
      }],
    };

    var options = {
      title: {
        display: true,
        text: "Gráfico de Torta de Películas Puntuadas por Rating",
      },
    };

    // Crear el gráfico de torta
    new Chart(ctx, {
      type: "pie",
      data: data,
      options: options,
    });
  }
}
