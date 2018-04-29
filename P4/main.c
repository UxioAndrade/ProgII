//
//  main.c
//  P4
//
//  Created by Uxío García Andrade on 19/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#include <stdio.h>
#include "enterosLargos.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

void intAEnteroLargo(int64_t num,int *arr,enteroLargo *n){
    
    unsigned long aux=0;
    short sig = 0;
    
    if(num>0) sig = 1;
    else sig = -1;
    
    aux = (int)log10((double)num) + 1;
    arr = (int *)malloc(aux*sizeof(int));
   
    for(unsigned long i = 0; i < aux; i++){
        *(arr + i) = num % 10;
        num /= 10;
    }
    
    creaEnteroLargo(n, aux, sig);
    
    for(unsigned long i=0;i<aux;i++){
        asignarCifras(n, i, *(arr + i));
    }
}


int main(int argc, const char * argv[]) {
   
    
    int opt=1;
    enteroLargo n1=NULL,n2=NULL,resul=NULL;
    int64_t p1=0,p2=0;
    int *num1=NULL,*num2=NULL;
    
    while(opt != 0){
        printf("-------------------------------------------------------\n");
        printf("--------Multiplicación Karatsuba-Ofman-----------------\n");
        printf("-----Seleccione la opción que desee llevar a cabo-----------\n");
        printf("-------[1] Divide y Vencerás -----------------\n");
        printf("-------[2] Karatsuba-Ofman ----------------\n");
        printf("-------[0] Salir ----------------\n");
        scanf("%d",&opt);
        
        switch (opt) {
                
            case 1:
                
                if(argc > 1){
                    /*for(int i=0; i < 3; i++){
                        argv[i];
                    }*/
                }else{
                   printf("Introduzca el primer factor \n");
                    scanf("%lld",&p1);
                    intAEnteroLargo(p1, num1, &n1);
                    
                    printf("Introduzca el segundo factor \n");
                    scanf("%lld",&p2);
                    intAEnteroLargo(p2, num2, &n2);
                }
                carry(&n1);
                carry(&n2);
                creaEnteroLargo(&resul, tamanhoEntero(n1)*2, signoEntero(n1)*signoEntero(n2));
                
                divYVence(&n1, &n2, &resul);
                carry(&resul);
                imprimeEntero(resul);
                
                liberarEntero(&n1);
                liberarEntero(&n2);
                liberarEntero(&resul);
                break;
            case 2:
                
                if(argc > 1){
                    
                }else{
                    printf("Introduzca el primer factor \n");
                    scanf("%lld",&p1);
                    intAEnteroLargo(p1, num1, &n1);
                    
                    printf("Introduzca el segundo factor \n");
                    scanf("%lld",&p2);
                    intAEnteroLargo(p2, num2, &n2);

                carry(&n1);
                carry(&n2);
                creaEnteroLargo(&resul, tamanhoEntero(n1)*2, signoEntero(n1)*signoEntero(n2));
        
                Karatsuba(&n1, &n2, &resul);
                carry(&resul);
                imprimeEntero(resul);
                    
                liberarEntero(&n1);
                liberarEntero(&n2);
                liberarEntero(&resul);
                }
                break;
            case 0:
                printf("Tenga un buen día \n");
                break;
            default:
                printf("La opción seleccionada es incorrecta \n");
                break;
                
        }
    }
}
