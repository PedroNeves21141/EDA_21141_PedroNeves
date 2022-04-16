/**
 * @file header.h
 * @author Pedro Neves (a21141@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region Struct 

/**
 * @brief 
 * Responsavel pela estrutura do projeto
 * Estrutura de verdadeiro(1) ou falso(0)
 *  
 */

typedef enum bool
{
    false = 0,
    true = 1
}bool;

/**
 * @brief Estrutura para armazenar um processo
 * 
 * Um processo contêm um id e contêm um apontador para o próximo processo
 */

typedef struct Processo
{
    int id;
    struct Processo* next;
}Processo;

/**
 * @brief Estrutura para armazenar um operação
 * 
 * Uma operação contêm um id, o id do processo, a posição e um apontador para a próxima operação
 */

typedef struct Operation
{
    int id;
    struct Operation* next;
}Operation;


/**
 * @brief Estrutura para armazenar a execução de uma operação
 * 
 * Uma execução de uma operação contêm o id da operação(operationID),o id da maquina(maquinaID),a unidade de tempo(usageTime) e contêm um apontador
 *  para a próxima execução de uma operação
 */

typedef struct OperationExecution
{
    int operationID;
    int machineID;
    int usageTime; //unidades de tempo necessaria para a realização da operação
    struct OperationExecution* next;
}OperationExecution;

/**
 * @brief Estrutura de uma maquina
 * 
 * Uma maquina contêm um id, um booliano(isActive) e contêm um apontador para a proxima maquina
 */

typedef struct Maquina
{
    int id;
    bool isActive; // se a maquina esta ou nao em utilização
    struct Maquina* next;
}Maquina;
#pragma endregion

#pragma region Metodos

//Inserir novo Processo
Processo* novoProcesso(int id);
//Inserir um processo no Inicio
Processo* inserirProcessoNoInicio(Processo* head, Processo* ProcessoDeInicio);
//Escrever para o ficheiro processos
bool escreverProcessos(char fileName[], Processo* head);
//Ler ficheiro de processos
Processo* lerProcessos(char fileName[]);
//Mostrar ficheiro de processos
bool mostrarProcessos(Processo* head);
//Atualizar um processo
Processo* atualizarProcesso(Processo* head, Processo* ProcessoParaAtualizar, int id);
//Eliminar um processo
bool eliminarProcesso(Processo** head, int id);
//Procurar um processo
bool procurarProcesso(Processo* head,int id);
//Apagar processos na memoria
bool apagarProcessos(Processo* head);


//Inserir nova Maquina
Maquina* novaMaquina(int id,bool isActive);
//Inserir uma maquina no Inicio
Maquina* inserirMaquinaNoInicio(Maquina* head,Maquina* machineDeInicio);
//Escrever para o ficheiro de Maquinas
bool escreverMaquinas(char fileName[],Maquina* head);
//Ler o ficheiro de Maquinas
Maquina* lerMaquinas(char fileName[]);
//Mostrar ficheiro de Maquinas
bool mostrarMaquinas(Maquina* head);
//Procurar uma maquina
bool procurarMaquina(Maquina* head,int id);
//Apagar maquinas na memoria
bool apagarMaquinas(Maquina* head);


//Inserir uma operação
Operation* novoOperation(int id);
//Inserir uma operação no Inicio
Operation* inserirOperationNoInicio(Operation* head,Operation* operationDeInicio);
//Atualizar uma operação
bool atualizarOperation(Operation** head, Operation** operationParaAtualizar, int id);
//Eliminar uma operação
bool eliminarOperation(Operation** head,int id);
//Escrever para o ficheiro de Operações
bool escreverOperations(char fileName[],Operation* head);
//Ler o ficheiro de Operações
Operation* lerOperations(char fileName[]);
//Mostrar o ficheiro de Operações
bool mostrarOperations(Operation* head);
//Procurar uma operação
bool procurarOperationporID(Operation* head, int id);
//Apagar operações na memoria
bool apagarOperations(Operation* head);


//Inserir nova execução de uma operação
OperationExecution* novoOperationExecution(int operationID,int machineID,int usageTime);
//Inserir uma execução de uma operação no Inicio
OperationExecution* inserirOperationExecutionNoInicio(OperationExecution* head,OperationExecution* operationExecutionDeInicio);
//Eliminar uma execução de uma operação
bool eliminarOperationExecution(OperationExecution** head,int operationID);
//Escrever para o ficheiro das execuções das operações
bool escreverOperationExecution(char fileName[],OperationExecution* head);
//Ler o ficheiro das execuções das operações
OperationExecution* lerOperationsExecution(char fileName[]);
//Mostrar o ficheiro das execuções das operações
bool mostrarOperationExecution(OperationExecution* head);
//Procurar uma execução de uma operação
OperationExecution* procurarOperationExecution(OperationExecution** head,int operationID,int machineID);
//Apagar execuções das operações na memoria
bool apagarOperationExecution(OperationExecution* head);
//Atualizar Operation Execution
bool atualizarOperationExecution(OperationExecution** head, OperationExecution* operationParaAtualizar,int usageTime);
//Procurar uma operação 
OperationExecution* procurarOperationExecutionOp(OperationExecution** head,int operationID);
//Ordenar por ordem crescente
OperationExecution* OrdenarExecucaoPorOrdem(OperationExecution* head);

//Lista o numero total de processos
int getListCount(Processo* head);
//Carrega os dados das listas
void loadData(Processo** processos,Maquina** maquinas,Operation** operations,OperationExecution** operationsExecutions);
//Calcular o maior tempo
int maxOperationExecution(Operation* operations, OperationExecution* executions, OperationExecution** minexecutions);
//Calcular o menor tempo
int minOperationExecution(Operation* operations, OperationExecution* executions, OperationExecution** minexecutions);
//Calcular a media do tempo
int avgOperationExecution(OperationExecution* head,int operationID);
//Calcular o caminho mais curto para completar um job
int TempoMinimoDaOperacao(OperationExecution* head);
//Calcular o caminho mais longo para completar um job
int TempoMaximoDaOperacao(OperationExecution* head);


#pragma endregion
