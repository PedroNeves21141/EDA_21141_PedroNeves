/**
 * @file main.c
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
#include "header.h"

/**
 * @brief Conta numero total de processos
 * 
 * @param head 
 * @return int (retorna o numero total de processos)
 */


int getListCount(Processo* head)
{
    if(head == NULL) // se a lista estiver vazia
    {
        return NULL;
    }

    int count = 0;
    Processo* current = head;

    while(current != NULL) //enquanto a lista for diferente de NULL
    {
        count++;
        current = current->next;
    }

    return count;
}

bool mostrarProcessoOperation(Processo* head1, OperationExecution* head)
{
    if(head == NULL || head1 == NULL)
    {
        return false;
    }

    Processo* current1 = head1;
    OperationExecution* current = head;

    printf("Lista:\n");
    while(current != NULL || current1 != NULL)
    {
        printf("ProcessoID: %d, OperationID: %d, MachineID: %d, Tempo: %d\n",current1->id,current->operationID,current->machineID,current->usageTime);
        current = current->next;
        current1 = current1->next;
    }

    return true;
}

/**
 * @brief 
 * 
 * @return int 
 */

int main()
{
    int op = 0;
    int op1 = 0;
    int op2 = 0;
    int opM = 0;
    int opO = 0;
    int op3 = 0;
    int op4 = 0;
    int op5 = 0;
    int op6 = 0;
    int opPrc = 0;
    int proPr;
    int valido = op6;
    int op7 = 0;

    Processo* processo = NULL;
    Maquina* maquina = NULL;
    Operation* operation = NULL;
    OperationExecution* operationExecution = NULL;
    ProcessoPart* processopart = NULL;

    Processo* processos = NULL;
    Maquina* maquinas = NULL;
    Operation* operations = NULL;
    OperationExecution* operationExecutions = NULL;
    ProcessoPart* processoparts = NULL;

    //FASE 1
        //Carregar dados para as tabelas
        loadData(&processos,&maquinas,&operations,&operationExecutions,&processoparts);
        //Guardar os dados em ficheiros
        escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
        escreverOperations("Listas/operation.txt",operations);
        escreverProcessos("Listas/processo.txt",processos);
        escreverProcessosPart("Listas/processopart.txt",processoparts);

    do
    {
        system("cls");
        printf("Menu:\n\n");
        printf("1 - Mostrar a Execucao dos Jobs\n\n");
        printf("///////////////////////////\n\n");
        printf("2 - Inserir um novo job\n");
        printf("3 - Remover um job\n");
        printf("4 - Inserir uma nova operacao a um job\n");
        printf("5 - Remover uma determinada operacao de um job\n");
        printf("6 - Editar operacoes associadas a um determinado job\n");
        printf("7 - Proposta de escalonamento\n\n");
        printf("///////////////////////////\n\n");
        printf("0 - Sair\n\n");
        printf("Opcao: "); scanf("%d",&op);

        switch (op)
        {
        case 1:
            system("cls");
            //Mostrar lista de execucao das operacoes
            mostrarProcessoOperation(processos,operationExecutions);
            system("pause");
            break;
        case 2:
            system("cls");
            //Inserir Processo - Funciona
            printf("Insire um id para o processo: "); scanf("%d",&op1);

            while((procurarProcessoPart(processoparts,op1) != false)||(op1 < 1))
            {
                system("cls");
                printf("Valor inserido esta incorreto ou ja esta inserido na lista!\n\n");
                printf("Insire um id para o processo: "); scanf("%d",&op1);
                if(op1 == 0)
                {
                    break;
                }
            }
            system("cls");
            printf("Selecione quantas operacoes vai querer neste processo: "); scanf("%d",&opM);
            system("cls");
            int operation = 0;
            int maquina = 0;
            int time = 0;
            for (int i = 1; i <= opM; i++)
            {
                system("cls");
                printf("(%d) - Digite o id da operacao: ",i); scanf("%d",&operation);
                printf("Digite o id da maquina para a operacao (%d): ",operation); scanf("%d",&maquina);
                printf("Digite o tempo: "); scanf("%d",&time);
                processo = novoProcesso(op1);
                processos = inserirProcessoNoInicio(processos,processo);
                operationExecution = novoOperationExecution(operation,maquina,time);
                operationExecutions = inserirOperationExecutionNoInicio(operationExecutions,operationExecution);                
            }
            processopart = novoProcessoPart(op1);
            processoparts = inserirProcessoPartNoInicio(processoparts,processopart);
            system("cls");
            escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
            escreverJob("job.txt",processos,operationExecutions);
            escreverOperations("Listas/operation.txt",operations);
            system("pause");
            break;
        case 3:
            system("cls");
            int zero;
            //Remover Processo - Em falta
            printf("Selecione o id do processo que deseja eliminar: ");scanf("%d",&op2);
            printf("zero: "); scanf("%d",&zero);
            int count = 0;

            while((procurarProcesso(processos,op2) == false)&&(procurarProcessoPart(processoparts,op2) == false))
            {
                system("cls");
                printf("Nao Existe!\n\n");
                printf("Selecione o id do processo que deseja eliminar: "); scanf("%d",&op2);
                if(op2 == 0)
                {
                    break;
                }
            }

            while(procurarProcesso(processos,op2) != false)
            {
                eliminarProcessoOperationExecution(processos,op2);
                count=count+1;
            }

            while(procurarProcessoPart(processoparts,op2) == true)
            {
                eliminarProcessoPart(&processoparts,op2);
            }

            escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
            escreverJob("job.txt",operationExecutions);
            escreverOperations("Listas/operation.txt",operations);
            escreverProcessosPart("Listas/processopart.txt",processoparts);
            system("pause");
            break;

        case 4:
            system("cls");
            //Inserir operação a um job - 
            printf("Processo: "); scanf("%d",&op3);

            while((procurarProcessoPart(processoparts,op3) == false)||(op3 < 1))
            {
                system("cls");
                printf("Valor inserido esta incorreto ou ja esta inserido na lista!\n\n");
                printf("Processo: "); scanf("%d",&op3);
                if(op3 == 0)
                {
                    break;
                }
            }
            printf("Selecione o id da operacao: "); scanf("%d",&opO);

            while((procurarProcessoOperationExecutionOp(processos,operationExecutions,op3,opO) != false)||(opO < 1))
            {
                system("cls");
                printf("Valor inserido esta incorreto ou ja esta inserido na lista!\n\n");
                printf("Selecione o id da operacao: "); scanf("%d",&opO);
                if(opO == 0)
                {
                    break;
                }
            }
            printf("Selecione o id da maquina: "); scanf("%d",&op4);
            printf("Selecione o tempo: "); scanf("%d",&op5);
            
            processo = novoProcesso(op3);
            processos = inserirProcessoNoInicio(processos,processo);
            operationExecution = novoOperationExecution(opO,op4,op5);
            operationExecutions = inserirOperationExecutionNoInicio(operationExecutions,operationExecution);                
            processopart = novoProcessoPart(op3);
            processoparts = inserirProcessoPartNoInicio(processoparts,processopart);
            system("cls");
            escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
            escreverJob("job.txt",processos,operationExecutions);
            escreverOperations("Listas/operation.txt",operations);
            system("pause");
            break;
        case 5:
            system("cls");
            int proc,oper;
            //Remover uma determinada operacao de um job
            printf("Selecione o id do processo: "); scanf("%d",&proc);
            printf("Selecione o id da operacao: "); scanf("%d",&oper);
            
            while((procurarProcessoOperationExecutionOp(processos,operationExecutions,proc,oper) == false)&&(procurarProcessoPart(processoparts,op2) == false))
            {
                system("cls");
                printf("Valores inseridos estao incorretos!\n\n");
                printf("Selecione o id do processo: "); scanf("%d",&proc);
                printf("Selecione o id da operacao: "); scanf("%d",&oper);
            
                if(proc == 0 || oper == 0)
                {
                    break;
                }
            }

            if(procurarProcessoOperationExecutionOp(processos,operationExecutions,proc,oper) != false)
            {
                while(eliminarProcessoOperationExecution(processos,op2) != false)
                {
                    count=count+1;
                }
            }

            if(procurarProcessoPart(processoparts,proc) == true)
            {
                eliminarProcessoPart(&processoparts,proc);
            }

            system("pause");
            escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
            escreverJob("job.txt",operationExecutions);
            escreverOperations("Listas/operation.txt",operations);
            escreverProcessosPart("Listas/processopart.txt",processoparts);
            system("pause");
            break;
        case 6:
            system("cls");
            //Editar uma determinada operação de um determinado processo
                int ope1,ope2,ope2U,ope3,ope3U,ope4,ope4U,opeO;
                system("cls");

                printf("Selecione o id do processo: "); scanf("%d",&ope1);
                while((procurarProcesso(processos,ope1) == false)&&(procurarProcessoPart(processoparts,ope1) == false))
                {
                    system("cls");
                    printf("Nao Existe!\n\n");
                    printf("Selecione o id do processo: "); scanf("%d",&ope1);
                }

                printf("\nAlterar: \n");
                printf("\n\t(OperacaoID) - Selecione 1");
                printf("\n\t(MachineID) - Selecione 2");
                printf("\n\t(Tempo) - Selecione 3");
                printf("\n\nOpcao: "); scanf("%d",&opeO);

                switch (opeO)
                {
                case 1: //Alterar Operação
                    system("cls");
                    printf("Selecione a id da operation: "); scanf("%d",&ope2);
                    printf("Selecione o id que deseja: "); scanf("%d",&ope2U);

                    while(procurarProcessoOperationExecutionOp(processos,operationExecutions,ope1,ope2) != true)
                    {
                        system("cls");
                        printf("Nao Existe!\n\n");
                        printf("Selecione a id da operation: "); scanf("%d",&ope2);
                        printf("Selecione o id que deseja: "); scanf("%d",&ope2U);
                    }

                    if(procurarProcessoOperationExecutionOp(processos,operationExecutions,ope1,ope2) != false)
                    {
                        atualizarProcessoOperationExecution(processos,operationExecutions,ope1,ope2,ope2U);
                        printf("Operacao atualizada com sucesso!\n");
                    }
                    escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
                    escreverJob("job.txt",processos,operationExecutions);
                    escreverOperations("Listas/operation.txt",operations);
                    system("pause");
                    break;
                case 2: // Alterar Maquina
                    system("cls");
                    printf("Selecione a id da operation: "); scanf("%d",&ope2);
                    printf("Selecione a id da maquina: "); scanf("%d",&ope3);
                    printf("Selecione o id que deseja: "); scanf("%d",&ope3U);

                    while(procurarProcessoOperationExecutionOpMaquina(processos,operationExecutions,ope1,ope2,ope3) != true)
                    {
                        system("cls");
                        printf("Nao Existe!\n\n");
                        printf("Selecione a id da operation: "); scanf("%d",&ope2);
                        printf("Selecione a id da maquina: "); scanf("%d",&ope3);
                        printf("Selecione o id que deseja: "); scanf("%d",&ope3U);
                    }

                    if(procurarProcessoOperationExecutionOpMaquina(processos,operationExecutions,ope1,ope2,ope3) != false)
                    {
                        atualizarProcessoOperationExecutionMaquina(processos,operationExecutions,ope1,ope2,ope3,ope3U);
                        printf("Maquina atualizada com sucesso!\n");
                    }
                    escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
                    escreverJob("job.txt",processos,operationExecutions);
                    escreverOperations("Listas/operation.txt",operations);
                    system("pause");
                    break;
                case 3: //Alterar Tempo
                    system("cls");
                    printf("Selecione a id da operation: "); scanf("%d",&ope2);
                    printf("Selecione a id da maquina: "); scanf("%d",&ope3);
                    printf("Selecione o tempo que deseja: "); scanf("%d",&ope4U);

                    while (procurarProcessoOperationExecutionOpMaquina(processos,operationExecutions,ope1,ope2,ope3) != true)
                    {
                        system("cls");
                        printf("Nao existe!\n\n");
                        printf("Selecione a id da operation: "); scanf("%d",&ope2);
                        printf("Selecione a id da maquina: "); scanf("%d",&ope3);
                        printf("Selecione o tempo que deseja: "); scanf("%d",&ope4U);
                    }
                    

                    if(procurarProcessoOperationExecutionOpMaquina(processos,operationExecutions,ope1,ope2,ope3) != false)
                    {
                        atualizarProcessoOperationExecutionTempo(processos,operationExecutions,ope1,ope2,ope3,ope4U);
                        printf("Tempo atualizada com sucesso!\n");
                    }
                    escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
                    escreverJob("job.txt",processos,operationExecutions);
                    escreverOperations("Listas/operation.txt",operations);
                    system("pause");
                    break;
                case 0:
                    
                    break;
                }
                break;
        case 7:
            system("cls");
            printf("Proposta de escalonamento:\n\n");
            //Minimo

            int i = 0;
            int j = 0;
            int maiorOperacao = 1;
            int count2 = 0;
            int maiorProcesso = 90;
            int operationIDOK = 1;
            printf("Menor tempo possivel para realizar todos os processos(jobs):\n");

            for(i=1;i<=maiorProcesso;i++)
            {
                while(maiorOperacao != 100)
                {
                    if(procurarOperationExecutionOp(processos,operationExecutions,i,maiorOperacao) != false)
                    {
                        count2 = count2 + TempoMinimoDaOperacao(processos,operationExecutions,i,maiorOperacao);
                    }
                    maiorOperacao = maiorOperacao + 1;       
                }
            }

            printf("\nCount: %d\n",count2);
            system("pause");
            break;
        case 0:
            printf("Adeus!\n\n");
            break;                        
        default:
            break;
        }
    }while (op < 1 && op > 8 || op != 0);

        return true;
}
