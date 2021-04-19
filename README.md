# STRE
Repositório de para o projeto de 'Sistemas em Tempo Real e Embarcados'

# DETALHES:
  - Para compilação do código foi utilizado o compilador gcc, com o padrão -std=c18
    (Caso a compilação seja efetuada com outro padrão, os programas ficam passíveis
    de falha na memória - Segmentation Fault)
    
    
    * Descrição das variáveis comuns:
    Arrival Time: Tempo que leva para o processo chega à fila de espera.
    Completion Time: Momento em que o processo conclui sua execução.
    Burst Time: Tempo necessário para um processo de execução da CPU.
    Turn Around Time: Diferença de tempo entre a hora de conclusão e a hora de chegada.
    Turn Around Time = Completion Time – Arrival Time
    Waiting Time(W.T): Diferença de tempo entre o tempo de rotação e o tempo de burst.
    Waiting Time = Turn Around Time – Burst Time

# Componentes do grupo
  
  - Carlos Leonardo Machado Lago 21709338 - carlos.leonardo@sempreceub.com
  - Tiago Braga Camargo Dias 21805183 - tiago.dias@sempreceub.com
  - Beatriz Helena dos Santos 21805492 - beatriz.helena@sempreceub.com
