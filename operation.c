/**
 * @file operation.c
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
 * @brief Inserir uma nova operação
 * 
 * @param id 
 * @return Operation* 
 */

Operation* novoOperation(int id)
{
    Operation* newOperation = (Operation*)malloc(sizeof(Operation));
    if(newOperation == NULL) //se nao houver memoria para alocar
    {
        printf("Entrou");
        return NULL;

    }

    newOperation->id = id;
    newOperation->next = NULL;

    return newOperation;
}

/**
 * @brief 
 * 
 * @param head 
 * @param operationNoInicio 
 * @return Operation* 
 */

Operation* inserirOperationNoInicio(Operation* head,Operation* operationNoInicio)
{
    if (head == NULL) //se a lista estiver vazia
    {
        head = operationNoInicio;
    }
    else //se existir algum elemento na lista
    {
        operationNoInicio->next = head;
        head = operationNoInicio; 
    }

    return head;
}

/**
 * @brief 
 * 
 * @param head 
 * @param operationParaAtualizar 
 * @param id 
 * @return true 
 * @return false 
 */

bool atualizarOperation(Operation** head, Operation** operationParaAtualizar,int id)
{
    if(*head == NULL) //se a lista estiver vazia
    {
        return false;
    }
    
    Operation* current = *head;

    while (current != NULL) //enquanto a lista for diferente de NULL,este corre todos os elementos da Operation
    {
        if(current->id == id)
        {
            current = operationParaAtualizar;
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
 * @param id 
 * @return true 
 * @return false 
 */

bool eliminarOperation(Operation** head,int id)
{
    if(*head == NULL) //se a lista estiver vazia
    {
        return false;
    }

    Operation* current = *head;
    Operation* previous = NULL;

    if(current != NULL && current->id == id) //se a lista for diferent de NULL e o id da lista for igual ao id inserido apaga-se a operação
    {
        *head = current->next;
        return true;
    }

    if(current == NULL) //se o elemento não foi encontrado
    {
        return false;
    }

    while(current != NULL && current->id != id) //procurar o elemento a ser apagado
    {
        previous = current;
        current = current->next;
        //free(current);
        //current = NULL;
    }

    previous -> next = current->next; // desassociar o elemento da lista
    free(current);
    //current = NULL;

     
    return true;
}

/**
 * @brief 
 * 
 * @param fileName 
 * @param head 
 * @return true 
 * @return false 
 */

bool escreverOperations(char fileName[],Operation* head)
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

    Operation* current = head;

    while(current != NULL) //escrever todos os elementos da lista no ficheiro
    {

        fprintf(file,"ID: %d\n",current->id);
        //fwrite(current, sizeof(Operation),1,file);
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
 * @return Operation* 
 */

Operation* lerOperations(char fileName[])
{
    Operation* current = (Operation*)malloc(sizeof(Operation));
    Operation* head = NULL;
    Operation* last = NULL;

    FILE* file = NULL;
    file = fopen(fileName,"r");
    if(file == NULL) //se nao foi possivel abrir o ficheiro
    {
        return NULL;
    }

    while(fread(current,sizeof(Operation),1,file)) //ler todos os elementos da lista do ficheiro
    {
        if(head == NULL) //ler o primeiro elemento
        {
            head = last = (Operation*)malloc(sizeof(Operation));
        }
        else //ler os restantes elementos
        {
            last->next = (Operation*)malloc(sizeof(Operation));
            last = last->next;
        }

        last->id = current->id;
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

bool mostrarOperations(Operation* head)
{
    if(head == NULL) //se a lista estiver vazia
    {
        return false;
    }

    Operation* current = head;

    printf("Operacoes:\n");
    while(current != NULL) //enquanto a lista for diferente de NULL
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
 * @param id 
 * @return true 
 * @return false 
 */

bool procurarOperationporID(Operation* head, int id)
{
    if(head == NULL)
    {
        return false;
    }

    Operation* current = head;
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

bool apagarOperations(Operation* head)
{
    Operation* current = NULL;

    while(head != NULL) //enquanto a lista for diferente de NULL
    {
        current = head;
        head = head->next;
        free(current);
    }
    
    return true;
}

/**
 * @brief 
 * 
 * @param operationID 
 * @param machineID 
 * @param usageTime 
 * @return OperationExecution* 
 */

OperationExecution* novoOperationExecution(int operationID,int machineID,int usageTime)
{
    OperationExecution* newOperationExecution = (OperationExecution*)malloc(sizeof(OperationExecution));

    if(newOperationExecution == NULL) //se não houver memoria para alocar
    {
        return NULL;
    }

    newOperationExecution->operationID = operationID;
    newOperationExecution->machineID = machineID;
    newOperationExecution->usageTime = usageTime;
    newOperationExecution->next = NULL;

    return newOperationExecution;
}

/**
 * @brief 
 * 
 * @param head 
 * @param operationExecutionDeInicio 
 * @return OperationExecution* 
 */

OperationExecution* inserirOperationExecutionNoInicio(OperationExecution*head,OperationExecution* operationExecutionDeInicio)
{
    if(head == NULL) //se a lista estvier vazia
    {
        head = operationExecutionDeInicio;
    }
    else // se existir algum elemento na lista
    {
        operationExecutionDeInicio->next = head;
        head = operationExecutionDeInicio;
    }

    return head;
}

/**
 * @brief 
 * 
 * @param head 
 * @param operationID 
 * @return true 
 * @return false 
 */

bool eliminarOperationExecution(OperationExecution** head,int operationID)
{
    if(head == NULL) //se a lista estiver vazia
    {
        return false;
    }

    OperationExecution* current = head;
    OperationExecution* previous = NULL;
    
    if(current != NULL && current->operationID == operationID) //se a lista for diferent de NULL e o id da lista for igual ao id inserido apaga-se a operação
    {
        *head = current->next;
        return true;
    }

    if(current == NULL) //se o elemento não foi encontrado
    {
        return false;
    }

    while(current != NULL && current->operationID != operationID) //procurar o elemento a ser apagado
    {
        previous = current;
        current = current->next;
        //free(current);
        //current = NULL;
    }

    previous -> next = current->next; // desassociar o elemento da lista
    free(current);
    //current = NULL;

     
    return true;

}

/**
 * @brief 
 * 
 * @param fileName 
 * @param head 
 * @return true 
 * @return false 
 */

bool escreverOperationExecution(char fileName[],OperationExecution* head)
{
    if(head == NULL) //se a lista estiver vazia
    {
        return false;
    }

    FILE * file = NULL;
    file = fopen(fileName,"w");
    if (file == NULL) // se nao foi possivel abrir o ficheiro
    {
        return false;
    }

    OperationExecution* current = head;
    while(current != NULL) //escrever todos os elementos da lista de ficheiros
    {
        fprintf(file,"OperationID: %d\tMaquinaID: %d\tTempo: %d\n",current->operationID,current->machineID,current->usageTime);
        current = current->next;
    }

    if(fprintf == 0)  //se nenhum elemento foi escrito no ficheiro
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
 * @return OperationExecution* 
 */

OperationExecution* lerOperationsExecution(char fileName[])
{
    OperationExecution* current = (OperationExecution*)malloc(sizeof(OperationExecution));
    OperationExecution* head = NULL;
    OperationExecution* last = NULL;

    FILE* file = NULL;
    file = fopen(fileName,"r");
    if(file == NULL) //se nao foi possivel abrir o ficheiro
    {
        return NULL;
    }

    while(fread(current,sizeof(OperationExecution),1,file)) //ler todos os elementos da lista de ficheiros
    {
        if(head == NULL) //ler o primeiro elemento
        {
            head = last = (OperationExecution*)malloc(sizeof(OperationExecution));
        }
        else //ler os restantes elementos
        {
            last->next = (OperationExecution*)malloc(sizeof(OperationExecution));
            last = last->next;
        }

        last->operationID = current->operationID;
        last->machineID = current->machineID;
        last->usageTime = current->usageTime;
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

bool mostrarOperationExecution(OperationExecution* head)
{
    if(head == NULL)
    {
        return false;
    }

    OperationExecution* current = head;

    //printf("Execucao de Operacoes:\n");
    while(current != NULL) //se a lista for diferente de NULL
    {
        printf("ID Operacoes: %d, ID Maquina: %d, Tempo: %d\n",current->operationID,current->machineID,current->usageTime);
        current = current->next;
    }

    return true;
}

/**
 * @brief 
 * 
 * @param head 
 * @param operationID 
 * @param machineID 
 * @return OperationExecution* 
 */

OperationExecution* procurarOperationExecution(OperationExecution** head,int operationID,int machineID)
{
    if(head == NULL)
    {
        return false;
    }

    
    OperationExecution* current = head;


    while (current != NULL) //enquanto a lista for diferente de NULL
    {  

        if((current->operationID == operationID)&&(current->machineID == machineID)) //verifica se existe o operationID na lista
        {
            return current;
        }
         current = current->next;
        
    }
    return false;
}


/**
 * @brief 
 * 
 * @param head 
 * @param operationID 
 * @return OperationExecution* 
 */

OperationExecution* procurarOperationExecutionOp(Processo** head1,OperationExecution** head,int id,int operationID)
{
    if(head == NULL)
    {
        return false;
    }

    Processo* current1 = head1;
    OperationExecution* current = head;

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

/**
 * @brief 
 * 
 * @param head 
 * @return true 
 * @return false 
 */

bool apagarOperationExecution(OperationExecution* head)
{
    OperationExecution* current = NULL;

    while(head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }

    return true;
}

/**
 * @brief 
 * 
 * @param operations 
 * @param executions 
 * @param minexecutions 
 * @return int 
 */

int maxOperationExecution(Operation* operations, OperationExecution* executions, OperationExecution** minexecutions)
{
    int time = 0;
	int counter = 0;

    if(operations == NULL || executions == NULL)
    {
        return false;
    }

    Operation* currentOperation = operations;
	OperationExecution* currentExecution = executions;
    OperationExecution* maxExecution = NULL;

    while (currentOperation != NULL) // percorrer lista de operações
	{
			while (currentExecution != NULL) // percorrer lista de execução de operações
			{
				if (currentExecution->operationID == currentOperation->id) // se encontrar a execucação de operação relativa à operação
				{
					// guardar execução de operação com maior tempo de utilização
					if (currentExecution->usageTime > time)
					{
						time = currentExecution->usageTime;
						maxExecution = novoOperationExecution(currentExecution->operationID, currentExecution->machineID, currentExecution->usageTime);
					}
				}

				currentExecution = currentExecution->next;
			}
            
		// repor lista percorrida (currentExecution), para que se for necessário voltar a percorrer o while da execução de operações de novo
		apagarOperationExecution(currentExecution);
		currentExecution = NULL;
		currentExecution = executions;
		counter += time; // acumular o tempo de utilização de cada execução de operação
		time = 0; // resetar tempo de utilização para a próxima iteração

		currentOperation = currentOperation->next;
	}

	return counter;
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 */

int avgOperationExecution(OperationExecution* head,int operationID)
{
   float sum = 0, i= 0;
   float avg = 0;

    if(head == NULL)
    {
        return false;
    }

    OperationExecution* current = head;
    while(current != NULL)
    {
        if(current->operationID == operationID) //se a lista for diferente de NULL
        {
            //printf("ID Operações: %d, ID Máquina: %d, Tempo: %d\n",current->operationID,current->machineID,current->usageTime);
            sum=sum+current->usageTime;
            i=i+1;
        }

        current = current->next;
    }
        avg=(float)sum/i;
        printf("\nMedia do tempo: %.2f\n",avg);
        return avg;
}

/**
 * @brief 
 * 
 * @param head 
 * @param operationParaAtualizar 
 * @param usageTime 
 * @return true 
 * @return false 
 */

bool atualizarOperationExecution(Processo** head1,OperationExecution** head, OperationExecution* operationParaAtualizar,int operationID)
{
    if(head == NULL) //se a lista estiver vazia
    {
        return false;
    }
    
    OperationExecution* current = &head;
    Processo* current1 = &head1;

    while (current != NULL) //enquanto a lista for diferente de NULL,este corre todos os elementos da Operation
    {
        if(operationID != 0)
        {
             current = operationParaAtualizar;
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
 * @return OperationExecution* 
 */

OperationExecution* OrdenarExecucaoPorOrdem(OperationExecution* head){
	//if (head == NULL) return head;// se a lista estiver vazia

	OperationExecution* current = head;
	OperationExecution* sorted = NULL;
	OperationExecution* new = NULL;

	while (current != NULL)
	{
		new = novoOperationExecution(current->operationID, current->machineID, current->usageTime);
		sorted = inserirOperationExecutionNoInicio(&sorted, new);
		current = current->next;
	}

	return sorted;
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 */

int TempoMinimoDaOperacao(Processo* head,OperationExecution* head1,int id,int operationID)
{
    int min=9999,auxOperation=0,auxMaquina=0;

    if(head1 == NULL || head == NULL || operationID == NULL)
    {
        printf("entrou");
        return false;
    }

    Processo* current = head;
    OperationExecution* current1 = head;
    
    while(current1 != NULL) //se a lista for diferente de NULL
    {
        if((current->id == id) && (current1->operationID == operationID))
        {
            printf("entrou2");
            if (current1->usageTime <= min)
            {
                printf("entrou3");
                min = current1->usageTime;
                auxOperation = current1->operationID;
                auxMaquina = current1->machineID;
            }
        }
            current1 = current1->next;
            current = current->next;
    }

    if(auxOperation != 0)
    {
        printf("\tProcessoID: %d\tOperacaoID: %d\tMaquinaID: %d\tTempo: %d\n",current->id,auxOperation,auxMaquina,min);
        return min;
    }
    return false;
    
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 */

int TempoMaximoDaOperacao(OperationExecution* head,int operationID)
{
    int max=0,auxOperation=0,auxMaquina=0;

    if(head == NULL || operationID == NULL)
    {
        return false;
    }

    OperationExecution* current = head;

    max = current->usageTime;
    while(current != NULL) //se a lista for diferente de NULL
    {
        if(current->operationID == operationID)
        {
            if (current->usageTime > max)
            {
                max = current->usageTime;
                auxOperation = current->operationID;
                auxMaquina = current->machineID;
            }
        }
        current = current->next;
    }

    if(auxOperation != 0)
    {
        printf("\tOperacaoID: %d\tMaquinaID: %d\tTempo: %d\n",auxOperation,auxMaquina,max);
        return max;
    }
    return false;
    
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 */

int maiorOperation(OperationExecution* head)
{
    int maiorO;

    if(head == NULL)
    {
        return false;
    }

    OperationExecution* current = head;

    maiorO = current->operationID;
    while(current != NULL) //se a lista for diferente de NULL
    {
    if (current->operationID > maiorO)
      {
         maiorO = current->operationID;
      }
        current = current->next;
    }

    return maiorO;

}