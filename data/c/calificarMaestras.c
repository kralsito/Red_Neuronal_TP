/*En una escuela primaria se solicita a los 30 alumnos del sexto curso que califiquen a sus 3 maestras.
Para hacerlo, deben agruparse de a 5 y cada grupo asignar una nota entre 1 y 10 a cada maestra.
Se requiere un informe en el que se detalle, para cada maestra, la nota que cada grupo le asignó y la nota promedio que obtuvo.*/
#include <stdio.h>
#include <conio.h>
main(){
	//declaracion de variables
	float grupo1a;
	float grupo1b;
	float grupo1c;

	float grupo2a;
	float grupo2b;
	float grupo2c;

	float grupo3a;
	float grupo3b;
	float grupo3c;

	float grupo4a;
	float grupo4b;
	float grupo4c;

	float grupo5a;
	float grupo5b;
	float grupo5c;

	float grupo6a;
	float grupo6b;
	float grupo6c;

	float notamaestraa;
	float notamaestrab;
	float notamaestrac;

	//ingreso de datos

	printf ("ingresar nota de grupo1a \n");
	scanf ("%f",&grupo1a);

	printf ("ingresar nota de grupo1b \n");
	scanf ("%f",&grupo1b);

	printf ("ingresar nota de grupo1c \n");
	scanf ("%f",&grupo1c);

	printf ("ingresar nota de grupo2a \n");
	scanf ("%f",&grupo2a);

	printf ("ingresar nota de grupo2b \n");
	scanf ("%f",&grupo2b);

	printf ("ingresar nota de grupo2c \n");
	scanf ("%f",&grupo2c);

	printf ("ingresar nota de grupo3a \n");
	scanf ("%f",&grupo3a);

	printf ("ingresar nota de grupo3b \n");
	scanf ("%f",&grupo3b);

	printf ("ingresar nota de grupo3c \n");
	scanf ("%f",&grupo3c);

	printf ("ingresar nota de grupo4a \n");
	scanf ("%f",&grupo4a);

	printf ("ingresar nota de grupo4b \n");
	scanf ("%f",&grupo4b);

	printf ("ingresar nota de grupo4c \n");
	scanf ("%f",&grupo4c);

	printf ("ingresar nota de grupo5a \n");
	scanf ("%f",&grupo5a);

	printf ("ingresar nota de grupo5b \n");
	scanf ("%f",&grupo5b);

	printf ("ingresar nota de grupo5c \n");
	scanf ("%f",&grupo5c);

	printf ("ingresar nota de grupo6a \n");
	scanf ("%f",&grupo6a);

	printf ("ingresar nota de grupo6b \n");
	scanf ("%f",&grupo6b);

	printf ("ingresar nota de grupo6c \n");
	scanf ("%f",&grupo6c);

	//calculos

	notamaestraa=(grupo1a+grupo2a+grupo3a+grupo4a+grupo5a+grupo6a)/6;
	notamaestrab=(grupo1b+grupo2b+grupo3b+grupo4b+grupo5b+grupo6b)/6;
	notamaestrac=(grupo1c+grupo2c+grupo3c+grupo4c+grupo5c+grupo6c)/6;

	if ((notamaestraa<notamaestrab)&&(notamaestrac<notamaestrab)) { printf ("La ganadora es la maestra b con una nota de: %f",notamaestrab);
	}else if((notamaestrab<notamaestrac) && (notamaestraa<notamaestrac)){ printf("La ganadora es la maestra c con una nota de: %f",notamaestrac);
	}else  printf ("La ganadora es la maestra a con una nota de: %f",notamaestraa);



	_getch();
}
