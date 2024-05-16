function esPalindromo(cadena) {
    const caracteres = cadena.toLowerCase().replace(/[\W_]/g, '');
    return caracteres === caracteres.split('').reverse().join('');
  }
  
  // Ejemplo de uso
  const cadena = 'Anita lava la tina';
  console.log(esPalindromo(cadena)); // Salida: true
  