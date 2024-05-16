function descifrarVigenere(textoCifrado, clave) {
    const alfabeto = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    let resultado = '';
  
    for (let i = 0; i < textoCifrado.length; i++) {
      const letraTextoCifrado = textoCifrado[i];
      const letraClave = clave[i % clave.length].toUpperCase();
      const indiceTextoCifrado = alfabeto.indexOf(letraTextoCifrado.toUpperCase());
      const indiceClave = alfabeto.indexOf(letraClave);
      
      if (indiceTextoCifrado === -1) {
        resultado += letraTextoCifrado;
      } else {
        let indiceDescifrado = (indiceTextoCifrado - indiceClave) % alfabeto.length;
        if (indiceDescifrado < 0) {
          indiceDescifrado += alfabeto.length;
        }
        resultado += alfabeto[indiceDescifrado];
      }
    }
  
    return resultado;
  }
  
  // Ejemplo de uso
  const textoCifrado = 'RIJVSUYVJN';
  const clave = 'KEY';
  console.log(descifrarVigenere(textoCifrado, clave)); // Salida: 'HELLOWORLD'
  