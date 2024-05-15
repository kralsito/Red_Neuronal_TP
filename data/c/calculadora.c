/*
  25065787 jhonny jose arana nieves <jhonnyjosearana@gmail.com>
 */
#include <stdio.h>
/* funcion para sumar */
double suma(double x,double y){
	double resSuma;
		resSuma = x + y;
	return resSuma;
	}
/* funcion para restar*/
	double resta(double x,double y){
	double resResta;
		resResta = x - y;
	return resResta ;
	}
/* funcion para multiplicar */
	double multiplicacion(double x,double y){
	double resMulti;
		resMulti= x * y;
	return resMulti;
	}
/* funcion para dividir */
	double division(double x,double y){
	double resDivi;
		resDivi = x / y;
	return resDivi;
	}
/* funcion que muestra el menu y retorna la opcion selecionada */
int menu(){
	int opcion;
	printf("\nque operacion desea realizar.? ");
	printf("\n1  - - suma");
	printf("\n2 - - resta");
	printf("\n3 - - multiplicacion");
	printf("\n4 - -division\n\n");
	scanf("%d",&opcion);
	return opcion;
}
/* funcion main compara la opcion seleccionada y los numeros 
   introducidos llama a las funciones respectivas
   e imprime el resultado */
int main(){
	float resultado;
	int a;
	int  b;
	int opcionmenu;
	printf("\nintroduzca el primer numero:\t");
	scanf("%d",&a);
	printf("\nintroduzca el segundo numero:\t");
	scanf("%d",&b);
/* obtiene la opcion selecionada e invoca las otras funciones */	
	opcionmenu = menu(); 
		if(opcionmenu == 1){
			resultado = suma(a,b);
		} else if(opcionmenu == 2) {
			resultado= resta(a,b);
		} else if(opcionmenu == 3) {	
			resultado = multiplicacion(a,b);
		} else if(opcionmenu == 4){
			resultado = division(a,b);
		}
/* imprime el resultado */
	printf("\nel resultado es: %f",resultado);
	return 0;
}

/*
  25065787 jhonny jose arana nieves <jhonnyjosearana@gmail.com>
 */
#include <stdio.h>
/*funcion celsius a kelvin*/
double kelvin(double x){
	double resKelvin;
		resKelvin = x + 273.15 ;
	return resKelvin;
	}
/*funcion celsius a fahrenheit*/
double fahrenheit(double x){
	double resFah;
		resFah = x * 9/5 + 32;
	return resFah ;
	}
/*menu de opciones*/
int menu(){
	int opcion;
	printf("\ncomo desea hacer la conversion ");
	printf("\n1  - - celsius a kelvin\n");
	printf("\n2 - - celcius a fahrenheit\n\n");
	scanf("%d",&opcion);
	return opcion;
}
/*funcion main obtiene y retorna datos*/
int main(){
	float resultado;
	int a;
	int opcionmenu;
	printf("\nintroduzca el valor en grados celcius:\t");
	scanf("%d",&a);
	opcionmenu = menu(); 
		if(opcionmenu == 1){
			resultado = kelvin(a);
		} else if(opcionmenu == 2) {
			resultado= fahrenheit(a);
		} 
/* imprime el resultado */
	printf("\nel resultado es: %f",resultado);
	return 0;
}