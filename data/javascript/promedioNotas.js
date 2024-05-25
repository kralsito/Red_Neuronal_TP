let grades = [85, 92, 78, 90, 88];

function calculateAverage(grades) {
    let total = grades.reduce((sum, grade) => sum + grade, 0);
    return total / grades.length;
}

let average = calculateAverage(grades);
console.log(`El promedio de las notas es: ${average}`);

if (average >= 90) {
    console.log("Excelente trabajo");
} else if (average >= 80) {
    console.log("Buen trabajo");
} else {
    console.log("Necesitas mejorar");
}
