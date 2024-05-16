function combinaciones(matriz) {
    const backtrack = (resultado, camino, inicio) => {
      resultado.push(camino.slice());
      for (let i = inicio; i < matriz.length; i++) {
        camino.push(matriz[i]);
        backtrack(resultado, camino, i + 1);
        camino.pop();
      }
    };
    
    const resultado = [];
    backtrack(resultado, [], 0);
    return resultado;
  }
  
  // Ejemplo de uso
  const matriz = [[1, 2], [3, 4], [5, 6]];
  console.log(combinaciones(matriz)); // Salida: [[1, 2], [1, 3], [1, 4], [1, 5], [1, 6], [2, 3], [2, 4], [2, 5], [2, 6], [3, 4], [3, 5], [3, 6], [4, 5], [4, 6], [5, 6]]
  