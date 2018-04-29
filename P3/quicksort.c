//
//  quicksort.c
//  P3
//
//  Created by Uxío García Andrade on 17/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#include "quicksort.h"
#include "vectordinamico.h"

unsigned long choose_pivot(unsigned long i,unsigned long j){
    return ((i+j)/2);
}

void quicksort(vectorP *pvector, unsigned long beg, unsigned long end){
    if(end >beg + 1){
        TELEMENTO piv = recuperar(*pvector, beg);
        unsigned long l= beg + 1, r = end;
        while (l < r){
            if(recuperar(*pvector, l) <= piv)
                l++;
            else{
                r--;
                swap(pvector,l,r);
            }
        }
        l--;
        swap(pvector,l,beg);
        quicksort(pvector, beg, l);
        quicksort(pvector, r, end);
    }
}
