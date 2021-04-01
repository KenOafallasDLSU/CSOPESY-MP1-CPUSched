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
    int process_id, arrival_time, total_execution_time;
    int process_id_list[], arrival_time_list[], total_execution_time[];

    printf("Enter file name: ");
    scanf("%s", filename);

    strcat(filename, txt);

    FILE* fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("%s not found.", filename);
        return 0;
    }
    
    fscanf(fp, "%d %d %d", algo, nprocesses, tsv)
    
    int i;
    
    if(algo == 1)
    {
            for(i = 0; i < nprocesses; i++)
            {
                 fscanf(fp, "%d %d %d", process_id, arrival_time, total_execution_time);
                 process_id_list[i] = process_id;
                 arrival_time_list[i] = arrival_time;
                 total_execution_time[i] = total_execution_time;
            }
            
            fcfs(nprocesses, process_id_list, arrival_time_list, total_execution_time);
    }

    fclose(fp);
        
    return 0;
}
