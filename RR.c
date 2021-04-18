#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 1000

int processesNum;
int processesQuantum;
int Processes[MAX];
int ProcessBurstTime[MAX];
int ProcessWaitingTime[MAX];
int ProcessTurnAroundTime[MAX];
int ProcessQuantum[MAX];
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

	findAvgTime(Processes, processesNum, ProcessBurstTime, processesQuantum);

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

	fgets(aux, 255, InputFile);
	processesQuantum = atoi(aux);

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
	// Fazendo Cópias do BurstTime para reter o BurstTime restante.
    // burst times.
    int ProcessRemainingBT[processesNum];
    for (int i = 0 ; i < processesNum ; i++)
        ProcessRemainingBT[i] =  ProcessBurstTime[i];
  
    int currentTime = 0; // Tempo Corrido
  
    // Continua percorrendo os processos em rodízio até que todos eles não sejam concluídos.
	while(1) {
		int done = 1;
		// Percorra todos os processos um por um repetidamente
		for ( i = 0 ; i < processesNum; i++ ) 
        {
            // Se o BurstTime for maior que 0, então apenas deve processar mais
            if (ProcessRemainingBT[i] > 0)
            {
                done = 0; // Há um processo pendente
  
                if (ProcessRemainingBT[i] > processesQuantum)
                {
                    // Aumenta o valor de currentTime
                    // Ou seja, quanto tempo um processo foi processado
                    currentTime += processesQuantum;
  
                    // Diminua o BurstTime do Quantum do processo atual
                    ProcessRemainingBT[i] -= processesQuantum;
                }
  
                // Se o BurstTime for menor ou igual ao Quantum.
                // Último ciclo para este processo
                else
                {
                    // Aumenta o valor de currentTime
                    // Ou seja, quanto tempo um processo foi processado
                    currentTime += ProcessRemainingBT[i];
  
					// O WaitingTime é o currentTime menos o tempo usado por este processo;
                    ProcessWaitingTime[i] = currentTime - ProcessBurstTime[i];
  
                    // À medida que o processo é totalmente executado, 
					// Seu BurstTime restante = 0
                    ProcessRemainingBT[i] = 0;
                }
            }
			total+=ProcessWaitingTime[i];
        }
		avg_wt = (float) total/processesNum;

		total = 0;

		// Se todos os processos estiverem concluído
		if (done == 1)
			break;
	}

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
    findWaitingTime();
    findTurnAroundTime();

    printf("\n\n-- Processos    |    Burst Time\tWaiting Time\tTurnaround Time\n");
    for ( i = 0; i < processesNum; i++) {
        printf("-- Processo[%d]\t|\t%d\t\t%d\t\t%d\n",Processes[i],ProcessBurstTime[i],ProcessWaitingTime[i],ProcessTurnAroundTime[i]);
    }
    printf("\n[Média Waiting Time=%f]",avg_wt);
    printf("\n[Média Turnaround Time=%f]\n",avg_tat);
}
