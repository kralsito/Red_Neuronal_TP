// Función para validar un correo electrónico
function validateEmail(email) {
    const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return regex.test(email);
}

// Ejemplo de uso
const email = 'usuario@example.com';
console.log(`El correo electrónico ${email} es ${validateEmail(email) ? 'válido' : 'inválido'}.`);
