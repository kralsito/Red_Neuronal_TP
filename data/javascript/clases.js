class Animal {
    constructor(name) {
        this.name = name;
    }

    makeSound() {
        console.log("Animal sound");
    }
}

class Dog extends Animal {
    constructor(name) {
        super(name);
    }

    makeSound() {
        console.log("Woof");
    }
}

class Cat extends Animal {
    constructor(name) {
        super(name);
    }

    makeSound() {
        console.log("Meow");
    }
}

let animal = new Animal("Generic Animal");
animal.makeSound();  // Output: Animal sound

let dog = new Dog("Buddy");
dog.makeSound();  // Output: Woof

let cat = new Cat("Whiskers");
cat.makeSound();  // Output: Meow
