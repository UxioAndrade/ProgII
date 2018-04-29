//
//  seleccion.c
//  P3
//
//  Created by Uxío García Andrade on 17/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#include "seleccion.h"
#include <stdlib.h>
#include <stdio.h>
#include "vectordinamico.h"

void Selec(vectorP *v1)
{
    unsigned long e,i, PosMenor;
    TELEMENTO aux;
    for (e=0; e<tamanho(*v1)-1; e++)
    {
        PosMenor=e;
        for (i=e+1;i<tamanho(*v1);i++)
            if (recuperar(*v1, i) < recuperar(*v1, PosMenor))
                PosMenor=i;
        aux=recuperar(*v1, e);
        asignar(v1, e, recuperar(*v1, PosMenor));
        asignar(v1,PosMenor,aux);
    }
}
