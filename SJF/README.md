*** SHORTEST JOB FIRST ***

	Os processo que tem o menor tempode Burst são escalonados primeiro. Se dois tem o mesmo tempo
	de busrt, O FCFS é usado para desempatar. É um algoritmo de escalonamento não-preemptivo, apesar
	de ter uma outra versão do SJF que é preemptiva.

** Instruções para compilar o código e rodar o programa **

* Para compilar o código, execute o comando em seu terminal, já com o compilador C instalado:
	```shell
	$gcc sjf.c -o <output-name> -std=c18
	```

	OBS: definimos com o '-std=c18', qual padrão da linguagem estamos utilizando, no nosso caso, 
	o padrão da linguagem C de 2018 está sendo utilizada.

* Com o código compilado, devemos configurar as propriedades de nossos processos para o algoritmo de escalonamento à partir do arquivo 'input', já disposto no repositório.

* O arquivo 'input' segue a seguinte sequência para determinar os valores das propriedades.
	* Na primeira linha definimos o número de processos;
	* Para as próximas três linhas definimos na sequência, a capacidade, deadline e período do processo. 
		- Ex:\
			4 	// número de processos\
			6 	// BurstTime do primeiro processo\
			8 	// BurstTime do segundo processo\
			7 	// BurstTime do terceiro processo\
			3 	// BurstTime do quarto processo\



			OBS: O arquivo 'input' já está parametrizado com está configuração


* Após compilar o código, execute ele passando o arquivo 'input' como argumento. 
```shell
$./<output-name> input
```


* Com a execução concluída, todo atividade foi impressa no terminal e um arquivo 'output' foi gerado com o registro da atividade.




