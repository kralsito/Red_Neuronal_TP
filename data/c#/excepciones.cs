using System;

class Program {
    static void Main(string[] args) {
        try {
            int[] numbers = { 1, 2, 3 };
            Console.WriteLine(numbers[4]);  // This will throw an IndexOutOfRangeException
        } catch (IndexOutOfRangeException ex) {
            Console.WriteLine("Index out of range.");
        } catch (Exception ex) {
            Console.WriteLine("An error occurred.");
        } finally {
            Console.WriteLine("Finally block executed.");
        }
    }
}
