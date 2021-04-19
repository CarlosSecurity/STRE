*** ROUND ROBIN ***

	Cada processo é atribuído a a um tempo fixo (Time Quantum / Time Slice) de forma cíclica.
	Ele é projetado especialmente para o sistema de compartilhamento de tempo (time sharing system).
	A fila pronta (aptos) é tratada como uma fila circular. O escalonador da CPU percorre a fila 
	pronta, alocando CPU para cada processo por um intervalo de tempo de até 1 quantum. Para
	implementar o escalonamento Round Robin, mantemos a fila pronta (aptos) como uma fila circular 
	FIFO de processos. Novos processos são adicionados ao final da fila pronta.
	O escalonador da CPU escolhe o primeiro processo da fila pronta, define um cronômetro para interromper após o Quantum de 1 tempo e despacha o processo.

	Uma de duas coisas podem ocorrer. O processo pode ter surto(Burst / Intermintência - que para e
	depois volta) de CPU de menos de um quantum . Nesse caso, o próprio processo liberará a CPU
	voluntariamente. O escalonador irá então prosseguir para o próximo processo na fila de espera 4(aptos). Por outro lado, se o burst de CPU do processo em execução for maior do que o quantum de
	1 tempo, o cronômetro será desativado e causará um interrupção no sistema operacional. Uma troca
	de contexto será executada e o processo será colocado no final da lista de espera (aptos). O 
	escalonador da CPU selecionará o próximo processo na fila de espera.

** Instruções para compilar o código e rodar o programa **

* Para compilar o código, execute o comando em seu terminal, já com o compilador C instalado:
	```shell
	$gcc rr.c -o <output-name>
	```

* Com o código compilado, devemos configurar as propriedades de nossos processos para o algoritmo de escalonamento à partir do arquivo 'input', já disposto no repositório.

* O arquivo 'input' segue a seguinte sequência para determinar os valores das propriedades.
	* Na primeira linha definimos o número de processos;
	* Para as próximas três linhas definimos na sequência, a capacidade, deadline e período do processo. 
		- Ex:\
			3   // número de processos\
			2	// quantum
			10	// BurstTime do primeiro processo\
			5	// BurstTime do segundo processo\
			8	// BurstTime do terceiro processo\

			OBS: O arquivo 'input' já está parametrizado com está configuração


* Após compilar o código, execute ele passando o arquivo 'input' como argumento. 
```shell
$./<output-name> input
```

* Com a execução concluída, todo atividade foi impressa no terminal e um arquivo 'output' foi gerado com o registro da atividade.




