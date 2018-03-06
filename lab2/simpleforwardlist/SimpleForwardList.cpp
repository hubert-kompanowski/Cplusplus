//
// Created by hubert on 05.03.18.
//

#include "SimpleForwardList.h"
#include <iostream>

using namespace std;

struct Node {
    int number;
    Node *next;
};


struct ForwardList {
    Node *head;
    ForwardList *CreateNode(int value){
        Node *new_number = new Node;

        new_number->number = value;

        if(head==0){
            head = new_number;
        }
        else{
            Node *temp = head;

            while(temp->next){
                temp = temp->next;
            }
            temp->next = new_number;
            new_number->next = 0;
        }
    }
};





//void DestroyList(ForwardList *list);
