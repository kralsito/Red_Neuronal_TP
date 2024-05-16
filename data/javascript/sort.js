function mergeSort(arreglo) {
    if (arreglo.length <= 1) {
      return arreglo;
    }
    
    const medio = Math.floor(arreglo.length / 2);
    const izquierda = mergeSort(arreglo.slice(0, medio));
    const derecha = mergeSort(arreglo.slice(medio));
    
    return merge(izquierda, derecha);
  }
  
  function merge(izquierda, derecha) {
    let resultado = [];
    let i = 0;
    let j = 0;
    
    while (i < izquierda.length && j < derecha.length) {
      if (izquierda[i] < derecha[j]) {
        resultado.push(izquierda[i]);
        i++;
      } else {
        resultado.push(derecha[j]);
        j++;
      }
    }
    
    return resultado.concat(izquierda.slice(i)).concat(derecha.slice(j));
  }
  