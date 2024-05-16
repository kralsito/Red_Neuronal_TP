/*
 * C# Program to Obtain the Character from the User and Convert 
 * the Case of the Character
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace casechange
{
    class Program
    {
        static void Main(string[] args)
        {
            char a;
            int i;
            Console.WriteLine("Enter the Character : ");
            a = Convert.ToChar(Console.ReadLine());
            i=(int)a;
            if (a >= 65 && a <= 90)
            {
 
                Console.WriteLine("The Character is : {0}", char.ToLower(a));
 
            }
            else if (a >= 97 && a <= 122)
            {
                Console.WriteLine("The Character is : {0}", char.ToUpper(a));
            }
            Console.ReadLine();
        }
    }