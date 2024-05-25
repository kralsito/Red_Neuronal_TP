let fruits = ["Manzana", "Banana", "Naranja"];

// Acceder a elementos
console.log(fruits[0]); // Manzana
console.log(fruits[1]); // Banana

// Cambiar un elemento
fruits[2] = "Kiwi";
console.log(fruits[2]); // Kiwi

// Obtener el tamaño del arreglo
console.log(fruits.length); // 3

let fruits = ["Manzana", "Banana"];

// Agregar al final
fruits.push("Naranja");
console.log(fruits); // ["Manzana", "Banana", "Naranja"]

// Eliminar del final
let lastFruit = fruits.pop();
console.log(lastFruit); // Naranja
console.log(fruits); // ["Manzana", "Banana"]

let fruits = ["Naranja", "Manzana", "Banana"];

// Ordenar alfabéticamente
fruits.sort();
console.log(fruits); // ["Banana", "Manzana", "Naranja"]

let numbers = [5, 1, 8, 3, 2];

// Ordenar numéricamente
numbers.sort(function(a, b) {
    return a - b;
});
console.log(numbers); // [1, 2, 3, 5, 8]

let fruits = ["Manzana", "Banana", "Naranja"];

// Verificar si el arreglo contiene un elemento específico
console.log(fruits.includes("Banana")); // true
console.log(fruits.includes("Kiwi")); // false

let numbers2 = [1, 2, 3, 4, 5];

// Crear un nuevo arreglo con los elementos mayores a 3
let filtered = numbers2.filter(function(number) {
    return number > 3;
});
console.log(filtered); // [4, 5]
