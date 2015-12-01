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
    void construct(int data)
    {
        struct node* node1;
        struct node* prev = NULL;
        node1->data = data;
        node1->left = NULL;
        node1->right = NULL;
        std::cout<<" "<<node1->data;
        if (head == NULL)
            head = node1;
        else
        {
            while (node1 != NULL)
            {
                prev = node1;
                if (node1->data < data)
                    node1 = node1->right;
                else
                    node1 = node1->left;
            }
            if (prev->data > data)
                prev->left = node1;
            else
                prev->right = node1;
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
        construct(5);
        construct(6);
        construct(3);
        construct(5);
        construct(7);
        print(head);
    }
}