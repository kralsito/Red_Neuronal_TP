#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


struct vehiculo { //datos de los vehiculos
    int tipo;
    int patenten;
    char patentel[7];
};

struct lista { //lista con los datos del vehiculo y el nodo siguiente
    struct vehiculo dato;
    struct lista *ps;
};

struct final { //datos de la lista final 
    int patenten;
    char patentel[7];
    int vtipo;
    int horas;
    float monto;
};

struct lfinal {
    struct final dato;
    struct lfinal *ps;
};

void carga(struct lista **l); //Lista para el ingreso de vehiculos 
void salida(struct lista **l,struct lfinal **f,float tarifa[]); //Lista para el egreso de vehiculos donde se borran y se cargan en la lista final
void total(struct lfinal *f, float *tot); //Se recorre de manera recursiva buscando el monto total recaudado en el dia

int main(void){
    struct lista *l=0;
    struct lfinal *f=0;
    int i=1, rta=5, type;
    float tot, precio, tarifa[3];
    printf("CARGA DE PRECIOS\n");
    while(i==1){
        printf("Ingrese el tipo de vehiculo 1 auto 2 moto 3 camioneta\n");
        scanf("%d",&type);
        printf("Ingrese el precio de la estadia por hora\n");
        scanf("%f",&precio);
        tarifa[type]=precio;
        printf("Hay otro precio para cargar? 1 si 0 no\n");
        scanf("%d",&i);
    }
    while(rta!=0){
        printf("MENU\n"); //menu para seleccionar opcion
        printf("1. Ingresar un vehiculo\n");
        printf("2. Egresar un vehiculo\n");
        printf("3. Obtener total de recaudacion\n");
        printf("0. Salir\n");
        scanf("%d",&rta);
        switch(rta){
            case 1:
            carga(&l);
            break;
            case 2:
            salida(&l,&f,tarifa);
            break;
            case 3:
            total(l,&tot);
            printf("El monto recaudado es de %f: \n",tot);
            break;
            case 0:
            printf("Saliendo..\n");
            break;
            default:
            printf("Opcion incorrecta. Seleccione otra vez\n");
            break;
        }
    }
}

void carga(struct lista **l){
    struct lista *nuevo=malloc(sizeof(struct lista));
   printf("INGRESO DE VEHICULOS\n");
   printf("Ingrese los numeros de la patente\n");
   scanf("%d",&nuevo->dato.patenten);
   printf("Ingrese las letras de la patente\n");
   scanf("%s",nuevo->dato.patentel);
   printf("Ingrese el tipo de vehiculo: 1 auto 2 moto 3 camioneta\n");
   scanf("%d",&nuevo->dato.tipo);
   nuevo->ps=*l;
    *l=nuevo;
}

void salida(struct lista **l, struct lfinal **f, float tarifa[]){
    struct lista *act;
    struct lista *ant;
    struct lfinal *auxi;
    auxi=*f;
    int num, horas;
    char letras[7];
    if(*l==0){
        printf("No hay vehiculos cargados\n");
    }
    else{
        ant=0;
        act=*l;
        printf("EGRESO DE VEHICULOS\n");
        printf("Ingrese los numeros de la patente\n");
        scanf("%d",&num);
        while(act!=0 && num!=act->dato.patenten){
            ant=act;
            act=act->ps;
        }
        if(act==0){
            printf("No se encontro el numero de patente\n");
		}
        else if(num==act->dato.patenten){
            printf("Ingrese las letras de la patente\n");
            scanf("%s",letras);
            while(act!=0){
                if(act->dato.patentel !=letras){
                    ant=act;
                    act=act->ps;
                }
            }
            if(act==0){
                printf("No se encontraron las letras de la patente\n");
            }
                if(act->dato.patentel==letras){
                    printf("PATENTE ENCONTRADA\n");
                    printf("Ingrese el numero de horas que estuvo el vehiculo en el estacionamiento\n");
                    scanf("%d",&horas);
                    auxi->dato.horas=horas;
                    auxi->dato.vtipo=act->dato.tipo;
                    strcpy(auxi->dato.patentel,act->dato.patentel);
                    auxi->dato.patenten=act->dato.patenten;
                    auxi->dato.monto= tarifa[auxi->dato.vtipo]*horas;
                    *f=auxi;
                    free(act);
                }
        }
    }
}

void total(struct lfinal *f,float *tot){
    if(f==0){
        *tot=0;
    }
    else{
        *tot=*tot+f->dato.monto;
        total(f->ps,tot);
    }
}
