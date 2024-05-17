using System;

class Animal {
    public string Name { get; set; }
    public virtual void MakeSound() {
        Console.WriteLine("Animal sound");
    }
}

class Dog : Animal {
    public override void MakeSound() {
        Console.WriteLine("Woof");
    }
}

class Cat : Animal {
    public override void MakeSound() {
        Console.WriteLine("Meow");
    }
}

class Program {
    static void Main(string[] args) {
        Animal animal = new Animal();
        animal.MakeSound();  // Output: Animal sound

        Dog dog = new Dog();
        dog.MakeSound();  // Output: Woof

        Cat cat = new Cat();
        cat.MakeSound();  // Output: Meow
    }
}
