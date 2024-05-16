// Simple function

function createObjectWithConstructor(){
    function vehicle(name,maker,engine){
        this.name = name;
        this.maker = maker;
        this.engine = engine;
    }
    // New keyword to create an object
    let car  = new vehicle('GT','BMW','1998cc');
    // Property accessors
    console.log(car.name);
    console.log(car.maker);
    console.log(car['engine']);
}

function createObjectUsingObjectLiterals(){
    let alumno = {
        name: 'Sergio',
        lastName: 'Gonzalez',
    }
    console.log(alumno.name);
    console.log(alumno.lastName);
}

function createObjectWithFunction(){
    const coder = {
        isStudying : false,
        printIntroduction : function(){
            console.log(`My name is ${this.name}. Am I studying?: ${this.isStudying}`);
        }
    };
    const me = Object.create(coder);
    me.name = 'Mukul';
    me.isStudying = true;
    me.printIntroduction();
}

function createObjectWithES6Classes(){
    // Usando clases ES6
    class Book {
        constructor(title, author, year) {
        this.title = title;
        this.author = author;
        this.year = year;
        }
    }
    
    // Creación de una instancia de la clase Book
    let book1 = new Book('1984', 'George Orwell', 1949);
    
    // Imprimir el título del libro
    console.log(book1.title);  // 1984
}  