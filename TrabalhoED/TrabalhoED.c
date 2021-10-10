#include<stdio.h>
typedef struct list {
    int value;
    struct list* next;
} list;

void printList(list* head) {
    list* current = head;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void insert(list* head, int val) {
    list* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (list*) malloc(sizeof(list));
    current->next->value = val;
    current->next->next = NULL;
;}

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

void main(){
    list* head = NULL;
    head = (list*) malloc(sizeof(list));
    if (head == NULL) {
        return 1;
    } else{
        head->value = 1;
        head->next = NULL;
    }

    insert(head, 4);
    insert(head, 5);
    insert(head, 7);
    removeByIndex(&head, 2);
    printList(head);
}

int menu()
{
    int input;
    printf("1 - Iniciar/Reiniciar\n");
    printf("2 - Inserir\n");
    printf("3 - Excluir\n");
    printf("4 - Imprimir\n");
    printf("5 - Buscar\n");
    printf("6 - Nr. de Elementos\n");
    printf("7 - Fim\n");
    printf("A opção selecionada: "); scanf_s("%d", &input);

    return input;
}
