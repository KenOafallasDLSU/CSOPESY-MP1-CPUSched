/***********************************************
Names:  TAN, Darren
        OAFALLAS, Kenneth Neil
Group: 16
Section: S15
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "headers/process.h"
//#include "headers/queue.h"
#include "headers/fcfs.h"
#include "headers/nsjf.h"
//#include "headers/psjf.h"
//#include "headers/rr.h"

#define MAX 100

int 
main(void) 
{
    char filename[50], txt[] = ".txt";
    int algo, nprocesses, tsv;
    int process_id, arrival_time, exec_time;
    int process_id_list[MAX], arrival_time_list[MAX], exec_time_list[MAX];

    printf("Enter file name: ");
    scanf("%s", filename);
	printf("\n");
	
    strcat(filename, txt);

    FILE* fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("%s not found.", filename);
        return 0;
    }
    
    fscanf(fp, "%d %d %d", &algo, &nprocesses, &tsv);
    
    if(algo == 0)
    {
    	int i;
    	
        for(i = 0; i < nprocesses; i++)
        {
            fscanf(fp, "%d %d %d", &process_id, &arrival_time, &exec_time);
            process_id_list[i] = process_id;
            arrival_time_list[i] = arrival_time;
            exec_time_list[i] = exec_time;
        }
            
        fcfs(nprocesses, process_id_list, arrival_time_list, exec_time_list);
    }
    else if(algo == 1)
    {
    	int i;
    	
    	for(i = 0; i < nprocesses; i++)
    	{
    	    fscanf(fp, "%d %d %d", &process_id, &arrival_time, &exec_time);
            process_id_list[i] = process_id;
            arrival_time_list[i] = arrival_time;
            exec_time_list[i] = exec_time;
	}
		
	nsjf(nprocesses, process_id_list, arrival_time_list, exec_time_list);
     }

    fclose(fp);
        
    return 0;
}
