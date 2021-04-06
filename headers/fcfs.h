/***********************************************
Names:  TAN, Darren
        OAFALLAS, Kenneth Neil
Group: 16
Section: S15
***********************************************/

#include <stdio.h>

void
fcfs(int nprocesses, int process_id_list[], int arrival_time_list[], int exec_time_list[])
{
	int total_exec_time = 0, total_wt = 0, start_time = 0;
	float awt;
        
    int i;
        
    for(i = 0; i < nprocesses; i++)
    {
    	total_exec_time += exec_time_list[i];
    	
        printf("P[%d]\n", process_id_list[i]);
        printf("Start Time: %d End time: %d\n", start_time, total_exec_time);
        printf("Waiting time: %d\n", start_time);
        printf("Turnaround time: %d\n", total_exec_time);
        printf("************************************\n");
        
        total_wt += start_time;
        start_time = total_exec_time;
    }
    
	awt = total_wt / nprocesses;
	    
    printf("Average waiting time: %.1f", awt);
}
