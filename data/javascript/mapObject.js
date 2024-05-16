function basicMethod() {
    let map1 = new Map([
        [1, 2],
        [2, 3],
        [4, 5]
    ]);
    
    console.log("Map1");
    console.log(map1);
    
    let map2 = new Map([
        ["firstname", "sumit"],
        ["lastname", "ghosh"],
        ["website", "geeksforgeeks"]
    ]);
    
    console.log("Map2");
    console.log(map2);
}

function setMethod() {
    let map1 = new Map();
    map1.set("FirstName", "Shobhit");
    map1.set("LastName", "Sharma");
    map1.set("website", "GeeksforGeeks");
    
    console.log(map1);
}

function mapMethod() {
    // Crear un nuevo mapa
    let map1 = new Map();

    // Añadir elementos al mapa
    map1.set("nombre", "Carlos")
        .set("apellido", "Ramirez")
        .set("profesión", "Ingeniero")
        .set("hobby 1", "fotografía")
        .set("hobby 2", "lectura");

    // Imprimir el mapa completo
    console.log("Mapa completo:", map1);

    // Verificar si el mapa tiene una clave específica
    console.log("¿map1 tiene la clave 'profesión'? " + map1.has("profesión"));
    console.log("¿map1 tiene la clave 'hobby 3'? " + map1.has("hobby 3"));

    // Obtener valores asociados a una clave específica
    console.log("Valor para la clave 'profesión': " + map1.get("profesión"));
    console.log("Valor para la clave 'hobby 3': " + map1.get("hobby 3"));

    // Eliminar un elemento del mapa usando su clave
    console.log("Eliminar elemento con clave 'profesión': " + map1.delete("profesión"));

    // Verificar si el elemento fue eliminado
    console.log("¿map1 tiene la clave 'profesión'? " + map1.has("profesión"));

    // Intentar eliminar un elemento que no existe
    console.log("Eliminar elemento con clave 'hobby 3': " + map1.delete("hobby 3"));

    // Limpiar todos los elementos del mapa
    map1.clear();

    // Imprimir el mapa después de limpiarlo
    console.log("Mapa después de clear:", map1);
}

