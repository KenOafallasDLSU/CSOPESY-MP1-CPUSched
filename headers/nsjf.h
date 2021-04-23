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
	int total_wt = 0;
	int start_time = 0, end_time = 0, waiting_time, turn_around;
	int temp, count, end;
	float awt;
    
    int i, j;
	
	for(i = 0; i < nprocesses - 1; i++)
        for(j = i + 1; j < nprocesses; j++)           
            if(arrival_time_list[i] > arrival_time_list[j])
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
    
    end = 0;
	                    
    while(end < nprocesses)
    {
        count = 0;
        
        for(i = end; i < nprocesses; i++)
        {
            if(arrival_time_list[i] <= end_time)
                count++;
            else
                break;
        }
        
        if(count > 1)
            for(i = end; i < end + count - 1; i++)
                for(j = i + 1; j < end + count; j++)
                    if(exec_time_list[i] > exec_time_list[j])
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
                                  
        
        start_time = end_time;
        end_time += exec_time_list[end];
        turn_around = end_time - arrival_time_list[end];
    	waiting_time = turn_around - exec_time_list[end];
        
        if(arrival_time_list[end] - 1 != arrival_time_list[end - 1] && !(arrival_time_list[end] == arrival_time_list[end - 1]))
    	{
    		start_time = arrival_time_list[end];
    		end_time = arrival_time_list[end] + exec_time_list[end];
    		turn_around = end_time - arrival_time_list[end];
    		waiting_time = turn_around - exec_time_list[end];
		}
        
        printf("P[%d]\n", process_id_list[end]);
        printf("Start Time: %d End time: %d\n", start_time, end_time);
        printf("Waiting time: %d\n", waiting_time);
        printf("Turnaround time: %d\n", turn_around);
        printf("************************************\n");
        
        total_wt += end_time - arrival_time_list[end] - exec_time_list[end];
        end++;
    }
   
	awt = (float) total_wt / nprocesses;
	    
    printf("Average waiting time: %.1f", awt);
}
