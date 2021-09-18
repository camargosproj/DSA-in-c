#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Defining a constant
#define MAX 10

int count = 0;

// Creating a stack using struct
typedef struct structstack{
    int items[MAX];
    int top;
}stack;

// Initializing an empty stack 

void creatEmptyStack(stack *stack){
    stack->top = -1;
}

// Check if the stack is full
bool isFull(stack *stack){
    if(stack->top == MAX -1){
        return true;
    }
    return false;
}

// Check if the stack is empty
int isEmpty(stack *stack){
    if(stack->top == -1){
        return true;
    }
    return false;
}

// Add elements into stack
bool push(stack *stack, int newItem){
    if(isFull(stack)){
      printf("Stack is Full!\n");
      return false;  
    } 
    stack->top++;
    stack->items[stack->top] = newItem;
    count++;

}

// Remove elements from stack
bool pop(stack *stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!\n");
        return false;
    } 
    stack->items[stack->top];
    stack->top--;
    count--;
}
//Reverse a Stack 
stack* reverse(stack *new){
    stack* temp = malloc(sizeof(stack));
    if(isEmpty(new)){
        printf("Stack is Empty!\n");
        return false;
    } 
    for (int i = 0; i < count; i++)
    {
        temp->items[i] = new->items[new->top];
        new->top--;
    }   
    return temp;
}
//Print elements of a stack
void printStack(stack *stack){
    if(!isEmpty(stack)){
        printf("Stack: ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
     
    }
}

// Main Program
int main(){
    int ch;
    stack *s = (stack*)malloc(sizeof(stack));
    creatEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
  
    printStack(s);
    stack *reversed = reverse(s); // Reversing a stack
    
    printStack(reversed);

    
}