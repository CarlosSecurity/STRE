#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 1000

int processesNum;
int Processes[MAX];
int ProcessBurstTime[MAX];
int ProcessWaitingTime[MAX];
int ProcessTurnAroundTime[MAX];
int total = 0;

float avg_wt, avg_tat;

char aux[255];
int i,j;

void getProcesses();
void orderBT();
void findWaitingTime();
void findTurnAroundTime();
void findAvgTime();

int main() {
	int temp;
	
    getProcesses();

    findAvgTime(Processes, processesNum, ProcessBurstTime);

    return 0;
}

void getProcesses()
{

	FILE *InputFile;
	InputFile = fopen("input", "r");


	fgets(aux, 255, InputFile);
	processesNum = atoi(aux);


	for ( i = 0; i < processesNum; i++)
	{		

		fgets(aux, 255, InputFile);
		ProcessBurstTime[i]= atoi(aux);
	}
	fclose(InputFile);

    printf("----------------------------------------------\n");
	printf("Shortest Job First\n");
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n");
    printf("Configuration Processes\n");
	printf("Processos    | BurstTime\n");
	printf("----------------------------------------------\n");
	for ( i=0; i < processesNum ; i++)
	{
        Processes[i]=i+1; 
	    printf("Processo[%d] |     %d\n" ,i+1 ,ProcessBurstTime[i]);
	}
}

void orderBT() 
{
    int position, temp;
    for ( i = 0; i < processesNum; i++ ) {
        position = i;
        for ( j = i+1; j < processesNum; j++ ){
            if ( ProcessBurstTime[j] < ProcessBurstTime[position])
                position=j;
        }

        temp = ProcessBurstTime[i];
        ProcessBurstTime[i] = ProcessBurstTime[position];
        ProcessBurstTime[position] = temp;

        temp = Processes[i];
        Processes[i] = Processes[position];
        Processes[position] = temp;
    }

}

void findWaitingTime()
{
    ProcessWaitingTime[0]=0;            
  
   
    for(i=1;i<processesNum;i++)
    {
        ProcessWaitingTime[i]=0;
        for(j=0;j<i;j++)
            ProcessWaitingTime[i]+=ProcessBurstTime[j];
  
        total+=ProcessWaitingTime[i];
    }
  
    avg_wt = (float) total/processesNum;      

    total = 0;
}

void findTurnAroundTime()
{
    ProcessTurnAroundTime[0] = 0;

    for ( i = 0; i<processesNum; i++) {
        ProcessTurnAroundTime[i] = ProcessBurstTime[i] + ProcessWaitingTime[i];
        total+=ProcessTurnAroundTime[i];
    }

    avg_tat = (float) total/processesNum;
}

void findAvgTime()
{
    orderBT();
    findWaitingTime();
    findTurnAroundTime();

    printf("\n\n-- Processos    |    Burst Time\tWaiting Time\tTurnaround Time\n");
    for ( i = 0; i < processesNum; i++) {
        printf("-- Processo[%d]\t|\t%d\t\t%d\t\t%d\n",Processes[i],ProcessBurstTime[i],ProcessWaitingTime[i],ProcessTurnAroundTime[i]);
    }
    printf("\n\n[Média Waiting Time=%f]",avg_wt);
    printf("\n[Média Turnaround Time=%f]\n",avg_tat);
}
