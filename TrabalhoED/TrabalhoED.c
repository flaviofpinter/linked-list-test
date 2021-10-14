#include<stdio.h>
#include<stdbool.h>
typedef struct list {
    int value;
    struct list* next;
} list;

void printList(list* head) {
    list* current = head;
    printf("\n");
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void insert(list* head, int val) {
    head = (list*) malloc(sizeof(list));
    list* current = head;
    while (current->next != NULL) {
        current = current->next;
        printf("IAI");
    }
    current->next = (list*) malloc(sizeof(list));
    current->next->value = val;
    current->next->next = NULL;
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

int removeLast(list* head) {
    int retvalue = 0;
    if (head->next == NULL) {
        retvalue = head->value;
        free(head);
        return retvalue;
    }

    list* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    retvalue = current->next->value;
    free(current->next);
    current->next = NULL;
    return retvalue;
}

int removeByIndex(list** head, int n) {
    int i = 0;
    int retvalue = -1;
    list* current = *head;
    list* temp = NULL;

    if (n == 0) {
        return pop(&head);
    }

    for (i = 0; i < n - 1;i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp = current->next;
    retvalue = current->next->value;
    free(current->next);

    return retvalue;
}

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
    list* head = NULL;
    int v;
    bool r = true;
    int i;
    while (r) {
        int opt = menu();
        switch (opt) {
        case 2:
            if (isEmpty(&head)) {
                printf("Digite o valor inicial: "); scanf_s("%d", &v);
                head = (list*) malloc(sizeof(list));
                head->value = v;
                head->next = NULL;
                printf("%d", head->value);
            }
            else {
                printf("Digite o valor: "); scanf_s("%d", &v);
                insert(head, v);
                printList(head);
            }
        break;
        case 3:
            printf("Removendo...");
            removeLast(head);
            break;
        case 4:
            printList(head);
        break;
        case 5:
            printf("Digite o index para busca: "); scanf_s("%d", &i);
            printf("\n Valor: %d", getByIndex(head, i));
        break;
        case 6:
            printf("Tamanho da lista : % d", length(head));
        break;
        case 7:
            printf("Encerrando...");
            r = false;
        }
    }
}

int menu()
{
    int input;
    printf("\n2 - Inserir\n");
    printf("3 - Excluir\n");
    printf("4 - Imprimir\n");
    printf("5 - Buscar\n");
    printf("6 - Nr. de Elementos\n");
    printf("7 - Fim\n");
    printf("A opção selecionada: "); scanf_s("%d", &input);

    return input;
}
// métodos que encerram tudo inesperadamente, print e insert