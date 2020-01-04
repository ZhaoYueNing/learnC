//
// Created by zhaoyuening on 2020/1/4.
//

#ifndef LEARNC_LIST_H
#define LEARNC_LIST_H

#endif //LEARNC_LIST_H

typedef struct LIST_NODE LIST_NODE;
typedef struct LIST LIST;
typedef enum LIST_NODE_TYPE LIST_NODE_TYPE;

struct LIST{
    // 列表的长度
    long _len;
    // 第一个节点
    LIST_NODE *first_node;
    // 第二个节点
    LIST_NODE *last_node;
};

// 节点类型
enum LIST_NODE_TYPE{
    // 数据节点
    LIST_NODE_DATA_TYPE,
    // 哨兵类型
    LIST_NODE_SENTRY_TYPE,
};

struct LIST_NODE {
    // 节点类型
    LIST_NODE_TYPE type;
    void* _data;
    LIST_NODE *_prev;
    LIST_NODE *_next;
};

LIST *list_create();
void list_add(LIST *list, void *data);
long list_size(LIST *list);
LIST_NODE *list_next_node(LIST_NODE *node);
LIST_NODE *list_prev_node(LIST_NODE *node);
void list_free(LIST* list);
LIST_NODE *list_get_node(LIST *list, long index);
LIST_NODE *list_get_data(LIST *list, long index);


