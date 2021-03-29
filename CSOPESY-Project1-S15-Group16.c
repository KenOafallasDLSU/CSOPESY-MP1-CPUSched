/***********************************************
Names:  TAN, Darren
        OAFALLAS, Kenneth Neil
Group: 16
Section: S15
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/process.h"
#include "headers/queue.h"

#include "headers/fcfs.h"
#include "headers/nsjf.h"
#include "headers/psjf.h"
#include "headers/rr.h"

int 
main(void) 
{
    char filename[50], txt[] = ".txt";
    int algo, nprocesses, tsv;

    printf("Enter file name: ");
    scanf("%s", filename);

    strcat(filename, txt);

    FILE* fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("%s not found.", filename);
        return 0;
    }

    while(fscanf(fp, "%d %d %d", algo, nprocesses, tsv) == 1)
    {
            
    }

    fclose(fp);
        
    return 0;
}
