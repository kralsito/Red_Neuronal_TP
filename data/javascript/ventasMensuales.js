const monthlySalesData = [
    { month: 'Enero', sales: 1500 },
    { month: 'Febrero', sales: 1800 },
    { month: 'Marzo', sales: 2200 },
    { month: 'Abril', sales: 1900 },
    { month: 'Mayo', sales: 2500 },
    { month: 'Junio', sales: 2800 },
    { month: 'Julio', sales: 3000 },
    { month: 'Agosto', sales: 2700 },
    { month: 'Septiembre', sales: 3200 },
    { month: 'Octubre', sales: 3500 },
    { month: 'Noviembre', sales: 3800 },
    { month: 'Diciembre', sales: 4000 }
];

// Calcular la suma total de las ventas mensuales
const totalSales = monthlySalesData.reduce((total, month) => total + month.sales, 0);

// Calcular el promedio de ventas mensuales
const averageSales = totalSales / monthlySalesData.length;

console.log(`La suma total de ventas es: ${totalSales}`);
console.log(`El promedio de ventas mensuales es: ${averageSales}`);
