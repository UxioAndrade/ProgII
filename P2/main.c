//
//  main.c
//  P2
//
//  Created by Uxío García Andrade on 3/3/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "listas.h"

#define PLUS 0.5


void imprimirPuntos(){
    printf("|---------------------------------------|\n");
}

void liberaColaEspera(TCOLA *c){
     if(*c != NULL){
         while(!EsColaVacia(*c)) destruye(*c);
         free(*c);
         *c = NULL;
     }
 }


 void liberaListaPluses(TLISTA *l){
     if(*l!=NULL){
         destruye(l);
     }
     *l=NULL;
 }
 

void imprimirCola(TCOLA c){
    TIPOELEMENTOCOLA elemento=0;
    PrimeroCola(c, &elemento);
    printf("El siguiente cliente tiene %d productos\n",elemento);
}

void imprimirListaPluses(TLISTA l){
    TNODOLISTA plus=NULL;
    TIPOELEMENTOLISTA elemento=0;
    plus=primero(l);
    
    printf("Lista de pluses:\n");
    
    for (int i=0; i<longitud(l);i++){
        recupera(l, plus, &elemento);
        printf("[%d] %f\n",i+1,elemento);
        plus = siguiente(l, plus);
    }
    imprimirPuntos();
}

int comprobacionNumeroProductos(TIPOELEMENTOCOLA n){
    if(n>0){
        return 1;
    }else{
        return 0;
    }
}

int comprobacionValorARecaudar(TIPOELEMENTOLISTA v){
    if(v>0){
        return 1;
    }else{
        return 0;
    }
}

TIPOELEMENTOLISTA totalPluses(TLISTA l){
    TNODOLISTA plus=NULL;
    TIPOELEMENTOLISTA total=0;
    TIPOELEMENTOLISTA aux=0;
    if(esVacia(l))return 0;
    else{
        plus=primero(l);
        for(int i = 0;i<longitud(l);i++){
            recupera(l, plus, &aux);
            total += aux;
            plus=siguiente(l, plus);
        }
        return total;
    }
}

void recaudarPluses(TLISTA *listaPluses,TIPOELEMENTOLISTA dineroARecaudar){
    
    TNODOLISTA plus=NULL,maxPlus=NULL;
    TIPOELEMENTOLISTA plusActual=0,max=0;
    
    while(dineroARecaudar){
        plus=primero(*listaPluses);
        maxPlus=primero(*listaPluses);
        recupera(*listaPluses, maxPlus, &max);
        
        for(int i=1;i<longitud(*listaPluses);i++){
            plus=siguiente(*listaPluses, plus);
            recupera(*listaPluses, plus, &plusActual);
            if(plusActual>max){
                max=plusActual;
                maxPlus=plus;
            }
        }
        if(dineroARecaudar-max>0){
            dineroARecaudar -= max;
            suprime(listaPluses, maxPlus);
        }else{
            modifica(listaPluses,maxPlus,max-dineroARecaudar);
            dineroARecaudar = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    short option=1;
    char confirm[1]="a";
    
    TIPOELEMENTOCOLA n=0;
    TIPOELEMENTOLISTA plusesACobrar=0;
    TLISTA listaPluses=NULL;
    TCOLA colaEspera=NULL;
    TNODOLISTA posicionLista=NULL;
    
    
    ColaVacia(&colaEspera);
    crea(&listaPluses);
    posicionLista=primero(listaPluses);
    
    
    
    while(option != 0){
        
        imprimirPuntos();
        printf("Seleccione la acción que desee realizar:\n");
        printf("[1] Anotarse a la cola\n");
        printf("[2] Atender cliente\n");
        printf("[3] Cobrar pluses\n");
        printf("[4] Calcular pluses\n");
        printf("[0] Salir\n");
        scanf("%hd",&option);
        
        switch(option){
            case 1:
                imprimirPuntos();
                if(argc > 1){
                    AnadirCola(colaEspera, argc-1);
                }else{
                    printf("Introduzca el numero de elementos que lleve\n");
                    scanf("%d",&n);
                    if(comprobacionNumeroProductos(n)){
                        AnadirCola(&colaEspera,n);
                    }else{
                        printf("El numero de productos introducido es invalido\n");
                    }
                }
                break;
            case 2:
                imprimirPuntos();
                printf("Cliente atendido\n");
                PrimeroCola(colaEspera, &n);
                EliminarCola(&colaEspera);
                if(!EsColaVacia(colaEspera))imprimirCola(colaEspera);
                if(comprobacionNumeroProductos(n))inserta(&listaPluses,posicionLista, n*PLUS);
                imprimirListaPluses(listaPluses);
                n=0;
                break;
            case 3:
                imprimirPuntos();
                printf("Introduzca el valor de pluses a retirar\n");
                scanf("%f",&plusesACobrar);
                if(comprobacionValorARecaudar(plusesACobrar)){
                    if(plusesACobrar<=totalPluses(listaPluses)){
                        recaudarPluses(&listaPluses, plusesACobrar);
                        imprimirListaPluses(listaPluses);
                    }
                }
                break;
            case 4:
                imprimirPuntos();
                printf("Los pluses acumulados hasta el momento son:\n");
                printf("%f",totalPluses(listaPluses));
                break;
            case 0:
                printf("Está seguro que desea salir del programa?\n");
                printf("y/n\n");
                fflush(stdin);
                scanf("%s",confirm);
                if(confirm[0] == 'y'){
                    printf("Tenga un buen día\n");
                    liberaListaPluses(&listaPluses);
                    liberaColaEspera(&colaEspera);
                } else{
                    option = 1;
                }
                break;
            default:
                printf("El carácter introducido es incorrecto\n");
        }
    }
    //en comprobacionValorARecaudar no se puede saber si el saldo es suficiente, eso lo hace otra funcion
    //para el meiquefail meterle main.c ./TAD/lista.c
    //modificamos la línea donde se compila
    //modificar la línea gcc -Wall -c $.
    return 0;
}
