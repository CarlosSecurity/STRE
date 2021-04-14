*** EARLIEST DEADLINE FIRST ***

	O Earliest DeadLine First (EDF) ou "menor tempo à percorrer" é um algoritmo de escalonamento de prioridade dinâmica usado em sistemas operacionais em tempo real para colocar processos em uma fila de prioridade. 
	
	Sempre que ocorrer um evento de agendamento	(tarefa concluída, nova tarefa liberada, etc.), a fila pesquisa o processo mais próximo de seu DeadLine. Este processo é o próximo a ser agendado para execução.

	EDF é um algoritmo de escalonamento ideal em uniprocessadores preemptivos,no seguinte sentido: se uma conjunto de tarefas independentes, cada uma caracterizada
	por um tempo de chegada, um requisito de execução e um DeadLine, pode ser programado (por qualquer algoritmo) de uma forma que garanta que todas as tarefas sejam
	concluídas dentro do prazo (DeadLine),a EDF irá agendar esta conjunto de tarefas para que todas sejam executadas dentro do prazo.
