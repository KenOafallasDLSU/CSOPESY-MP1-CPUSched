/***********************************************
Names:  TAN, Darren
        OAFALLAS, Kenneth Neil
Group: 16
Section: S15
***********************************************/

#include <stdio.h>

void
nsjf(int nprocesses, int process_id_list[], int arrival_time_list[], int exec_time_list[])
{
	int total_ta = 0, total_wt = 0;
	int start_time[nprocesses], end_time[nprocesses], waiting_time_list[nprocesses], turn_around_list[nprocesses];
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
	
    for(i = 1; i < nprocesses; i++)
    	for(j = 1; j < nprocesses; j++)
    		if(exec_time_list[i] < exec_time_list[j])
    		{
    			temp = process_id_list[i];
				process_id_list[i] = process_id_list[j];
				process_id_list[j] = temp;
    			
    			temp = arrival_time_list[i];
                arrival_time_list[i] = arrival_time_list[j];
                arrival_time_list[j] = temp;
                
                temp = exec_time_list[i];
                exec_time_list[i] = exec_time_list[j];
                exec_time_list[j] = temp;
			}
	    
    for(i = 0; i < nprocesses; i++)
    {
    	if(i == 0)
            start_time[i] = arrival_time_list[i];
        else
            start_time[i] = end_time[i - 1];
            
        waiting_time_list[i] = start_time[i] - arrival_time_list[i];
        end_time[i] = start_time[i] + exec_time_list[i];
        turn_around_list[i] = end_time[i] - arrival_time_list[i];
        total_wt += waiting_time_list[i];
        total_ta += turn_around_list[i];
	}
    
    for(i = 0; i < nprocesses; i++)
    {
    	printf("P[%d]\n", process_id_list[i]);
        printf("Start Time: %d End time: %d\n", start_time[i], end_time[i]);
        printf("Waiting time: %d\n", waiting_time_list[i]);
        printf("Turnaround time: %d\n", turn_around_list[i]);
        printf("************************************\n");
	}
    
	awt = total_wt / nprocesses;
	    
    printf("Average waiting time: %.1f", awt);
}
