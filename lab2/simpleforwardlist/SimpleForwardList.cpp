//
// Created by matematyk60 on 14.03.17.
//

#include "SimpleForwardList.h"





ForwardList* CreateNode(int value){
    ForwardList *list = new ForwardList;
    list->next = nullptr;
    list->value = value;

    return list;
}

void DestroyList (ForwardList *list){
    ForwardList *tmp = list;
    ForwardList *tmp2 = list;

    while(tmp != nullptr){
        tmp2 = tmp->next;
        delete tmp;
        tmp = tmp2;
    }
}

ForwardList *PushFront(ForwardList *list, int value){
    if(list == nullptr){
        return nullptr;
    }

    ForwardList *new_node = CreateNode(value);
    new_node->next = list;
    list = new_node;

    return list;
}

void Append(ForwardList *list, ForwardList *tail){
    if(list == nullptr){
        return;
    }
    ForwardList *tmp = list;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    tmp->next = tail;
}

