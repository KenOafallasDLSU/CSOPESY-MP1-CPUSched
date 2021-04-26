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
#include "headers/helpers.h"
#include "headers/fcfs.h"
#include "headers/nsjf.h"
#include "headers/psjf.h"
#include "headers/rr.h"

#define MAX 100

int 
main(void) 
{
    char filename[50], txt[] = ".txt";
    int algo, nprocesses, tsv;
    int process_id, arrival_time, exec_time;
    int process_id_list[MAX], arrival_time_list[MAX], exec_time_list[MAX];
    int readCount;

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
    
    readCount = fscanf(fp, "%d %d %d", &algo, &nprocesses, &tsv);
    if(readCount < 3)
    {
    	printf("ERROR: Invalid first line\n");
        return 0;
	}
    if(nprocesses < 1)
    {
        printf("No processes\n");
        return 0;
    }
    
    if(algo == 0)
    {
    	int i;
    	
        for(i = 0; i < nprocesses; i++)
        {
            readCount = fscanf(fp, "%d %d %d", &process_id, &arrival_time, &exec_time);
            if(readCount < 3)
            {
            	printf("ERROR: Invalid process line\n");
        		return 0;
			}
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
    	    readCount = fscanf(fp, "%d %d %d", &process_id, &arrival_time, &exec_time);
    	    if(readCount < 3)
            {
            	printf("ERROR: Invalid process line\n");
        		return 0;
			}
            process_id_list[i] = process_id;
            arrival_time_list[i] = arrival_time;
            exec_time_list[i] = exec_time;
	}
		
	nsjf(nprocesses, process_id_list, arrival_time_list, exec_time_list);
     }
    else if(algo == 2)
    {
        struct Process aProcesses[nprocesses];
        int i;
        for(i=0; i < nprocesses; i++)
        {
            readCount = fscanf(fp, "%d %d %d", &aProcesses[i].processID, &aProcesses[i].arrivalTime, &aProcesses[i].executionTime);
            if(readCount < 3)
            {
            	printf("ERROR: Invalid process line\n");
        		return 0;
			}
            aProcesses[i].waitingTime = 0;
            aProcesses[i].remainingTime = aProcesses[i].executionTime;
            aProcesses[i].turnaroundTime = aProcesses[i].executionTime;
            aProcesses[i].runCnt = 0;
            aProcesses[i].aStart = (int*) malloc(sizeof(int));
            aProcesses[i].aEnd = (int*) malloc(sizeof(int));
            
        }
        
        psjf(nprocesses, aProcesses);
        printGantt(nprocesses, aProcesses);
        
        //dealloc
        for(i=0; i < nprocesses; i++)
        {
        	free(aProcesses[i].aStart);
        	free(aProcesses[i].aEnd);
		}
    }
    else if(algo == 3) //Round Robin
    {
        struct Process aProcesses[nprocesses];
        int i;
        for(i=0; i < nprocesses; i++)
        {
            readCount = fscanf(fp, "%d %d %d", &aProcesses[i].processID, &aProcesses[i].arrivalTime, &aProcesses[i].executionTime);
            if(readCount < 3)
            {
            	printf("ERROR: Invalid process line\n");
        		return 0;
			}
            aProcesses[i].waitingTime = 0;
            aProcesses[i].remainingTime = aProcesses[i].executionTime;
            aProcesses[i].turnaroundTime = aProcesses[i].executionTime;
            aProcesses[i].runCnt = 0;
            aProcesses[i].aStart = (int*) malloc(sizeof(int));
            aProcesses[i].aEnd = (int*) malloc(sizeof(int));
        }

        rr(tsv, nprocesses, aProcesses);
        printGantt(nprocesses, aProcesses);
        
        //dealloc
        for(i=0; i < nprocesses; i++)
        {
        	free(aProcesses[i].aStart);
        	free(aProcesses[i].aEnd);
		}
    }

    fclose(fp);
        
    return 0;
}
