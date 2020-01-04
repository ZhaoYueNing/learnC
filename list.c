#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LIST_NODE* _list_init_node(LIST_NODE_TYPE type);
LIST* _list_init();

LIST* list_create(){
    LIST* list = _list_init();
    list->_len = 0;

    LIST_NODE* first_node = _list_init_node(LIST_NODE_SENTRY_TYPE);
    LIST_NODE* last_node = _list_init_node(LIST_NODE_SENTRY_TYPE);
    first_node->_next = last_node;
    last_node->_prev = first_node;


    list->first_node = first_node;
    list->last_node = last_node;
    return list;
}

void list_add(LIST* list, void* data){
    LIST_NODE* node = _list_init_node(LIST_NODE_DATA_TYPE);
    node->_data = data;

    node->_prev = list->last_node->_prev;
    node->_next = list->last_node;
    list->last_node->_prev->_next = node;
    list->last_node->_prev = node;
    list->_len++;
}

int list_has_next(LIST_NODE* node){
    return node->_next != NULL && node->_next->type == LIST_NODE_DATA_TYPE;
}

int list_has_prev(LIST_NODE* node){
    return node -> _prev != NULL && node->_prev->type == LIST_NODE_DATA_TYPE;
}

long list_size(LIST* list){
    return list->_len;
}

void list_free(LIST* list){
    LIST_NODE *node = list->first_node;
    while (list_has_next(node)) {
        LIST_NODE *node1 = node;
        node = node->_next;
        free(node1);
    }
    free(list->last_node);
    free(list);
}


LIST_NODE *list_next_node(LIST_NODE *node) {
    return node->_next;
}

LIST_NODE *list_prev_node(LIST_NODE *node){
    return node->_prev;
}

LIST_NODE *list_get_node(LIST *list, long index) {
    if (index >= list_size(list)) return NULL;

    long cur_index = 0;
    LIST_NODE *node = list->first_node;
    while (list_has_next(node)) {
        node = node ->_next;
        if (cur_index++ == index) return node;
    }
    return NULL;
}

LIST_NODE *list_get_data(LIST *list, long index) {
    LIST_NODE *node = list_get_node(list, index);
    if (node != NULL) return node->_data;
    return NULL;
}

LIST* _list_init(){
    LIST* list = (LIST*) malloc(sizeof(LIST));
    return list;
}

LIST_NODE* _list_init_node(LIST_NODE_TYPE type){
    LIST_NODE* node = (LIST_NODE*) malloc(sizeof(LIST_NODE));
    node->type = type;
    return node;
}
