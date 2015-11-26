//
// Created by babayega on 11/24/15.
//

#include "reverse_linked.h"
#include <stdlib.h>
#include <iostream>

struct rnode
{
    int data;
    struct rnode *next;

};

void reverse(struct rnode** head_ref)
{
    struct rnode* prev = NULL;
    struct rnode* current = *head_ref;
    struct rnode* next;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void push(struct rnode **head_ref, int new_data)
{
    struct rnode *new_node = new rnode;  //creating new node
    if(new_node == NULL)
    {
        std::cout<<"stack overflow";
        exit(0);
    }

    new_node->data = new_data;  //adding data to the node
    new_node->next = (*head_ref);   //linking the rest of the stack to the new_node
    (*head_ref) = new_node;  //making new_node as top node

}

void printlist(struct rnode* head_ref)
{
    struct rnode *temp = head_ref;
    while (temp!=NULL)
    {
        std::cout<<" "<<temp->data;
        temp = temp->next;
    }
}

void rev::execute()
{
    struct rnode *head = NULL;

    push(&head, 20);
    push(&head, 10);
    push(&head, 1);
    push(&head, 4);

    printlist(head);
    reverse(&head);
    std::cout<<"\n";
    printlist(head);
}