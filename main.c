//
// Created by zhaoyuening on 2020/1/4.
//

#include <stddef.h>
#include <stdio.h>
#include "list.h"

int main() {
    char *str1 = "aa";
    char *str2 = "bb";
    char *str3 = "cc";

    LIST* list = list_create();
    list_add(list, str1);
    list_add(list, str2);
    list_add(list, str3);


    printf("%ld\n", list_size(list));
    LIST_NODE *node = list->first_node->_next;
    while (node != NULL && node->_data != NULL) {
        printf("%s", node->_data);
        node = node->_next;
    }

    char *s = (char *) list_get_data(list, 2);
    printf("%s", s);
    list_free(list);
}