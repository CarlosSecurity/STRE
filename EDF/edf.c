#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Protótipos de função
void getProcessos();
void getPeriodosLCM();
float capacidadeParaAgendar();
void agendamento();

int processosNum;
int ProcessosExecutionTime[1000];
int ProcessosDeadline[1000];
int ProcessosPeriodo[1000];
int PeriodosLCM;

char aux[255];
int i,j,h;
float f;

int main()
{
	setlocale(LC_ALL, "pt-BR"); // Habilita a acentuação para o português;

	printf("Earliest Deadline First \n");
	
	printf("\nSistema:\n");
	getProcessos();
	
	
	
	printf("\n\nPeriodos LCM :\n");
	getPeriodosLCM();
	
	
	
	printf("\n\nTeste da Capacidade para ser Schedulado:\n");
	f = capacidadeParaAgendar();
	if(f <= 1)
	{
		printf("\n Pode ser Schedulado: ( %f <= 1 )", f);
		agendamento();
	}
	else
	{
		printf("\nNao pode ser Schedulado ( %f > 1 )",f);
		FILE *OutputFile;
		OutputFile = fopen("output.txt", "w");
		fprintf(OutputFile, "Nao pode ser Schedulado ( %f > 1 )",f);
		fclose(OutputFile);
		exit(0);
	}

	return 0;
}


void getProcessos()
{
	// Abrindo o arquivo;
	FILE *InputFile;
	InputFile = fopen("input", "r");
	fgets(aux, 255, InputFile);
	processosNum = atoi(aux);
	// Recebendo os processos do arquivo input.txt;
	for ( i = 0; i < processosNum; i++)
	{
		fgets(aux, 255, InputFile);
		ProcessosExecutionTime[i]= atoi(aux);
		
		fgets(aux, 255, InputFile);
		ProcessosDeadline[i]= atoi(aux);
		
		fgets(aux, 255, InputFile);
		ProcessosPeriodo[i]= atoi(aux);
	}
	fclose(InputFile);
	// Mostrando os Processos;
	printf("----------------------------------------------\n");
	printf("Processo    | Capacidade | DeadLine | Periodos\n");
	printf("----------------------------------------------\n");
	for ( i=0; i < processosNum ; i++)
	{
	printf("Processo[%d] |    %d       |    %d     |    %d\n",i,ProcessosExecutionTime[i], ProcessosDeadline[i], ProcessosPeriodo[i]);
	}
	
	
}
void getPeriodosLCM()
{
	int aux[1000];
	for ( i=0 ; i < processosNum ; i++)
	{
		aux[i] = ProcessosPeriodo[i];
	}
	int h = 0;
	int menorValorAux;
	int menorValorIndice;
	while(h == 0)
	{
		h = 1;
		menorValorAux = aux[0];
		menorValorIndice = 0;
		
		for ( i=0 ; i < processosNum; i++)
		{
			if ( menorValorAux != aux[i] )
			{
				h = 0;
				if(menorValorAux>aux[i])
				{
					menorValorAux = aux[i];
					menorValorIndice = i;
					
				}
				
			}	
		}
		if(h == 0)
		{
			aux[menorValorIndice] = menorValorAux + ProcessosPeriodo[menorValorIndice];
		}	
	}
	PeriodosLCM = aux[0];
	printf("Podemos agendar o Sistemas em %d unidades ( [Periodos do Processos] LCM:%d)",PeriodosLCM,PeriodosLCM);
	
}

float capacidadeParaAgendar()
{
	float cond = 0;
	float x,y;
	printf("\n A soma :");
	for(i=0 ; i < processosNum ; i++)
	{
		x = ProcessosExecutionTime[i];
		y = ProcessosPeriodo[i];
		cond = cond + (x/y);
		printf(" (%d/%d) ",ProcessosExecutionTime[i],ProcessosPeriodo[i]);
	}
	printf(">> %f", cond);
	return cond;
}

void agendamento()
{
	int primeiroDeadline;
	int primeiroDeadlineIndice;
	int TabelaAgendamento[PeriodosLCM];
	int capacidadeRestante[1000];
	int proxDeadline[1000];
	int processoNovoPeriodo[1000];
	for( i=0 ; i < processosNum ; i++ )
	{
		proxDeadline[i] = ProcessosDeadline[i];
		capacidadeRestante[i] = ProcessosExecutionTime[i];
		processoNovoPeriodo[i] = 0;
	}
	// Tempo de Agendamento | Histórico
	FILE *OutputFile;
	OutputFile = fopen("outputc", "w");
	fprintf(OutputFile, "Periodos LCM = %d\n",PeriodosLCM);
	for(i=0; i<PeriodosLCM; i++)
	{
		printf("\n(%d,%d) : ",i,i+1);
			
			//Pegar o primeiro DeadLine
			primeiroDeadline = PeriodosLCM;
			primeiroDeadlineIndice = -1;
			for(j=0 ; j<processosNum ; j++)
			{
				 if(capacidadeRestante[j] > 0)
				 {
				 	
				 	if(primeiroDeadline > proxDeadline[j])
				 	{
				 		
				 		primeiroDeadline = proxDeadline[j];
				 		primeiroDeadlineIndice = j;
					 }
				 }
			}
			printf("     [exc = %d] ",primeiroDeadlineIndice);
			fprintf(OutputFile, "(%d,%d) :   [exc = %d]\n",i,i+1,primeiroDeadlineIndice);
			capacidadeRestante[primeiroDeadlineIndice]--;
			
			//Pegar a distância do próximo DeadLine	
			for(j=0 ; j<processosNum ; j++)
			{
				
				 if(processoNovoPeriodo[j] == (ProcessosPeriodo[j] - 1 ) )
				 {
				 	proxDeadline[j] =  ProcessosDeadline[j];
				 	capacidadeRestante[j] = ProcessosExecutionTime[j];
				 	processoNovoPeriodo[j] = 0;
				 }
				 else
				 {
				 	if(proxDeadline[j] >0)
				 	{
				 		proxDeadline[j]--;
					 }
					 else
					 {
					 	if(capacidadeRestante[j] > 0)
					 	{
					 		printf("\nO processo %d nao tem chance de completar sua Capacidade",j);
					 		fprintf(OutputFile, "\n O processo %d não tem chance de completar sua Capacidade",j);
						 }
					 }
				 	 processoNovoPeriodo[j]++; 
				 }
				 
				 
			}
	}
	fclose(OutputFile);


}

