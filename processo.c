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





















