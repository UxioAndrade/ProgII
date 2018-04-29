//
//  vectordinamico.c
//  P3
//
//  Created by Uxío García Andrade on 17/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef short TELEMENTO;
/* Se vuelve a definir el tipo de datos que con ene el vector*/

typedef struct {
    TELEMENTO *datos;
    unsigned long tam;
    /*valores del vector*/
    /*tamaño del vector*/
    /*definición de la estructura*/
    /*signo*/
}STVECTOR;

typedef STVECTOR *vectorP;  /*puntero a estructura*/

/*Función crear: asigna memoria y devuelve la asignación al vector*/
void crear(vectorP *v1,unsigned long tam1)
{
    short i=0;
    
    *v1=(vectorP)malloc(sizeof(STVECTOR));
    
    if (!*v1){
        printf("Fatal error. Memory couldn't be allocated");
        exit(0);
    }
    
    (*v1)->datos=(TELEMENTO*)malloc(tam1*sizeof(TELEMENTO));
    if (!(*v1)->datos){
        printf("Fatal error. Memory couldn't be allocated");
        exit(0);
    }
    
    (*v1)->tam=tam1;
    
    if((*v1)->tam <= 0 || (*v1)->tam > tam1) printf("Error, el tamanho no puede ser de la dimension indicada");
    
    for(i=0; i < tam1; i++)
        *((*v1)->datos+i) = 0; /*Inicialización a 0 de las componentes del vector*/
}

/*Función asignar: Asigna un valor a una posición del vector */
void asignar(vectorP *v1,unsigned long posicion, TELEMENTO valor)
{
    if(*v1 != NULL && (*v1)->datos != NULL && posicion<(*v1)->tam)
        *((*v1)->datos+posicion)=valor;
}

/*Función liberar: Libera la memoria asignada a un vector*/

void liberar(vectorP *v1){
    if (*v1 != NULL && (*v1)->datos != NULL){
        free((*v1)->datos);
        free(*v1);
        *v1 = NULL;
    } else{
        printf("El vector no ha sido creado");
    }
}

TELEMENTO recuperar(vectorP v1,unsigned long posicion){
    TELEMENTO elemento=0;
    if (v1 != NULL && v1->datos != NULL){
        if (posicion > (v1)->tam){
            printf("La posicion indicada no existe");
            return 0;
        } else{
            elemento = *(v1->datos + posicion);
            return elemento;
        }
    }else{
        printf("Fatal error");
        return 0;
    }
}

unsigned long tamanho(vectorP v1){
    if (v1 != NULL){
        return v1->tam;
    }else{
        printf("No se ha creado ningún vector");
        return 0;
    }
}

void inicializaVectorRand(vectorP *v1){
    
    unsigned long k=-1;
    
    srand(time(NULL));
    
    for(k=0;k<(*v1)->tam;k++)
        asignar(v1, k, rand());
}

void swap(vectorP *pvector,unsigned long m,unsigned long n){
    TELEMENTO temp;
    
    temp = recuperar(*pvector,m);
    asignar(pvector, m, recuperar(*pvector, n));
    asignar(pvector, n, temp);
    
}

