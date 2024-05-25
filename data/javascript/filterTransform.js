const numbers = [1, 2, 3, 4, 5];

// Duplicar cada número en el array
const doubledNumbers = numbers.map(num => num * 2);
console.log('Números duplicados:', doubledNumbers);

// Filtrar números pares
const evenNumbers = numbers.filter(num => num % 2 === 0);
console.log('Números pares:', evenNumbers);
