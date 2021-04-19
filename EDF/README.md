*** EARLIEST DEADLINE FIRST ***

	O Earliest DeadLine First (EDF) ou "menor tempo à percorrer" é um algoritmo de escalonamento
	de prioridade dinâmica usado em sistemas operacionais em tempo real para colocar processos em
	uma fila de prioridade. 
	
	Sempre que ocorrer um evento de escalonamento	(tarefa concluída, nova tarefa liberada, etc.),
	a fila pesquisa o processo mais próximo de seu DeadLine. Este processo é o próximo a ser agendado
	para execução.

	EDF é um algoritmo de escalonamento ideal em uniprocessadores preemptivos,no seguinte sentido:
		- Se uma conjunto de tarefas independentes (PCBs), cada uma caracterizada por um tempo de 
		  chegada, uma request da execução e um DeadLine, pode ser programado (por qualquer algoritmo)
		  de uma forma que garanta que todas as tarefas sejam concluídas dentro do prazo (DeadLine),
		  a EDF irá agendar este conjunto de tarefas para que todas sejam executadas dentro do prazo.


** Instruções para compilar o código e rodar o programa **

* Para compilar o código, execute o comando em seu terminal, já com o compilador C instalado:
	```shell
	$gcc edf.c -o <output-name> -std=c18
	```

	OBS: definimos com o '-std=c18', qual padrão da linguagem estamos utilizando, no nosso caso, 
	o padrão da linguagem C de 2018 está sendo utilizada.

* Com o código compilado, devemos configurar as propriedades de nossos processos para o algoritmo de escalonamento à partir do arquivo 'input', já disposto no repositório.

* O arquivo 'input' segue a seguinte sequência para determinar os valores das propriedades.
	* Na primeira linha definimos o número de processos;
	* Para as próximas três linhas definimos na sequência, a capacidade, deadline e período do processo. 
		- Ex:\
			3 	// número de processos\
			3 	// capacidade do primeiro processo\
			7 	// deadline do primeiro processo\
			20 	// períodos do primeiro processo\
			2 	// capacidade do primeiro processo\
			4 	// deadline do primeiro processo\
			5 	// períodos do primeiro processo\
			2 	// capacidade do primeiro processo\
			8 	// deadline do primeiro processo\
			10 	// períodos do primeiro processo

			OBS: O arquivo 'input' já está parametrizado com está configuração


* Após compilar o código, execute ele passando o arquivo 'input' como argumento. 
```shell
$./<output-name> input
```

* Com a execução concluída, todo atividade foi impressa no terminal e um arquivo 'output' foi gerado com o registro da atividade.




