#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    int dia;
    int mes;
    int year;
    char hora[15];
    char actividad[60];
    char lugar [25];
}evento;


typedef struct nodo{
    evento infor;
    struct nodo* siguiente;
    struct nodo* atras;
}nodo;

nodo* primero=NULL;
nodo* ultimo=NULL;

void menu();
void agregaractividad();
void listadeactividades();
void buscar();
void eliminarevento();
//void ordenar();

int main (){
    menu();
return 0;
}

void menu(){
    int opcion=0;
    do{
        printf("_____________________________________________\n");
        printf("|--------Agenda de actividades en c---------|\n");
        printf("|-------------------------------------------|\n");
        printf("| 1. Agregar actividad 4. Eliminar evento   |\n");
        printf("| 2. Buscar actividad  5. Ver lista de activ|\n");
        printf("| 3. Modificar evento  6. Salir             |\n");
        printf("|___________________________________________|\n\n");
        printf("Escoja una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                agregaractividad();

                break;
            case 2:
                buscar();
                break;
            case 3:
                break;
            case 4:
                eliminarevento();
                break;
            case 5:
                listadeactividades();
                break;
            case 6:
                printf("\nSaliendo del programa...");
                break;
            default:
                printf("\nOpcion Invalida\n");
                break;
        }
} while(opcion!=6);
}

void agregaractividad(){
    printf("|----Agregar actividad ---------------------|\n");
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    printf("\nAgregar el dia de la actividad: ");
    scanf("%d",&nuevo->infor.dia);
    printf("\nAgregar el mes de la actividad: ");
    scanf("%d",&nuevo->infor.mes);
    printf("\nAgregar el año de la actividad: ");
    scanf("%d",&nuevo->infor.year);
    fflush(stdin);
    printf("\nIngrese la hora de la actividad (00.00.00): ");
    gets(nuevo->infor.hora);
    fflush(stdin);
    printf("\nIngrese el lugar de la actividad: ");
    gets(nuevo->infor.lugar);
    fflush(stdin);
    printf("\nIngrese que hará en dicha actividad: ");
    gets(nuevo->infor.actividad);
    fflush(stdin);
    if(primero==NULL){
        primero=nuevo;
        primero->siguiente=primero;
        ultimo=primero;
        primero->atras=ultimo;
    }else{
        ultimo->siguiente=nuevo;
        nuevo->siguiente=primero;
        nuevo->atras=ultimo;
        ultimo=nuevo;
        primero->atras=ultimo;
    }
    printf("\n La actividad fue ingresada exitosamente :) \n");
   // ordenar();
}

void listadeactividades(){
    printf("|--Ver lista de actividades-----------------|\n");
    nodo*aux=(nodo*)malloc(sizeof(nodo)); //Creacion de un apuntador de este tipo auxiliar para poder recorrer la lista.
    aux=primero;
    if(primero!=NULL){
        do{
            printf(" %d",aux->infor.dia);
            printf("/%d",aux->infor.mes);
            printf("/%d\n",aux->infor.year);
            printf("Hora: %s\n",aux->infor.hora);
            printf("Lugar: %s\n",aux->infor.lugar);
            printf("Actividad: %s\n",aux->infor.actividad);
            printf("\n\n");
            aux=aux->siguiente;
        }while(aux!=primero);
    }else{
    printf("La agenda se encuentra vacía \n");
    }

}

void buscar(){
    nodo* actual=(nodo*)malloc(sizeof(nodo));
    actual=primero;
    int diabusca=0, encontrado=0,op=0, mesbusca=0;
    printf("La busqueda se realiza por fecha \n Inserta el dia a buscar: ");
    scanf("%d",&diabusca);
    printf("\nIngresa el mes de la fecha: ");
    scanf("%d",&mesbusca);
    if(primero!=NULL){
        do{
            if (actual->infor.dia==diabusca){
                do{
                        if(actual->infor.mes==mesbusca){
                            printf("\n Actividad encontrada!\n \t %d/%d/%d \n", actual->infor.dia,actual->infor.mes,actual->infor.year);
                            printf(" Hora:  %s\n",actual->infor.hora);
                            printf("Lugar: %s\n",actual->infor.lugar);
                            printf("\n Actividad: %s\n\n",actual->infor.actividad);
                            printf("\n");
                            encontrado=1;
                        }
                        actual=actual->siguiente;
                }while(actual!=primero && encontrado!=1);
            }
            actual=actual->siguiente;
        }while(actual!=primero && encontrado!=1);
    if(encontrado==1){
        fflush(stdin);
        int respuesta;
        int op=0;
        do{
        printf("Desea ver la actividad siguiente o la anterior? (1=S/2=N) \n");
        scanf("%d",&respuesta);
        if (respuesta==1){
            printf("Hacia atras (1), Hacia adelante(2)?\n");
            scanf("%d",&op);
            switch(op){
            case 1:
                actual=actual->siguiente;
                printf("\n Actividad encontrada!\n \t %d/%d/%d \n", actual->infor.dia,actual->infor.mes,actual->infor.year);
                printf(" Hora:  %s\n",actual->infor.hora);
                printf("Lugar: %s\n",actual->infor.lugar);
                printf("\n Actividad: %s\n\n",actual->infor.actividad);
                printf("\n");
                break;
            case 2:
                actual=actual->atras;
                printf("\n Actividad encontrada!\n \t %d/%d/%d \n", actual->infor.dia,actual->infor.mes,actual->infor.year);
                printf(" Hora:  %s\n",actual->infor.hora);
                printf("Lugar: %s\n",actual->infor.lugar);
                printf("\n Actividad: %s\n\n",actual->infor.actividad);
                printf("\n");
                break;
            default:
                printf("\nOpcion Invalida\n");
                break;
            }
        }else
        printf("Okey :)\n");
        }while(respuesta!=1);
    }
    if(encontrado==0){
        actual=actual->siguiente;
        printf("Nodo no encontrado\n");
    }
    }else{
    printf("La lista se encuentra vacía\n");
    }

}

void eliminarevento(){
    nodo* actual=(nodo*)malloc(sizeof(nodo));
    actual=primero;
    nodo*anterior=(nodo*)malloc((sizeof(nodo)));
    int diabusca=0, encontrado=0,opcio=0, mesbusca=0;
    printf("La busqueda se realiza por fecha \n Inserta el dia a buscar: ");
    scanf("%d",&diabusca);
    printf("\nIngresa el mes de la fecha: ");
    scanf("%d",&mesbusca);
    if(primero!=NULL){
        do{
            if (actual->infor.dia==diabusca){
                do{
                        if(actual->infor.mes==mesbusca){
                            printf("\n Nodo encontrado (%d)", actual->infor.dia);
                            printf("\n Nodo encontrado (%d)", actual->infor.mes);
                            printf("\n Actividad: %s\n\n",actual->infor.actividad);
                            if (actual==primero){
                                primero=primero->siguiente;
                                primero->atras=ultimo;
                                ultimo->siguiente=primero;
                            }else
                                if(actual==ultimo){
                                    ultimo=anterior;
                                    ultimo->siguiente=primero;
                                    primero->atras=ultimo;
                                }else{
                                    anterior->siguiente=actual->siguiente;
                                    actual->siguiente->atras=anterior;
                                }


                            printf("Actividad eliminada satisfactoriamente");
                            encontrado=1;
                        }
                        anterior=actual;
                        actual=actual->siguiente;
                }while(actual!=primero && encontrado!=1);

            }

                //anterior=actual;
                //actual=actual->siguiente;


        }while(actual!=primero && encontrado!=1);

        if(encontrado==0){
            printf("nodo no encontrado");
        }else{
        free(anterior);
        }


    }else{
    printf("La lista se encuentra vacía\n");
    }

}
/*
void ordenar(){
    nodo* actual=(nodo*)malloc(sizeof(nodo));
    nodo* siguiente=(nodo*)malloc((sizeof(nodo)));
    nodo* tmp =(nodo*)malloc(sizeof(nodo));

    if(primero!=NULL){
        actual=primero;
        do{
            siguiente=actual->siguiente;
            while(siguiente!=primero){
            if(actual->infor.mes > siguiente->infor.mes){
                tmp->infor=siguiente->infor;
                siguiente->infor=actual->infor;
                actual->infor=tmp->infor;
            }
            siguiente=siguiente->siguiente;
            }
            actual=actual->siguiente;
            siguiente=actual->siguiente;

        }while(siguiente!=ultimo);
    }
}*/
