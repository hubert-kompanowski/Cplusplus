//
// Created by hubert on 05.03.18.
//

#include "SimpleForwardList.h"


ForwardList *CreateNode(int value) {
    auto* new_node = new ForwardList;
    new_node -> value = value;
    new_node -> next_node = nullptr;
    return new_node;
}


void DestroyList(ForwardList *list) {
    auto *current_node = list;
    ForwardList *tmp_node;

    while(current_node) {
        tmp_node = current_node;
        current_node = current_node->next_node;
        delete[] tmp_node;
    }
}


ForwardList *PushFront(ForwardList *list, int value) {
    if(!list) {
        return nullptr;
    } else {
        auto *tmp_node = new ForwardList;
        tmp_node->value = value;
        tmp_node->next_node = list;
        return tmp_node;
    }
}


void Append(ForwardList *list, ForwardList *tail) {
    if(list && tail) {
        auto *tmp_node = list;
        while (tmp_node->next_node) {
            tmp_node = tmp_node->next_node;
        }
        tmp_node->next_node = tail;
    }
}