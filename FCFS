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
	// Abrindo o arquivo;
	FILE *InputFile;
	InputFile = fopen("input", "r");

	// Número de process
	fgets(aux, 255, InputFile);
	processesNum = atoi(aux);

	// Recebendo os process do arquivo input.txt;
	for ( i = 0; i < processesNum; i++)
	{
		// Burst Time
		fgets(aux, 255, InputFile);
		ProcessBurstTime[i]= atoi(aux);
	}
	fclose(InputFile);
	printf("----------------------------------------------\n");
	printf("First Come Fisrt Served\n");
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n");
    printf("Configuration Processes\n");
	printf("Processos    | ArrivelTime | BurstTime\n");
	printf("----------------------------------------------\n");
	for ( i=0; i < processesNum ; i++)
	{
		Processes[i]=i+1; 
		printf("Processo[%d] |     %d\n" ,i+1 ,ProcessBurstTime[i]);
	}
}

void findWaitingTime()
{ 
    // Waiting Time do primeiro processo deve ser 0.
    ProcessWaitingTime[0] = 0; 
    
    // Calculando o WaintingTime 
    for (int  i = 1; i < processesNum ; i++ ) 
        ProcessWaitingTime[i] =  ProcessBurstTime[i-1] + ProcessWaitingTime[i-1] ;

	avg_wt = (float) total/processesNum;      

    total = 0; 
}

void findTurnAroundTime() 
{ 
    // Calculando o TurnAround Time (Tempo de Resposta)
    // BurstTime + WaitingTime
    for (int  i = 0; i < processesNum ; i++) 
        ProcessTurnAroundTime[i] = ProcessBurstTime[i] + ProcessWaitingTime[i];

	avg_tat = (float) total/processesNum;
} 

void findAvgTime() 
{     
    findWaitingTime(); 
    findTurnAroundTime(); 
    
    printf("\n\n-- Processos    |    Burst Time\tWaiting Time\tTurnaround Time\n");

    for ( i = 0; i < processesNum; i++) {
        printf("-- Processo[%d]\t|\t%d\t\t%d\t\t%d\n",Processes[i],ProcessBurstTime[i],ProcessWaitingTime[i],ProcessTurnAroundTime[i]);
    }
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
