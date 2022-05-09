#include "circular.h"

int main(){
    node *head,*temp;
    head = init(head);
    head = insertFront(head,5);
    head = insertFront(head,8);
    head = insertFront(head,6);

    display(head);
}