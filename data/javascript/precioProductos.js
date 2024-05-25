let products = [
    { name: "Producto 1", price: 30 },
    { name: "Producto 2", price: 20 },
    { name: "Producto 3", price: 50 },
    { name: "Producto 4", price: 40 }
];

function filterByPrice(products, maxPrice) {
    return products.filter(product => product.price <= maxPrice);
}

let affordableProducts = filterByPrice(products, 35);
console.log("Productos asequibles:");
affordableProducts.forEach(product => {
    console.log(`${product.name} - $${product.price}`);
});
