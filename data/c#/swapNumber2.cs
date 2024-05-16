using System;  
  public class SwapExample  
   {  
     public static void Main(string[] args)  
      {  
       int  a=5, b=10;            
       Console.WriteLine("Before swap a= "+a+" b= "+b);    
       a=a+b; //a=15 (5+10)      
       b=a-b; //b=5 (15-10)      
       a=a-b; //a=10 (15-5)   
       Console.Write("After swap a= "+a+" b= "+b);       
      }  
  }  