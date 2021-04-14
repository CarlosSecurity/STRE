#define MAX_DESC_PROC   20

// estrutura do bloco descritor do processo
struct desc_Proc{
    // declarando o registro - struct
    char estado_atual;
    int prioridade;
    unsigned inicio_memoria;
    unsigned tamanho_memoria;
    struct arquivo
        arq_abertos[20];
    unsigned tempo_de_cpu;

    // registradores
    unsigned proc_pc;   // Program Counter - Apontador de instruções
    unsigned proc_sp;   // Stack Pointer - Apontador de pilha
    unsigned proc_acc;  // Accumulator - Acumulador
    unsigned proc_rx;   // Register Index - Registrador indexador

    // Ponteiro que aponta para o próximo descritor de processos
    struct desc_Proc * proximo;
}

// apontadores e listas
struct desc_Proc tab_desc[MAX_DESC_PROC];  // Tabela de estruturas, tamanho 20;
struct desc_Proc * desc_livre;  // Aponta para a lista de descritores livres;
struct desc_Proc * espera_cpu;  // Lista de processos aguardando para utilizar a CPU;
struct desc_Proc * usando_cpu;  // Aponta para o processo que está utilizando a CPU;
struct desc_Proc * bloqueados;  // Aponta para o processo que está bloqueado a espera de um evento;

/*  
    Criando uma tabela de blocos descritores de processos
    para deixar o sistema preparado para receber processos,
    já que processos podem criar outros processos.
*/
// encadeamento e inicialização
for ( int i = 0; i < MAX_DESC_PROC; i++) {
    tab_desc[i].proximo = &tab_desc[i+1];
}
tab_desc[i].proximo = NULL;
desc_livre = &tab_desc[0];

espera_cpu = NULL;
usando_cpu = NULL;
