const movies = [
    { title: 'Interstellar', genre: 'Ciencia Ficción', rating: 8.6 },
    { title: 'The Shawshank Redemption', genre: 'Drama', rating: 9.3 },
    { title: 'Inception', genre: 'Ciencia Ficción', rating: 8.8 },
    { title: 'The Godfather', genre: 'Crimen', rating: 9.2 },
    { title: 'Pulp Fiction', genre: 'Crimen', rating: 8.9 }
];

// Contar películas por género
const movieCountsByGenre = movies.reduce((counts, movie) => {
    counts[movie.genre] = (counts[movie.genre] || 0) + 1;
    return counts;
}, {});

console.log('Cantidad de películas por género:');
console.log(movieCountsByGenre);
