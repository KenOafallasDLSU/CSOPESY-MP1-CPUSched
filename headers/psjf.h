/***********************************************
Names:  TAN, Darren
        OAFALLAS, Kenneth Neil
Group: 16
Section: S15
***********************************************/
#include <stdio.h>

int checkAllDone(int nProcesses, struct Process aProcesses[])
{
        int bAllDone = 1;

        for(int i=0; i<nProcesses; i++)
                if(aProcesses[i]->remainingTime != 0)
                        int bAllDone = 0;

        return bAllDone;
}

int checkNewArrival(int systemTime, int nProcesses, struct Process aProcesses[])
{
        int found = -1;

        int ctr = 0;
        while(found <= -1 && ctr < nProcesses)
        {
                if(aProcesses[ctr]->arrivalTime == systemTime)
                        found = ctr;
                ctr++;
        }

        return found;
}



void psjf(int nProcesses, struct Process aProcesses[])
{
        int systemTime = 0;
        int aArrived[nProcesses];
        int nArrivedCnt = 0;
        float awt;

        struct Process *active;

        while(checkAllDone(nProcesses, aProcesses) == 0)
        {
                //check new arrivals
                int new = checkNewArrival(systemTime, nProcesses, aProcesses)
                if(new >= 0)
                {
                        aArrived[nArrivedCnt] = new;
                        nArrivedCnt++; 
                }

                //preempt

                //update processs

                //update system
                systemTime++;
        }
}