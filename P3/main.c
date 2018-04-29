//
//  main.c
//  P3
//
//  Created by Uxío García Andrade on 17/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectordinamico.h"
#include "quicksort.h"
#include "seleccion.h"
#include "burbuja.h"

int main(int argc, const char * argv[]) {
    
    unsigned long n=0, f = 0, paso = 0;
    clock_t inicio = -1, fin = -1;
    int opt = 0;
    vectorP v=NULL;
    
    FILE *fp=NULL;
    
    if(argc > 1){
        n = atoll(argv[1]);
        f = atoll(argv[2]);
        paso = atoll(argv[3]);
        opt = atoi(argv[4]);
    } else {
        printf("N \n");
        scanf("%lu",&n);
        printf("F \n");
        scanf("%lu",&f);
        printf("Paso \n");
        scanf("%lu",&paso);
        printf("Opcion");
        scanf("%d",&opt);
    }
    
    
    
    switch (opt){
        case 1 :
            fp=fopen("tiemposBurbuja.txt","w");
            if (!fp) exit(0);
            for(unsigned long i=n; i<f ; i += paso){
                crear(&v,i);
                inicializaVectorRand(&v);
                inicio = clock();
                Burbuja(&v);
                fin = clock();
                printf("n:%u\tf(n):%u\tini.:%u\tfin:%d\ttiempo:%.4lf\n", i, f, fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
                fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
                liberar(&v);
            }
            fclose(fp);
            break;
        case 2:
            fp=fopen("tiempposQuicksort.txt","w");
            if (!fp) exit(0);
            for(unsigned long i= n; i< f; i += paso){
                crear(&v, i);
                inicializaVectorRand(&v);
                inicio = clock();
                quicksort(&v, 0, i);
                fin = clock();
                printf("n:%u\tf(n):%u\tini.:%u\tfin:%d\ttiempo:%.4lf\n", i, f, fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
                fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
                liberar(&v);
            }
            fclose(fp);
            break;
            
        case 3:
            fp = fopen("tiemposSeleccion.txt","w");
            if(!fp) exit(0);
            for(unsigned long i = n; i<f; i += paso){
                crear(&v,i);
                inicializaVectorRand(&v);
                inicio = clock();
                Selec(&v);
                fin = clock();
                printf("n:%u\tf(n):%u\tini.:%u\tfin:%d\ttiempo:%.4lf\n", i, i, fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
                fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
                liberar(&v);
            }
            fclose(fp);
            break;
    }
    return 0;
}
