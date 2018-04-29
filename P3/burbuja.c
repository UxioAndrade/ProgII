//
//  burbuja.c
//  P3
//
//  Created by Uxío García Andrade on 17/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#include "burbuja.h"
#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"

void Burbuja(vectorP *v1)
{
    TELEMENTO aux;
    unsigned long e,i;
    int intercambio;
    for (e=0;e<tamanho(*v1) - 1;e++){
        intercambio = 0;
        for (i=0;i<tamanho(*v1) - e - 1;i++){
            if ( recuperar(*v1, i) > recuperar(*v1, i+1))
            {
                aux= recuperar(*v1, i);
                asignar(v1, i, recuperar(*v1, i+1));
                asignar(v1,i + 1, aux);
                intercambio = 1;
            }
        }
        if(intercambio==0) break;
    }
}
