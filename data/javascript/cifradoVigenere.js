function cifrarVigenere(texto, clave) {
    const alfabeto = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    let resultado = '';
  
    for (let i = 0; i < texto.length; i++) {
      const letraTexto = texto[i];
      const letraClave = clave[i % clave.length].toUpperCase();
      const indiceTexto = alfabeto.indexOf(letraTexto.toUpperCase());
      const indiceClave = alfabeto.indexOf(letraClave);
      
      if (indiceTexto === -1) {
        resultado += letraTexto;
      } else {
        const indiceCifrado = (indiceTexto + indiceClave) % alfabeto.length;
        resultado += alfabeto[indiceCifrado];
      }
    }
  
    return resultado;
  }
  
  // Ejemplo de uso
  const texto = 'HELLO';
  const clave = 'KEY';
  console.log
  