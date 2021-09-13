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
    if(stack == NULL) return false;
}
void push(node **stack, int data){
    node *tempNode = newNode(data);
    tempNode->next = *stack;
    *stack = tempNode;
    //printf("%d pushed\n", data);
}

int pop(node **stack){
    if(isEmpty(*stack)) return INT_MIN;
    node *temp = *stack;
    *stack = (*stack)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
void printList(node* list){
    while(list != NULL){
        printf("%d - ", list->data);
        list = list->next;
    }
    printf("\n");
}
int main(){
    node *head = NULL;
    push(&head, 1);
    push(&head, 1);
    push(&head, 1);
    push(&head, 1);
   
    //pop(&head);
    printList(head);
    //pop(&head);

}
