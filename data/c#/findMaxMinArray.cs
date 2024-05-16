/*
 * C# Program to Find Minimum and Maximum of Numbers
 */
using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] array1 = { 10, -10, -20, 0,15,20,30 };
        Console.WriteLine("Maximum Element : " +array1.Max());
        Console.WriteLine("Minimum Element : " +array1.Min());
        Console.Read();
    }
}