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
	int total_wt = 0, total_time_list[nprocesses];
	int start_time = 0, end_time = 0, waiting_time_list[nprocesses], turn_around_list[nprocesses];
	int temp, min, key;
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
	
	total_time_list[0] = arrival_time_list[0] + exec_time_list[0];		
    turn_around_list[0] = total_time_list[0] - arrival_time_list[0];
    waiting_time_list[0] = turn_around_list[0] - exec_time_list[0];
      
    for(i = 1; i < nprocesses; i++)
    {
        temp = total_time_list[i - 1];
        min = exec_time_list[i];
        
        for(j = i; j < nprocesses; j++)
            if(temp >= arrival_time_list[j] && min >= exec_time_list[j])
            {
                min = exec_time_list[j];
                key = j;
            }
        
        total_time_list[key] = temp + exec_time_list[key];
        turn_around_list[key] = total_time_list[key] - arrival_time_list[key];
        waiting_time_list[key] = turn_around_list[key] - exec_time_list[key];
        
		   
        temp = process_id_list[key];
        process_id_list[key] = process_id_list[i];
        process_id_list[i] = temp;
            
        temp = arrival_time_list[key];
        arrival_time_list[key] = arrival_time_list[i];
        arrival_time_list[i] = temp;
        
        temp = exec_time_list[key];
        exec_time_list[key] = exec_time_list[i];
        exec_time_list[i] = temp;
        
        temp = total_time_list[key];
        total_time_list[key] = total_time_list[i];
        total_time_list[i] = temp;
        
        temp = waiting_time_list[key];
        waiting_time_list[key] = waiting_time_list[i];
        waiting_time_list[i] = temp;
        
        temp = turn_around_list[key];
        turn_around_list[key] = turn_around_list[i];
        turn_around_list[i] = temp;
    }
	

    for(i = 0; i < nprocesses; i++)
    {
    	end_time += exec_time_list[i];
    	
    	printf("P[%d]\n", process_id_list[i]);
        printf("Start Time: %d End time: %d\n", start_time, end_time);
        printf("Waiting time: %d\n", waiting_time_list[i]);
        printf("Turnaround time: %d\n", turn_around_list[i]);
        printf("************************************\n");
        
        start_time = end_time;
	}
    
    for(i = 0; i < nprocesses; i++)
    	total_wt += waiting_time_list[i];
    
	awt = (float) total_wt / nprocesses;
	    
    printf("Average waiting time: %.1f", awt);
}
