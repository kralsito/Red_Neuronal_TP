function suma(...numeros) {
    if (numeros.some(num => typeof num !== 'number')) {
      throw new Error('Todos los argumentos deben ser números');
    }
    return numeros.reduce((acc, num) => acc + num, 0);
}
function resta(...numeros) {
    if (numeros.some(num => typeof num !== 'number')) {
      throw new Error('Todos los argumentos deben ser números');
    }
    return numeros.reduce((acc, num) => acc - num);
}
function multiplicacion(...numeros) {
    if (numeros.some(num => typeof num !== 'number')) {
      throw new Error('Todos los argumentos deben ser números');
    }
    return numeros.reduce((acc, num) => acc * num, 1);
}
function division(...numeros) {
    if (numeros.some(num => typeof num !== 'number')) {
      throw new Error('Todos los argumentos deben ser números');
    }
    if (numeros.some(num => num === 0)) {
      throw new Error('No se puede dividir por cero');
    }
    return numeros.reduce((acc, num) => acc / num);
}
