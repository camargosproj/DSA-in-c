#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Creating a stack using struct
typedef struct NodeStack{
    int data;
    struct NodeStack *next;
}node;

node* newNode(int data){
    node* stack =  malloc(sizeof(node));
    stack->data = data;
    stack->next = NULL;
    return stack;
}
bool isEmpty(node* stack){
    if(stack == NULL) return true;
}
void push(node **stack, int data){
    node *tempNode = newNode(data);
    tempNode->next = *stack;
    *stack = tempNode;
    //printf("%d pushed\n", data);
}

int pop(node** stack){
    // if(isEmpty(*stack)){
    //     //printf("Is Empty\n");
    //     return INT_MIN;
    // }
    node *temp = *stack;
    *stack = (*stack)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
void printList(node* stack){
    while(!isEmpty(stack)){
        printf("%d - ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}
void swap(node *stack)
{
    if(isEmpty(stack))
    {
        printf("\nPilha Vazia!\n");
        return;
    }
    node *no_aux = malloc(sizeof(node)); 
    node *tmp = stack->next; 

    while(tmp->next != NULL)
        tmp = tmp->next;   
    no_aux->data = tmp->data; 
    tmp->data = stack->data; 
    stack->data = no_aux->data; 

    free(no_aux);
}

int main(){
    node *head = NULL;
    push(&head,11);
    push(&head,22);
    push(&head,33);
    push(&head,44);
    //pop(&head);
    printList(head);
    swap(head);
    printList(head);
}
