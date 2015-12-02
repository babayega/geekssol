//
// Created by babayega on 11/30/15.
//

#include <iostream>
#include <vector>
#include "min_val_bt.h"

namespace min
{
    std::vector<int> inorder;
    struct node
    {
        int data;
        struct node* left;
        struct node* right;
    };
    struct node* head = NULL;
    void construct(int data)
    {
        struct node* node1 = new node;
        struct node* prev = new node;
        struct node* current;
        node1->data = data;
        node1->left = NULL;
        node1->right = NULL;
        if (head == NULL)
            head = node1;
        else
        {
            current = head;
            while (current != NULL)
            {
                prev = current;
                if (current->data < data)
                    current = current->right;
                else
                    current = current->left;
            }
            if (prev->data > data)
                prev->left = node1;
            else
                prev->right = node1;
        }
        
    }

    void min_val(struct node *node1)
    {
        struct node* prev = new node;
        while(node1 != NULL)
        {
            prev = node1;
            node1 = node1->left;
        }
        std::cout<<"\nThe minimum element in the tree is  "<<prev->data<<"\n";

    }

    void print(struct node* node1)
    {
        if (node1 != NULL)
        {
            print(node1->left);
            std::cout << " " << node1->data;
            inorder.push_back(node1->data);
            print(node1->right);
        }
    }

    void check_BST()
    {
        for (int i = 0; i < inorder.size()-1; ++i)
        {
            if (inorder[i] > inorder[i+1])
            {
                std::cout<<"\nNot BST";
                exit(0);
            }

        }
        std::cout << "\nValid BST";

    }

    void execute()
    {
        construct(5);
        construct(6);
        construct(3);
        construct(4);
        construct(7);
        print(head);
        min_val(head);
        check_BST();
    }
}