using System;

interface IShape {
    double GetArea();
}

class Rectangle : IShape {
    public double Width { get; set; }
    public double Height { get; set; }

    public double GetArea() {
        return Width * Height;
    }
}

class Circle : IShape {
    public double Radius { get; set; }

    public double GetArea() {
        return Math.PI * Radius * Radius;
    }
}

class Program {
    static void Main(string[] args) {
        Rectangle rectangle = new Rectangle() { Width = 5, Height = 3 };
        Circle circle = new Circle() { Radius = 4 };

        Console.WriteLine("Rectangle Area: " + rectangle.GetArea());  // Output: Rectangle Area: 15
        Console.WriteLine("Circle Area: " + circle.GetArea());  // Output: Circle Area: 50.26548245743669
    }
}
