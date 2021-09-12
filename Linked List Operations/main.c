#include "linkedList.h"

int main(){
    nodeList* head = NULL;
    nodeList* new = NULL;
   
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int num, max = 0;
    while(max < 10){
        //printf("Enter the %d° element: ", max);
        //scanf("%d",vetor[max]);
        append(&head, vetor[max]);
        max++;
    }
    new = splitByValue(&head,5);
    printList(new);
    printList(head);

  
    return 0;

}