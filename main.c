#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargo(Pila *dada);
void acomodo(Pila *aux, Pila *aux2);
void pase (Pila *dada, Pila *aux);
void menor (Pila*dada,Pila *aux,Pila *aux2);
void ordsel(Pila *dada, Pila *aux3);
void insernum(Pila *dada, int *i);
void ordins(Pila *dada);
int sumatops(Pila *dada);
int sumaval(Pila *dada);
int elemnts(Pila *dada);
int divide(Pila pilita);
int promele(Pila dada);
void numerar(Pila *dada);
void carga(Pila *dada);
void verpila(Pila *dada);


int main()
{

    int num;
    num=0;
    Pila pilita, aux, aux2;
    inicpila(&pilita);
    inicpila(&aux);
    inicpila(&aux2);
    char yes;

    do
    {
        printf("Bienvenido a la guia 3: funciones, elija el numero  del ejercicio que desea realizar: ");
        scanf("%i", &num);
        switch(num)
        {
        case 1:
            cargo(&pilita);
            mostrar(&pilita);
            break;

        case 2:
            cargo(&pilita);
            printf("La pila A esta asi:  ");
            mostrar(&pilita);
            pase(&pilita, &aux);
            printf("La pila A paso a la pila B asi:  ");
            mostrar(&aux);
            break;

        case 3:
            cargo(&pilita);
            printf("La pila A esta asi:  ");
            mostrar(&pilita);
            pase(&pilita, &aux);
            acomodo(&aux, &aux2);
            printf("La pila B esta asi:  ");
            mostrar(&aux2);
            break;

        case 4:
            cargo(&pilita);
            printf("La pila A esta asi:  ");
            mostrar(&pilita);
            menor(&pilita, &aux, &aux2);
            printf("La pila A quedo asi:  ");
            mostrar(&pilita);
            break;

        case 5:
            cargo(&pilita);
            printf("La pila esta cargada de esta manera");
            mostrar(&pilita);
            ordsel(&pilita, &aux);
            printf("Pila ordenada por seleccion");
            mostrar(&aux);
            break;

        case 6:
            cargo(&pilita);
            printf("PILA ORIGINAL");
            mostrar(&pilita);
            do
            {
                printf("Elija el numero que desea insertar: ");
                scanf("%i", &num);
                insernum(&pilita, &num);
                printf("PILA INSERTADA");
                mostrar(&pilita);
                printf("Desea agregar otro elemento a la pila? presione 's' para si:");
                fflush(stdin);
                scanf("%c", &yes);
            }
            while(yes=='s'|| yes== 'S');
            break;

        case 7:
            do
            {
                printf("para insertar un numero por favor ");
                leer(&pilita);
                ordins(&pilita);
                printf("para agregar un elemento mas a la pila, presione 's'\n");
                fflush(stdin);
                scanf("%c", &yes);
            }
            while(yes=='s'|| yes=='S');
            printf("La pila quedo se la siguiente manera:");
            mostrar(&pilita);
            break;

        case 8:
            cargo(&pilita);
            num = sumatops(&pilita);
            printf("\n\nPILITA");
            mostrar(&pilita);
            printf("La suma del tope y su anterior de la pila es: %i\n\n", num);
            break;

        case 9:
            cargo(&pilita);
            mostrar(&pilita);
            num=promele(pilita);
            printf("\n\nEl promedio de las notas es aproximadamente de: %i\n\n", num);
            break;

        case 10:
            cargo(&pilita);
            mostrar(&pilita);
            numerar(&pilita);
            break;

        case 11:
            do
            {
                carga(&pilita);
                printf("para agregar un elemento mas a la pila, presione 's'\n");
                fflush(stdin);
                scanf("%c", &yes);
            }
            while(yes=='s'|| yes=='S');
            mostrar(&pilita);
            break;

        case 12:
            cargo(&pilita);
            verpila(&pilita);
            mostrar(&pilita);
            break;

        default:
            printf("\nEjercicio inexistente!!\n\n");
            break;
        }

        while(!pilavacia(&pilita))
        {
            desapilar(&pilita);
        }
        while(!pilavacia(&aux))
        {
            desapilar(&aux);
        }
        while(!pilavacia(&aux2))
        {
            desapilar(&aux2);
        }
        printf("Desea realizar otro ejercicio? presione 's' para si: ");
        fflush(stdin);
        scanf("%c",&yes);
    }
    while(yes=='s'|| yes== 'S');

    printf("\n\nHASTA LA PROXIMA!!!\n\n");

    return 0;
}

void cargo(Pila *dada)
{
    char yes;
    do
    {
        leer(dada);
        printf("para agregar un elemento mas a la pila, presione 's'\n");
        fflush(stdin);
        scanf("%c", &yes);
    }
    while(yes=='s'|| yes=='S');
}

void pase (Pila *dada, Pila *aux)
{
    while(!pilavacia(dada))
    {
        apilar(aux, desapilar(dada));
    }
}

void acomodo(Pila *aux, Pila *aux2)
{
    while(!pilavacia(aux))
    {
        apilar(aux2, desapilar(aux));
    }
}

void menor (Pila *dada,Pila *aux, Pila *aux2)
{
    if(!pilavacia(dada))
    {
        apilar(aux, desapilar(dada));
    }

    while(!pilavacia(dada))
    {
        if(tope(dada)<tope(aux))
        {
            apilar(aux2, desapilar(aux));
            apilar(aux, desapilar(dada));
        }
        else
        {
            apilar(aux2, desapilar(dada));
        }
    }
    while(!pilavacia(aux2))
    {
        apilar(dada, desapilar(aux2));
    }

    desapilar(aux);

}

void ordsel(Pila *dada, Pila *aux3)
{
    Pila aux,aux2;
    inicpila(&aux);
    inicpila(&aux2);
    while (!pilavacia(dada))
    {
        apilar(&aux2, desapilar(dada));

        while(!pilavacia(dada))
        {
            if(tope(&aux2)>tope(dada))
            {
                apilar(&aux, desapilar(&aux2));
                apilar(&aux2, desapilar(dada));
            }
            else
            {
                apilar(&aux, desapilar(dada));
            }
        }

        while(!pilavacia(&aux))
        {
            apilar(dada, desapilar(&aux));
        }

        apilar(aux3, desapilar(&aux2));
    }

}

void insernum(Pila *dada, int *i)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    apilar(&aux, *i);
    mostrar(&aux);

    while(!pilavacia(dada) && tope(dada)>tope(&aux))
    {
        apilar(&aux2, desapilar(dada));
    }

    apilar(dada, desapilar(&aux));

    while(!pilavacia(&aux2))
    {
        apilar(dada, desapilar(&aux2));
    }
}

void ordins(Pila *dada)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    apilar(&aux, desapilar(dada));
    while(!pilavacia(dada) && tope(dada)>tope(&aux))
    {
        apilar(&aux2, desapilar(dada));
    }

    apilar(dada, desapilar(&aux));

    while(!pilavacia(&aux2))
    {

        apilar(dada, desapilar(&aux2));
    }
}

int sumatops(Pila *dada)
{
    int suma;
    suma=0;
    Pila aux;
    inicpila(&aux);
    apilar(&aux, desapilar(dada));
    suma= tope(dada) + tope(&aux);
    apilar(dada, desapilar(&aux));
    return suma;
}

int sumaval(Pila *dada)
{
    int num1;
    num1=0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(dada))
    {
        num1 = tope(dada) + num1;
        apilar(&aux, desapilar(dada));
    }
    while(!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
    return num1;
}

int elemnts(Pila *dada)
{
    int num1;
    num1=0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(dada))
    {
        num1++;
        apilar(&aux, desapilar(dada));
    }
    while(!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
    return num1;
}

int divide(Pila pilita)
{
    int num, num2, total;
    num = 0;
    num2 = 0;
    num = sumaval(&pilita);
    num2 = elemnts(&pilita);

    total = num/num2;
    return total;
}

int promele(Pila dada)
{
    int promedio;
    promedio = divide(dada);
    return promedio;
}

void numerar(Pila *dada)
{
    Pila aux;
    inicpila(&aux);

    printf("Pila hecha decimal: ");

    while(!pilavacia(dada))
    {
        printf("%i", tope(dada));
        apilar(&aux, desapilar(dada));
    }
    printf("\n\n");
    while(!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
}

void carga(Pila *dada)
{
    int a;
    printf("ingrese el numero que quiera cargar a la pila: ");
    scanf("%i", &a);
    apilar(dada, a);
}

void verpila(Pila *dada)
{
    Pila a;
    inicpila(&a);
    printf("...TOPE...\n");
    while(!pilavacia(dada))
    {
        printf("    (%i)\n", tope(dada));
        apilar(&a, desapilar(dada));
    }
    printf("...BASE...\n\n");

    while(!pilavacia(&a))
    {
        apilar(dada, desapilar(&a));
    }
}

