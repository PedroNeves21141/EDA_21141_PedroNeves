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

    Processo* processos = NULL;
    Maquina* maquinas = NULL;
    Operation* operations = NULL;
    OperationExecution* operationExecutions = NULL;

    //FASE 1
        //Carregar dados para as tabelas
        loadData(&processos,&maquinas,&operations,&operationExecutions);
        //Guardar os dados em ficheiros
        escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
        escreverOperations("Listas/operation.txt",operations);

    do
    {
        system("cls");
        printf("Menu:\n\n");
        printf("1 - Mostrar a Execucao das operacoes\n\n");
        printf("///////////////////////////\n\n");
        printf("2 - Inserir nova operacao\n");
        printf("3 - Remover uma operacao\n");
        printf("4 - Alterar uma operacao\n\n");
        printf("///////////////////////////\n\n");
        printf("5 - Minimo\n");
        printf("6 - Maximo\n");
        printf("7 - Media\n\n");
        printf("///////////////////////////\n\n");
        printf("0 - Sair\n\n");
        printf("Opcao: "); scanf("%d",&op);

        switch (op)
        {
        case 1:
            system("cls");
            //Mostrar lista de execucao das operacoes
            mostrarOperationExecution(operationExecutions);
            system("pause");
            break;
        case 2:
            system("cls");
            //Inserir um nova operacao
            printf("Selecione o ID para a operacao: "); scanf("%d",&op2);
            if((procurarOperationExecutionOp(operationExecutions,op2) != false)||(op2 < 1))
            {
                while((procurarOperationExecutionOp(operationExecutions,op2) != false)||(op2 < 1))
                {
                    system("cls");
                    printf("Valor inserido esta incorreto ou ja esta inserido na lista!\n\n");
                    printf("Selecione o ID para a operacao: "); scanf("%d",&op2);
                }
                
            }
            printf("Selecione quantas maquinas vai querer nesta operacao: "); scanf("%d",&opM);
            system("cls");
            int time = 0;
            for (int i = 1; i <= opM; i++)
            {
                printf("Que tempo pretende inserir para a %d maquina: ",i); scanf("%d",&time);
                operation = novoOperation(op2);
                operations = inserirOperationNoInicio(operations, operation);
                maquina = novaMaquina(i,false);
                maquinas = inserirMaquinaNoInicio(maquinas,maquina);
                operationExecution = novoOperationExecution(op2,i,time);
                operationExecutions = inserirOperationExecutionNoInicio(operationExecutions,operationExecution);                
            }
            escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
            escreverJob("job.txt",operationExecutions);
            escreverOperations("Listas/operation.txt",operations);
            system("pause");
            break;
        case 3:
            //Remover uma operacao
            system("cls");
            printf("Que operation pretende eliminar: "); scanf("%d",&op1);
            int count = 0;

            while(procurarOperationExecutionOp(operationExecutions,op1) == false)
            {
                system("cls");
                printf("Nao Existe!\n\n");
                printf("Que operation pretende eliminar: "); scanf("%d",&op1);
            }

            if(procurarOperationExecutionOp(operationExecutions,op1) == true)
            {
                while(procurarOperationExecutionOp(operationExecutions,op1) == true)
                {
                   
                    if(eliminarOperationExecution(operationExecutions,op1))
                    {
                        count=count+1;
                    }
                }
            }
            else
            {
                printf("Valor Indisponivel tente de novo\n");
            }

            printf("Foram eliminados %d maquinas!\n",count);

            while(procurarOperationporID(operations,op1) == true)
            {
                eliminarOperation(&operations,op1);
            }

            system("pause");
            escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
            escreverJob("job.txt",operationExecutions);
            escreverOperations("Listas/operation.txt",operations);
            break;

        case 4:
            system("cls");
            //Alterar uma operacao
            int ope2,ope3,ope4;
            system("cls");
            printf("Operacao: "); scanf("%d",&ope2);
            printf("Maquina: "); scanf("%d",&ope3);
            printf("Que tempo quer inserir : "); scanf("%d",&ope4);

            while(procurarOperationExecution(operationExecutions,ope2,ope3) == 0)
                {
                    system("cls");
                    printf("Esta operacao que inseriu nao existe\n\n");
                    printf("Operacao: "); scanf("%d",&ope2);
                    printf("Maquina: "); scanf("%d",&ope3);
                    printf("Que tempo quer inserir : "); scanf("%d",&ope4);
                }

            if(procurarOperationExecution(operationExecutions,ope2,ope3) != 0)
            {

                OperationExecution* operationParaAtualizar = procurarOperationExecution(operationExecutions,ope2,ope3);
                operationParaAtualizar->usageTime = ope4;
                if(atualizarOperationExecution(operationExecutions,operationParaAtualizar,operationParaAtualizar->usageTime))
                {
                    printf("Operacao atualizada com sucesso!\n");
                }


                system("pause");
                escreverOperationExecution("Listas/operations-execution.txt",operationExecutions);
                escreverJob("job.txt",operationExecutions);
                escreverOperations("Listas/operation.txt",operations);
            }
            else
            {
                 printf("Tente de novo com valores corretos\n\n");
            }
            break;
        case 5:
            system("cls");
            //Minimo
            int TempoMin;
            TempoMin = TempoMinimoDaOperacao(operationExecutions);
            system("pause");
            break;
        case 6:
            system("cls");
            //Maximo
            int TempoMax;
            TempoMax = TempoMaximoDaOperacao(operationExecutions);
            system("pause");
            break;
        case 7:
            system("cls");
            //Media a funcionar
            int id;
            printf("Insire o ID da Operacao: "); scanf("%d",&id);
            while(procurarOperationporID(operations,id) == false)
            {
                system("cls");
                printf("Nao Existe!\n\n");
                printf("Insire o ID da Operacao: "); scanf("%d",&id);
            }
            avgOperationExecution(operationExecutions,id);
            system("pause");
            break;
        case 0:
            printf("Adeus!\n\n");
            break;                        
        default:
            break;
        }
    }while (op < 1 && op > 10 || op != 0);

        return true;
}
