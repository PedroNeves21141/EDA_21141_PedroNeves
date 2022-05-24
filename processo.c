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
 * @brief 
 * 
 * @param id 
 * @return Processo* 
 */

Processo* novoProcesso(int id)
{
    Processo* newProcesso = (Processo*)malloc(sizeof(Processo));
    if(newProcesso == NULL) //se nao houver memoria para alocar
    {
        return NULL;
    }
    
    newProcesso->id = id;
    newProcesso->OperationExecutions = NULL;
    newProcesso->next = NULL;

    return newProcesso;
}

/**
 * @brief 
 * 
 * @param head 
 * @param ProcessoDeInicio 
 * @return Processo* 
 */

Processo* inserirProcessoNoInicio(Processo* head, Processo* ProcessoDeInicio)
{
    if (head == NULL) //se a lista estiver vazia
    {
        head = ProcessoDeInicio;
    }
    else //se existir algum elemento na lista
    {
        ProcessoDeInicio->next = head;
        head = ProcessoDeInicio;
    }

    return head;
}

/**
 * @brief 
 * 
 * @param fileName 
 * @param head 
 * @return true 
 * @return false 
 */

bool escreverProcessos(char fileName[],Processo* head)
{
    if(head == NULL) //se lista está vazia
    {
        return false;
    }

    FILE * file = NULL;
    file = fopen(fileName,"w");
    if(file == NULL) //se não foi possivel abrir o ficheiro
    {
        return false;
    }

    Processo* current = head;
    while (current != NULL) // escrever todos os elementos da lista de ficheiro
    {
        fprintf(file,"ID: %d\n",current->id);
        //fwrite(current, sizeof(Processo),1,file);
        current = current->next;
    }

    if(fprintf == 0) //se nenhum elemento foi escrito no ficheiro
    {
        fclose(file);
        return false;
    }

    fclose(file);

    return true;

}

/**
 * @brief 
 * 
 * @param fileName 
 * @return Processo* 
 */

Processo* lerProcessos(char fileName[])
{
    Processo* current = (Processo*)malloc(sizeof(Processo));
    Processo* head = NULL;
    Processo* last = NULL;

    FILE* file = NULL;
    file = fopen(fileName,"r");
    if(file == NULL) //se não for possivel abrir o ficheiro
    {
        return NULL;
    }

    while (fread(current,sizeof(Processo),1,file)) //ler todos os elementos da lista
    {
        if(head == NULL) //ler o primeiro elemento
        {
            head = last = (Processo*)malloc(sizeof(Processo));
        }
        else //ler os restantes elementos
        {
            last -> next = (Processo*)malloc(sizeof(Processo));
            last = last->next;
        }

        last->id = current->id;
        last->next = NULL; //o proximo elemento da lista nao existe, portanto é nulo
    }

    fclose(file);

    return head;
}

/**
 * @brief 
 * 
 * @param head 
 * @return true 
 * @return false 
 */

bool mostrarProcessos(Processo* head)
{
    if(head == NULL)
    {
        return false;
    }

    Processo* current = head;
    printf("Processos:\n");
    while(current != NULL)
    {
        printf("ID: %d\n",current->id);
        current = current->next;
    }

    return true;
}

/**
 * @brief 
 * 
 * @param head 
 * @param ProcessoParaAtualizar 
 * @param id 
 * @return Processo* 
 */

Processo* atualizarProcesso(Processo* head,Processo* ProcessoParaAtualizar,int id)
{
    if(head == NULL)
    {
        return NULL;
    }

    Processo* current = head;

    while(current != NULL)
    {
        if(current->id == id)
        {
            head = ProcessoParaAtualizar;
            return current;
        }
        current = current->next;
    }

    return head;
}

/**
 * @brief 
 * 
 * @param head 
 * @param id 
 * @return true 
 * @return false 
 */

bool eliminarProcesso(Processo** head, int id)
{
    if(*head == NULL)
    {
        return false;
    }

    Processo* current = *head;
    Processo* previous = NULL;

    if(current != NULL && current->id == id) //se o elemento que será apagado é o primeiro da lista
    {
        *head = current->next;
        free(current);
        return true;
    }

    while(current != NULL && current->id != id) //procurar o elemento a ser apagado
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next; //desassociar o elemento da lista
    free(current);

    return true;;
}

/**
 * @brief 
 * 
 * @param head 
 * @param id 
 * @return true 
 * @return false 
 */

bool procurarProcesso(Processo* head,int id)
{
    if(head == NULL)
    {
        return false;
    }

    Processo* current = head;

    while (current != NULL)
    {
        if(current->id == id)
        {
            return true;
        }
        current = current->next; 
    }
     return false;
}

/**
 * @brief 
 * 
 * @param head 
 * @return true 
 * @return false 
 */

bool apagarProcessos(Processo* head)
{
    Processo* current = NULL;

    while(head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }

    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////


ProcessoPart* novoProcessoPart(int id)
{
    ProcessoPart* newProcessoPart = (ProcessoPart*)malloc(sizeof(ProcessoPart));
    if(newProcessoPart == NULL) //se nao houver memoria para alocar
    {
        return NULL;
    }
    
    newProcessoPart->id = id;
    newProcessoPart->next = NULL;

    return newProcessoPart;
}

ProcessoPart* inserirProcessoPartNoInicio(ProcessoPart* head, ProcessoPart* ProcessoDeInicio)
{
    if (head == NULL) //se a lista estiver vazia
    {
        head = ProcessoDeInicio;
    }
    else //se existir algum elemento na lista
    {
        ProcessoDeInicio->next = head;
        head = ProcessoDeInicio;
    }

    return head;
}

bool eliminarProcessoPart(ProcessoPart** head, int id)
{
    if(*head == NULL)
    {
        return false;
    }

    ProcessoPart* current = *head;
    ProcessoPart* previous = NULL;

    if(current != NULL && current->id == id) //se o elemento que será apagado é o primeiro da lista
    {
        *head = current->next;
        free(current);
        return true;
    }

    while(current != NULL && current->id != id) //procurar o elemento a ser apagado
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next; //desassociar o elemento da lista
    free(current);

    return true;;
}

bool mostrarProcessosPart(ProcessoPart* head)
{
    if(head == NULL)
    {
        return false;
    }

    ProcessoPart* current = head;
    printf("ProcessosPartList:\n");
    while(current != NULL)
    {
        printf("ID: %d\n",current->id);
        current = current->next;
    }

    return true;
}

bool escreverProcessosPart(char fileName[],ProcessoPart* head)
{
    if(head == NULL) //se lista está vazia
    {
        return false;
    }

    FILE * file = NULL;
    file = fopen(fileName,"w");
    if(file == NULL) //se não foi possivel abrir o ficheiro
    {
        return false;
    }

    ProcessoPart* current = head;
    while (current != NULL) // escrever todos os elementos da lista de ficheiro
    {
        fprintf(file,"ID: %d\n",current->id);
        //fwrite(current, sizeof(Processo),1,file);
        current = current->next;
    }

    if(fprintf == 0) //se nenhum elemento foi escrito no ficheiro
    {
        fclose(file);
        return false;
    }

    fclose(file);

    return true;

}

ProcessoPart* procurarProcessoPart(ProcessoPart* head,int id)
{
    if(head == NULL)
    {
        return false;
    }

    ProcessoPart* current = head;

    while (current != NULL)
    {
        if(current->id == id)
        {
            return current;
        }
        current = current->next; 
    }
     return false;
}

bool eliminarProcessoOperationExecution(Processo** head,int id)
{
    if(head == NULL)
    {
        return false;
    }

    Processo* current = head;

    while (current != NULL) //enquanto a lista for diferente de NULL
    {
        if(current->id == id)//verifica se existe o operationID na lista
        {
            current->id = 0;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool eliminarProcessoOperationExecutionOp(Processo** head,OperationExecution** head1,int id,int operation)
{
    if(head == NULL)
    {
        return false;
    }

    int zero = 0;
    Processo* current = head;
    OperationExecution* current1 = head1;

    while(current != NULL) //enquanto a lista for diferente de NULL
    {
        if((current->id == id) && (current1->operationID == operation))//verifica se existe o operationID na lista
        {
            current1->operationID = zero;
            return true;
        }
        current = current->next;
        current1 = current1->next;
    }
    return false;
}

bool procurarProcessoOperationExecutionOp(Processo** head1,OperationExecution** head,int id,int operationID)
{
    if(head == NULL || head1 == NULL)
    {
        return false;
    }

    OperationExecution* current = head;
    Processo* current1 = head1;

    while (current != NULL) //enquanto a lista for diferente de NULL
    {
        if((current1->id == id)&&(current->operationID == operationID))//verifica se existe o operationID na lista
        {
            return true;
        }
        current = current->next;
        current1 = current1->next; 
    }
    return false;
}

bool procurarProcessoOperationExecutionOpMaquina(Processo** head1,OperationExecution** head,int id,int operationID,int machineID)
{
    if(head == NULL || head1 == NULL)
    {
        return false;
    }

    OperationExecution* current = head;
    Processo* current1 = head1;

    while (current != NULL) //enquanto a lista for diferente de NULL
    {
        if((current1->id == id)&&(current->operationID == operationID)&&(current->machineID == machineID))//verifica se existe o operationID na lista
        {
            return true;
        }
        current = current->next;
        current1 = current1->next; 
    }
    return false;
}

bool atualizarProcessoOperationExecution(Processo** head1,OperationExecution** head,int id,int operationID,int update)
{
    if(head == NULL || head1 == NULL)
    {
        return false;
    }

    OperationExecution* current = head;
    Processo* current1 = head1;

    while (current != NULL) //enquanto a lista for diferente de NULL
    {
        if((current1->id == id)&&(current->operationID == operationID))//verifica se existe o operationID na lista
        {
            current->operationID = update;
            return true;
        }
        current = current->next;
        current1 = current1->next; 
    }
    return false;
}

bool atualizarProcessoOperationExecutionMaquina(Processo** head1,OperationExecution** head,int id,int operationID,int machineID,int update)
{
    if(head == NULL || head1 == NULL)
    {
        return false;
    }

    OperationExecution* current = head;
    Processo* current1 = head1;

    while (current != NULL) //enquanto a lista for diferente de NULL
    {
        if((current1->id == id)&&(current->operationID == operationID)&&((current->machineID == machineID)))//verifica se existe o operationID na lista
        {
            current->machineID = update;
            return true;
        }
        current = current->next;
        current1 = current1->next; 
    }
    return false;
}

bool atualizarProcessoOperationExecutionTempo(Processo** head1,OperationExecution** head,int id,int operationID,int machineID,int update)
{
    if(head == NULL || head1 == NULL)
    {
        return false;
    }

    OperationExecution* current = head;
    Processo* current1 = head1;

    while (current != NULL) //enquanto a lista for diferente de NULL
    {
        if((current1->id == id)&&(current->operationID == operationID)&&(current->machineID == machineID))//verifica se existe o operationID na lista
        {
            current->usageTime = update;
            return true;
        }
        current = current->next;
        current1 = current1->next; 
    }
    return false;
}