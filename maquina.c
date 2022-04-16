/**
 * @file maquina.c
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
 * @param isActive 
 * @return Maquina* 
 */

Maquina* novaMaquina(int id,bool isActive)
{
    Maquina* newMaquina = (Maquina*)malloc(sizeof(Maquina));
    if(newMaquina == NULL) //se nao houver memoria para alocar
    {
        return NULL;
    }

    newMaquina->id = id;
    newMaquina->isActive = isActive;
    newMaquina->next = NULL;

    return newMaquina;
}

/**
 * @brief 
 * 
 * @param head 
 * @param machineDeInicio 
 * @return Maquina* 
 */

Maquina* inserirMaquinaNoInicio(Maquina* head,Maquina* machineDeInicio)
{
    if (head == NULL) //se a lista estiver vazia
    {
        head = machineDeInicio;
    }
    else //se existir algum elemento na lista
    {
        machineDeInicio->next = head;
        head = machineDeInicio; 
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

bool escreverMaquinas(char fileName[],Maquina* head)
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

    Maquina* current = head;
    while(current != NULL) //escrever todos os elementos da lista no ficheiro
    {
        fprintf(file,"ID: %d\tisAtivo: %d\n",current->id,current->isActive);
        //fwrite(current, sizeof(Maquina),1,file);
        current = current->next;
    }

    if (fwrite == 0) //se nenhum elemento foi escrito no ficheiro
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
 * @return Maquina* 
 */

Maquina* lerMaquinas(char fileName[])
{
    Maquina* current = (Maquina*)malloc(sizeof(Maquina));
    Maquina* head = NULL;
    Maquina* last = NULL;

    FILE* file = NULL;
    file = fopen(fileName,"r");
    if(file == NULL) //se nao foi possivel abrir o ficheiro
    {
        return NULL;
    }

    while(fread(current,sizeof(Maquina),1,file)) //ler todos os elementos da lista do ficheiro
    {
        if(head == NULL) //ler o primeiro elemento
        {
            head = last = (Maquina*)malloc(sizeof(Maquina));
        }
        else //ler os restantes elementos
        {
            last->next = (Maquina*)malloc(sizeof(Maquina));
            last = last->next;
        }

        last->id = current->id;
        last->isActive = current->isActive;
        last->next = NULL; // o proximo elemento da lista nao existe, portanto é nulo
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

bool mostrarMaquinas(Maquina* head)
{
    if(head == NULL) //se a lista estiver vazia
    {
        return false;
    }

    Maquina* current = head;

    printf("Maquinas:\n");
    while(current != NULL) //enquanto a lista for diferente de NULL
    {
        printf("ID: %d, IsAtivo: %d\n",current->id,current->isActive);
        current = current->next;
    }

    return true;
}

/**
 * @brief 
 * 
 * @param head 
 * @param id 
 * @return true 
 * @return false 
 */

bool procurarMaquina(Maquina* head,int id)
{
    if(head == NULL) //se a lista estiver vazia
    {
        return false;
    }

    Maquina* current = head;

    while(current != NULL) //enquanto a lista for diferente de NULL
    {
        if(current->id == id) //verifica se existe o id na lista
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

bool apagarMaquinas(Maquina* head)
{
    Maquina* current = NULL;

    while(head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }

    return true;
}







