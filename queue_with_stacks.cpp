//
// Created by babayega on 11/24/15.
//

#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "queue_with_stacks.h"

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *stack1;
    struct node *stack2;
};


void enqueue(struct queue *q, int x)
{
    push(&q->stack1,x);
}

int deque(struct queue *q)
{
    int x;
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        std::cout<<"Queue is empty";
        exit(0);
    }
    if (q->stack2 == NULL)
    {
        while (q->stack1 !=NULL)
        {
            x = pop(&q->stack1);
            push(&q->stack2, x);
        }
    }
    x = pop(&q->stack2);
    return x;

}

void push(struct node** top_ref, int new_data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));  //creating new node
    if(new_node == NULL)
    {
        std::cout<<"stack overflow";
        exit(0);
    }

    new_node->data = new_data;  //adding data to the node
    new_node->next = (*top_ref);   //linking the rest of the stack to the new_node
    (*top_ref) = new_node;  //making new_node as top node

}

int pop(struct node** top_ref)
{
    int res;
    struct node *top;

    if (*top_ref == NULL)
    {
        std::cout<<"stack empty";
        exit(0);
    }
    else
    {
        top = *top_ref;  //pointer to top_ref pointer is assigned top
        res = top->data;  //top->data is assigned to res
        *top_ref = top->next; // address of next node is assigned to top_ref
        free(top);  //top is freed
        return res;
    }
}


    void execute() {
        struct queue *queue1 = (struct queue *) malloc(sizeof(struct queue));
        queue1->stack1 = NULL;
        queue1->stack2 = NULL;
        enqueue(queue1, 1);
        enqueue(queue1, 2);
        enqueue(queue1, 3);
        enqueue(queue1, 4);
        std::cout << " " << deque(queue1);
        std::cout << " " << deque(queue1);
        enqueue(queue1, 5);
        enqueue(queue1, 6);


        std::cout << " " << deque(queue1);
        std::cout << " " << deque(queue1);
        std::cout << " " << deque(queue1);
        std::cout << " " << deque(queue1);

    }
