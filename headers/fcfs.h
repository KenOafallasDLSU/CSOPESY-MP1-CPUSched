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
	int total_wt = 0, start_time = 0, end_time = 0, turn_around;
	int temp;
	float awt;
        
    int i, j;
    
	for(i = 0; i < nprocesses - 1; i++)
		for(j = 0; j < nprocesses - i - 1; j++)
			if(arrival_time_list[j] > arrival_time_list[j + 1])
			{
				temp = process_id_list[j];
				process_id_list[j] = process_id_list[j + 1];
				process_id_list[j + 1] = temp;
				
				temp = arrival_time_list[j];
				arrival_time_list[j] = arrival_time_list[j + 1];
				arrival_time_list[j + 1] = temp;
				
				temp = exec_time_list[j];
				exec_time_list[j] = exec_time_list[j + 1];
				exec_time_list[j + 1] = temp;
			}
	
    for(i = 0; i < nprocesses; i++)
    {
    	end_time += exec_time_list[i];
    	turn_around = start_time + exec_time_list[i];
    	
        printf("P[%d]\n", process_id_list[i]);
        printf("Start Time: %d End time: %d\n", start_time, end_time);
        printf("Waiting time: %d\n", start_time);
        printf("Turnaround time: %d\n", turn_around);
        printf("************************************\n");
        
        total_wt += start_time;
        start_time = end_time;
    }
    
	awt = (float) total_wt / nprocesses;
	    
    printf("Average waiting time: %.1f", awt);
}
