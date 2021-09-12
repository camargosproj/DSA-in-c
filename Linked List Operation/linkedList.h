#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node
{
    int data;
    struct Node* next;
}nodeList;

void printList(nodeList* list);
void push(nodeList** head_ref, int new_data);
void insertAfter(nodeList* prev_node, int new_data);
void append(nodeList** head_ref, int new_data);
void deleteNode(nodeList** head_ref, int key);
void deleteByPosition(nodeList** head_ref, int position);
int getLen(nodeList* head);
bool search(nodeList* head, int value);
int getByIndex(nodeList* head, int index);
void splitList(nodeList** source, nodeList** aRef, nodeList** bRef);
void moveNode(nodeList** destRef, nodeList** sourceRef);
nodeList* splitByValue(nodeList** head, int value); 


//Print a given list passing a head or a node ref
void printList(nodeList* list){
    while(list != NULL){
        printf("%d - ", list->data);
        list = list->next;
    }
    printf("\n");
}
// Inserting an element at the beginning of a list
void push(nodeList** head_ref, int new_data){
    nodeList* new_node = malloc(sizeof(nodeList));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}
//Inserting an element just after a given previous node
void insertAfter(nodeList* prev_node, int new_data){
    if(prev_node == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
    // Creating a temp node to assign a new data
    nodeList* new_node = malloc(sizeof(nodeList));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    //Pointing to the new node 
    prev_node->next = new_node;
}
//Inserting an element at the end of a linked list
void append(nodeList** head_ref, int new_data){
    //Alocate memory to a new node
    nodeList* new_node = malloc(sizeof(nodeList));
    nodeList* last = *head_ref;

    new_node->data = new_data;
    //Checking if the list is empty
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    // Looping till the end to find the last node
    while (last->next != NULL)
    {
        last = last->next;
    }
    //When the loop ends last is gonna point to the new data
    last->next = new_node;
    return;
}
void deleteNode(nodeList** head_ref, int key){
    //store head node 
    nodeList *temp = *head_ref, *prev;
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next; //If it's true head is gonna have the next value
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    //if key was not present in linket list
    if(temp == NULL)
        return;
    //unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}
//Deleting a node by position
void deleteByPosition(nodeList** head_ref, int position){
    //Check if it is empty
    if(*head_ref == NULL)
        return;
    nodeList* temp = *head_ref;

    if(position == 0){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    //Find the prev node
    for(int i = 0; temp != NULL && i < position-1; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        return;
    }
    nodeList* next = temp->next->next;
    free(temp->next);
    temp->next = next;

}
//Get a length of a linked list
int getLen(nodeList* head){
    int count = 0;
    nodeList* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;    
}
//Search an element in linked list
bool search(nodeList* head, int value){
    nodeList* current = head;
    while(current != NULL){
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
        
    }
    return false;
}
// Find an element by index
int getByIndex(nodeList* head, int index){
    nodeList* current = head;
    int count = 0;
    while (current != NULL)
    {
        if(count == index){
            return (current->data);
        }
        count++;
        current = current->next;
    }
    assert(0);
    
}
//Move node alternatively


void moveNode(nodeList** destRef, nodeList** sourceRef){
    nodeList* newNode = *sourceRef;
    assert(newNode != NULL);

    *sourceRef = newNode->next;

    newNode->next = *destRef;

    *destRef = newNode;
}
void splitList(nodeList** source, nodeList** aRef, nodeList** bRef){
    nodeList* a = NULL;
    nodeList* b = NULL;

    nodeList* current = source;
    while (current != NULL)
    {
        moveNode(&a,&current);
        if(current != NULL)
        {
            moveNode(&b, &current);
        }
    }
    *aRef = a;
    *bRef = b;
}
nodeList* splitByValue(nodeList** head, int value) 
{
     nodeList* new_list = malloc(sizeof(nodeList)); 
     nodeList* temp =  malloc(sizeof(nodeList));   
     temp = *head;
     while (temp != NULL)
     {  
        if(temp->data == value){
            new_list = temp->next;
            temp->next = NULL;
            return new_list;
        }    
        temp = temp->next;
     }
    return NULL;
}
