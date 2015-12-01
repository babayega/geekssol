//
// Created by babayega on 11/30/15.
//

#include <iostream>
#include "min_val_bt.h"

namespace min
{
    struct node
    {
        int data;
        struct node* left;
        struct node* right;
    };
    struct node* head = NULL;
    void construct(struct node* node1, int data)
    {
        if(node1 == NULL)
        {
            (node1)->data = data;
            (node1)->left = NULL;
            (node1)->right = NULL;
            std::cout<<" "<<node1->data;
            if (head == NULL)
                head = node1;
        }
        else
        {

            if(node1->data < data)
            {
                construct(node1->right, data);
            }
            else
            {
                construct(node1->left, data);
            }
        }
        
    }

  /*  void min_val(struct node *head_ref)
    {

    }*/

    void print(struct node* node1)
    {
        if (node1 != NULL)
        {
            print(node1->left);
            std::cout << " " << node1->data;
            print(node1->right);
        }
    }

    void execute()
    {
        construct(head, 5);
        construct(head, 6);
        construct(head, 3);
        construct(head, 5);
        construct(head, 7);
        print(head);
    }
}