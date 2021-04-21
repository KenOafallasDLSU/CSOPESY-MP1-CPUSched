/***********************************************
Names:  TAN, Darren
        OAFALLAS, Kenneth Neil
Group: 16
Section: S15
***********************************************/
int checkAllDone(int nProcesses, struct Process aProcesses[])
{
        int bAllDone = 1;

		int i;
        for(i=0; i<nProcesses; i++)
                if(aProcesses[i].remainingTime != 0)
                        bAllDone = 0;

        return bAllDone;
}

int checkNewArrival(int loc, int systemTime, int nProcesses, struct Process aProcesses[])
{
        int found = -1;

        int ctr = loc;
        while(found <= -1 && ctr < nProcesses)
        {
                if(aProcesses[ctr].arrivalTime == systemTime)
                        found = ctr;
                ctr++;
        }

        return found;
}

int getShortestRemaining(int nArrivedCnt, int aArrived[], struct Process aProcesses[])
{
		if(nArrivedCnt == 0) return -1;
		
        int shortest = aArrived[0];
		int i;
        for(i=0; i<nArrivedCnt; i++)
        {
                if(aProcesses[shortest].remainingTime == 0)
                        shortest = aArrived[i];
                else if(aProcesses[aArrived[i]].remainingTime != 0 && 
                        aProcesses[aArrived[i]].remainingTime < aProcesses[shortest].remainingTime)
                        shortest = aArrived[i];
                //printf("shortTime: %d\n", aProcesses[aArrived[i]].remainingTime);
        }

		if(aProcesses[shortest].remainingTime == 0) return -1;
        return shortest;
}

void updateActiveProcess(struct Process *process)
{
        process->remainingTime--;
}

void printProcessReport(struct Process *process)
{
		int i;
		
		printf("P[%d]\n", process->processID);
		for(i=0; i<process->runCnt; i++)
			printf("Start time: %d End time: %d\n", *(process->aStart+i), *(process->aEnd+i));
        printf("Waiting time: %d\n", process->waitingTime);
        printf("Turnaround time: %d\n", process->turnaroundTime);
        printf("************************************\n");
}

void updateWaitingProcess(struct Process *process)
{
        process->waitingTime++;
        process->turnaroundTime++;
}

float getAvgWaitingTime(int nProcesses, struct Process aProcesses[])
{
	float sum = 0;
	
	int i;
	for(i=0; i<nProcesses; i++)
		sum += aProcesses[i].waitingTime;
	
	return sum/nProcesses;
}

void psjf(int nProcesses, struct Process aProcesses[])
{		
        int systemTime = 0;
        int aArrived[nProcesses];
        int nArrivedCnt = 0;
        int newProcess;
        int newShortest = -1;
        int shortest = -1;

        float awt;

        while(checkAllDone(nProcesses, aProcesses) == 0)
        {
                //check new arrivals
                int loc = 0;
                do{
                	newProcess = checkNewArrival(loc, systemTime, nProcesses, aProcesses);
	                if(newProcess >= 0)
	                {
	                        aArrived[nArrivedCnt] = newProcess;
	                        nArrivedCnt++; 
	                }
	                //printf("Arrived %d\n", newProcess);
	                loc = newProcess+1;
				} while(newProcess != -1);
                
                //preempt
                newShortest = getShortestRemaining(nArrivedCnt, aArrived, aProcesses);
                //printf("%d\n", newShortest);
                if (shortest < 0 && newShortest >= 0)
                {
                	shortest = newShortest;
                	aProcesses[shortest].aStart[aProcesses[shortest].runCnt] = systemTime;
                	aProcesses[shortest].runCnt++;
				}
				else if(shortest != newShortest)
                {
                        aProcesses[shortest].aEnd[aProcesses[shortest].runCnt-1] = systemTime;
                        shortest = newShortest;
                        if(aProcesses[shortest].runCnt >= 1)
                        {
                        	aProcesses[shortest].aStart = realloc(aProcesses[shortest].aStart, aProcesses[shortest].runCnt+1);
                        	aProcesses[shortest].aEnd = realloc(aProcesses[shortest].aEnd, aProcesses[shortest].runCnt+1);
						}
                        aProcesses[shortest].aStart[aProcesses[shortest].runCnt] = systemTime;
                        aProcesses[shortest].runCnt++;
                } 

                //update processs
                int i;
                for(i=0; i< nArrivedCnt; i++)
                {
                		if(aProcesses[aArrived[i]].remainingTime != 0)
                		{
                        		if(aArrived[i] == shortest)
                            			updateActiveProcess(&aProcesses[shortest]);
                        		else
                            	    	updateWaitingProcess(&aProcesses[aArrived[i]]);
                        }
                }

                //update system
                systemTime++;
                
                //print report
                if(shortest == -1) continue;
        		if(aProcesses[shortest].remainingTime == 0)
        		{
        				aProcesses[shortest].aEnd[aProcesses[shortest].runCnt-1] = systemTime;
        				printProcessReport(&aProcesses[shortest]);
        				shortest = -1;
        		}
        }
        
        awt = getAvgWaitingTime(nProcesses, aProcesses);
        printf("Average Waiting Time: %.1f", awt);
}
