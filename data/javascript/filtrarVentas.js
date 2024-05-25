// Datos de ventas mensuales por región
const salesData = [
    { region: 'Norte', month: 'Enero', sales: 1500 },
    { region: 'Norte', month: 'Febrero', sales: 1800 },
    { region: 'Sur', month: 'Enero', sales: 2200 },
    { region: 'Sur', month: 'Febrero', sales: 1900 },
    { region: 'Norte', month: 'Marzo', sales: 2500 },
    { region: 'Norte', month: 'Abril', sales: 2800 },
    { region: 'Sur', month: 'Marzo', sales: 3000 },
    { region: 'Sur', month: 'Abril', sales: 2700 }
];

// Filtrar ventas solo para la región Norte
const salesDataNorth = salesData.filter(sale => sale.region === 'Norte');

// Agrupar ventas por mes en la región Norte
const salesByMonthNorth = salesDataNorth.reduce((result, sale) => {
    if (!result[sale.month]) {
        result[sale.month] = [];
    }
    result[sale.month].push(sale.sales);
    return result;
}, {});

// Calcular el total de ventas por mes en la región Norte
const totalSalesByMonthNorth = {};
for (const month in salesByMonthNorth) {
    const totalSales = salesByMonthNorth[month].reduce((total, sales) => total + sales, 0);
    totalSalesByMonthNorth[month] = totalSales;
}

console.log('Total de ventas por mes en la región Norte:');
console.log(totalSalesByMonthNorth);