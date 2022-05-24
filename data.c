/**
 * @file data.c
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
 * @brief Carregar dados do tipo Processos, Maquinas, Operation e OperationExecution
 * 
 * @param processos lista de processos
 * @param maquinas lista de maquinas
 * @param operations lista de operations
 * @param operationsExecution lista de operationExecution
 */

void loadData(Processo** processos,Maquina** maquinas,Operation** operations,OperationExecution** operationsExecution,ProcessoPart** processoparts)
{
    Processo* processo = NULL;
    Maquina* maquina = NULL;
    Operation* operation = NULL;
    OperationExecution* operationExecution = NULL;
    ProcessoPart* processopart = NULL;
    int op1,op2,op3,op4;

    FILE* fp = fopen("job.txt", "r");
 
   
    if (!fp)
        printf("Can't open file\n");
 
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
 
        int row = 0;
        int column = 0;
     
 
 
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
 
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 0)
                continue;
 
            // Splitting the data
            char* value = strtok(buffer, ", ");
 
        while (value) {
                // Column 1
                if (column == 0) {
                    printf("%d", value);
                    op1 = atoi(value);
                }
 
                // Column 2
                if (column == 1) {
                    printf("%d", value);
                    op2 = atoi(value);
                }
 
                // Column 3
                if (column == 2) {
                    printf("%s", value);
                    op3 = atoi(value);
                   
                }

                // Column 4
                if (column == 3) {
                    printf("%s", value);
                    op4 = atoi(value);
                   
                }
                
                //printf("-->%s", value);
                value = strtok(NULL, ", ");
                column++;
                
            }

                processo = novoProcesso(op1);
                *processos = inserirProcessoNoInicio(*processos,processo);
                processopart = novoProcessoPart(op1);
                *processoparts = inserirProcessoPartNoInicio(*processoparts,processopart);
                operation = novoOperation(op2);
                *operations = inserirOperationNoInicio(*operations, operation);
                operationExecution = novoOperationExecution(op2,op3,op4);
                *operationsExecution = inserirOperationExecutionNoInicio(*operationsExecution, operationExecution);
                printf("\n");
        }
 
        // Close the file
        fclose(fp);
    }
}

/**
 * @brief Escrever no ficheiro job.txt
 * 
 * @param fileName 
 * @param head 
 * @return true 
 * @return false 
 */

bool escreverJob(char fileName[],Processo* head,OperationExecution* head1)
{
    if(head == NULL) //se a lista estiver vazia
    {
        return false;
    }

    FILE* file = NULL;
    file = fopen(fileName,"w");
    if(file == NULL) //se nao foi possivel abrir o ficheiro
    {
        return false;
    }

    Processo* current = head;
    OperationExecution* current1 = head1;
    while(current != NULL || current1 != NULL) //escrever todos os elementos da lista no ficheiro
    {
        if((current->id != 0) && (current1->operationID != 0))
        {
            fprintf(file,"%d,%d,%d,%d\n",current->id,current1->operationID,current1->machineID,current1->usageTime);
            current = current->next;
            current1 = current1->next;
        }
    }

    if (fwrite == 0) //se nenhum elemento foi escrito no ficheiro
    {
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}