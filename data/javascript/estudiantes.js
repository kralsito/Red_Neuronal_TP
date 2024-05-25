// Definición de un objeto con información de estudiantes
const students = [
    { id: 1, name: 'Juan', age: 20, grade: 'A' },
    { id: 2, name: 'María', age: 21, grade: 'B' },
    { id: 3, name: 'Pedro', age: 22, grade: 'C' },
    { id: 4, name: 'Luisa', age: 19, grade: 'A' },
    { id: 5, name: 'Ana', age: 20, grade: 'B' }
];

// Función para calcular el promedio de edad de los estudiantes
function calculateAverageAge(students) {
    let totalAge = 0;
    students.forEach(student => {
        totalAge += student.age;
    });
    return totalAge / students.length;
}

// Función para filtrar estudiantes por grado
function filterStudentsByGrade(students, grade) {
    return students.filter(student => student.grade === grade);
}

// Función para mostrar información de estudiantes filtrados
function displayStudentsInfo(students) {
    console.log('Información de estudiantes:');
    students.forEach(student => {
        console.log(`ID: ${student.id}, Nombre: ${student.name}, Edad: ${student.age}, Grado: ${student.grade}`);
    });
}

// Calcular el promedio de edad de todos los estudiantes
const averageAge = calculateAverageAge(students);
console.log('Promedio de edad de los estudiantes:', averageAge);

// Filtrar estudiantes con grado 'A'
const gradeAStudents = filterStudentsByGrade(students, 'A');
console.log('Estudiantes con grado A:');
displayStudentsInfo(gradeAStudents);