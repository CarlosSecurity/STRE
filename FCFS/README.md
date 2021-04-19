*** FIRST COME FIRST SERVED ***

	Algoritmo de escalonamento mais simples que programa de acordo com os tempos de chegada (arrivel time) dos processos. O algoritmo de FCFS afirma que o processo que solicita a CPU primeiro é
	alocado à CPU primeiro

	O FCFS é implementado usando uma fila FIFO. Quando um processo entra na fila de prontidão (aptos),
	seu PCB (Process Control Block) é vinculado ao final da fila. Quando a CPU está livre, ele é 
	alocado no topo da fila. O processo de execução é então removido da fila.

	FCFS é um algoritmo não-preemptivo.

	- Nota: O FCFS pode sofrer do efeito comboio


** Instruções para compilar o código e rodar o programa **

* Para compilar o código, execute o comando em seu terminal, já com o compilador C instalado:
	```shell
	$gcc fcfs.c -o <output-name> -std=c18
	```

	OBS: definimos com o '-std=c18', qual padrão da linguagem estamos utilizando, no nosso caso, 
	o padrão da linguagem C de 2018 está sendo utilizada.

	

* Com o código compilado, devemos configurar as propriedades de nossos processos para o algoritmo de escalonamento à partir do arquivo 'input', já disposto no repositório.

* O arquivo 'input' segue a seguinte sequência para determinar os valores das propriedades.
	* Na primeira linha definimos o número de processos;
	* Para as próximas três linhas definimos na sequência, a capacidade, deadline e período do processo. 
		- Ex:\
			3 	// número de processos\
			3 	// bursttime do primeiro processo\
			10 	// bursttime do segundo processo\
			8 	// bursttime do terceiro processo\

			OBS: O arquivo 'input' já está parametrizado com está configuração


* Após compilar o código, execute ele passando o arquivo 'input' como argumento. 
```shell
$./<output-name> input
```

* Com a execução concluída, todo atividade foi impressa no terminal e um arquivo 'output' foi gerado com o registro da atividade.




