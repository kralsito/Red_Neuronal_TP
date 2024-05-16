function buscarSubcadena(cadena, subcadena) {
    const calcularTablaLPS = (subcadena) => {
      const lps = new Array(subcadena.length).fill(0);
      let longitud = 0;
      let i = 1;
  
      while (i < subcadena.length) {
        if (subcadena[i] === subcadena[longitud]) {
          longitud++;
          lps[i] = longitud;
          i++;
        } else {
          if (longitud !== 0) {
            longitud = lps[longitud - 1];
          } else {
            lps[i] = 0;
            i++;
          }
        }
      }
  
      return lps;
    };
  
    const lps = calcularTablaLPS(subcadena);
    const resultados = [];
    let i = 0;
    let j = 0;
  
    while (i < cadena.length) {
      if (subcadena[j] === cadena[i]) {
        i++;
        j++;
      }
      if (j === subcadena.length) {
        resultados.push(i - j);
        j = lps[j - 1];
      } else if (i < cadena.length && subcadena[j] !== cadena[i]) {
        if (j !== 0) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }
    }
  
    return resultados;
  }
  
  // Ejemplo de uso
  const cadena = 'ababcabcabababd';
  const subcadena = 'ababd';
  console.log(buscarSubcadena(cadena, subcadena)); // Salida: [10]
  