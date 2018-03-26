//
// Created by hubert on 05.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#include <iostream>


struct ForwardList {
    ForwardList* next_node;
    int value;
};

ForwardList *CreateNode(int value);

void DestroyList(ForwardList *list);

ForwardList *PushFront(ForwardList *list, int value);

void Append(ForwardList *list, ForwardList *tail);


#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
