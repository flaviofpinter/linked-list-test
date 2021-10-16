#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct list {
    int value;
    struct list* next;
} list;

void printList(list* head) {
    list* current = head;
    printf("\n");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

void insert(list** head, int val) {
    list* newItem = malloc(sizeof(list));
    newItem->value = val;
    newItem->next = NULL;
    list* current = *head;
    
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newItem;
}

int pop(list** head) {
    int retvalue = -1;
    list* nextItem = NULL;

    if (*head == NULL) {
        return -1;
    }


    nextItem = (*head)->next;
    retvalue = (*head)->value;
    free(*head);
    *head = nextItem;

    return retvalue;
}

void removeLast(list* head) {
    if (head->next == NULL) {
        free(head);
    }

    list* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
}
//     TESTE
//int removeByIndex(list** head, int n) {
//    int i = 0;
//    int retvalue = -1;
//    list* current = *head;
//    list* temp = NULL;
//
//    if (n == 0) {
//        return pop(&head);
//    }
//
//    for (i = 0; i < n - 1;i++) {
//        if (current->next == NULL) {
//            return -1;
//        }
//        current = current->next;
//    }
//
//    temp = current->next;
//    retvalue = current->next->value;
//    free(current->next);
//
//    return retvalue;
//}

int getByIndex(list* head, int n) {
    list* current = head;
    int index = 0;
    while (current != NULL) {
        if (index == n) {
            return (current->value);
        }
        index++;
        current = current->next;
    }
}

int length(list* head) {
    list* current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

bool isEmpty(list** head) {
    if(*head == NULL){
        return true;
    }
    else {
        return false;
    }
}


void main(){
    

    printf("----------------MENU----------------");
    exec();
}

int menu()
{
    int input;
    printf("\n1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Imprimir\n");
    printf("4 - Buscar\n");
    printf("5 - Nr. de Elementos\n");
    printf("6 - Fim\n");
    printf("A opcao selecionada: "); scanf_s("%d", &input);

    return input;
}

int exec(){
    int v;
    bool r = true;
    int i;
    list* head = NULL;
    while (r) {
        int opt = menu();
        switch (opt) {
        case 1:
            if (isEmpty(&head)) {
                printf("Digite o valor inicial: "); scanf_s("%d", &v);
                head = (list*)malloc(sizeof(list));
                head->value = v;
                head->next = NULL;
                //printf("%d", head->value);
            }
            else {
                printf("Digite o valor: "); scanf_s("%d", &v);
                insert(&head, v);
            }
            break;
        case 2:
            if (head == NULL) {
                printf("\nA lista esta vazia!!\n");
                break;
            }
            else if (head->next == NULL) {
                pop(&head);
                printf("\nA lista esta vazia agora\n");

            }
            else {
                printf("\nRemovendo...\n");
                removeLast(head);
            }
            break;
        case 3:
            printList(head);
            break;
        case 4:
            printf("\nDigite o index do valor que deseja buscar: "); scanf_s("%d", &i);
            printf("\n Valor: %d\n", getByIndex(head, i));
            break;
        case 5:
            printf("\nTamanho da lista : %d\n", length(head));
            break;
        case 6:
            printf("\nEncerrando...\n");
            r = false;
        }
    }
}