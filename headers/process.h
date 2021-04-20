/***********************************************
Names:  TAN, Darren
        OAFALLAS, Kenneth Neil
Group: 16
Section: S15
***********************************************/
struct Process
{
        int processID;
        int arrivalTime;
        int executionTime;
        int remainingTime;
        int waitingTime;
        int turnaroundTime;
        int *aStart;
        int runCnt;
        int *aEnd;
};
