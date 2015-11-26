//
// Created by babayega on 11/26/15.
//

#include <iostream>
#include "list_mid_ele.h"

namespace mid
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node* head = NULL;

    void insert()
    {
        struct  node* current = NULL;
        for (int i = 1; i < 10; ++i)
        {

            struct node* temp = new node;
            temp->data = i;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
                current = temp;
            }
            else
            {
                current->next = temp;
                current = temp;
            }

        }
    }

    void print()
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            std::cout<<" "<<temp->data;
            temp = temp->next;
        }
    }

    void middle_ele()
    {
        int count1 = 0;
        struct node* temp1 = head;
        struct node* temp2 = head;
        while (temp2 != NULL && temp2->next != NULL)
        {
            temp1 = temp1->next;
            ++count1;
            temp2 = temp2->next->next;
        }
        std::cout<<"The middle element is "<<temp1->data;
    }

    void execute()
    {
        insert();
        print();
        middle_ele();
    }

}