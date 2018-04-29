//
//  vectordinamico.h
//  P3
//
//  Created by Uxío García Andrade on 17/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#ifndef vectordinamico_h
#define vectordinamico_h

#include <stdio.h>

/*Tipo de datos de los elementos del vector*/
typedef unsigned long TELEMENTO;
/*tipo opaco, los detalles de implementación están ocultos al usuario*/
typedef void * vectorP;
/*Función crear: asigna memoria y devuelve la asignación al vector. Recibe v1 por referencia para devolver al programa principal la dirección de memoria reservada por este procedimiento*/
void crear(vectorP *v1,unsigned long tam1);
/*Función asignar: Llena una posición del vector con un valor. Recibe una copia de la dirección de memoria reservada para el vector v1*/
void asignar(vectorP *v1,unsigned long posicion, TELEMENTO valor);
/*Función liberar: Libera la memoria asignada a un vector v1. Recibe una copia de la dirección de memoria reservada para el vector v1*/
void liberar(vectorP *v1);
/*Función recuperar: . Recibe una copia del vector v1 y de la posición*/
TELEMENTO recuperar(vectorP v1,unsigned long posicion);
/*Función tamanho: Devuelve el tamanho del vector. Recibe una copia del vector*/
unsigned long tamanho(vectorP v1);
/*Función inicializar: Crea un vector con elementos aleatorios*/
void inicializaVectorRand(vectorP *v1);
/*Función swap: Cambia dos elementos de posición dentro de un vector*/
void swap(vectorP *pvector,unsigned long m,unsigned long n);

#endif /* vectordinamico_h */
