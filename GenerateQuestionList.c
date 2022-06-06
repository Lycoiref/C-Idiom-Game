#include <stdio.h>
#include <stdlib.h>
#include "data.c"
#include<time.h>

// 定义一个栈数据结构，用于存放题目顺序
typedef struct Stack {
    int num[50];    //题号
    int type[50];   //题目类型
    int top;
} Stack;

// 存放出栈元素的结构体
typedef struct StackNode {
    int num;
    int type;
} StackNode;

// 入栈
void push(Stack *s, int num, int type) {
    s->num[++s->top] = num;
    s->type[s->top] = type;
}

// 出栈,返回出栈的题号和题目类型
struct StackNode pop(Stack *s) {
    struct StackNode node;
    node.num = s->num[s->top];
    node.type = s->type[s->top];
    s->top--;
    return node;
}

// 定义一个链表数据结构，用于存放不同类型题目的题号
typedef struct List {
    int num;
    struct List *next;
} List;

void initQuestion(Stack *s) {
    s->top = -1;
    // 生成一个由0到15的链表
    List *type1_head = (List *) malloc(sizeof(List));
    List *p = type1_head;
    for (int i = 0; i < 16; i++) {
        p->num = i;
        p->next = (List *) malloc(sizeof(List));
        p = p->next;
    }
    // 生成一个由0到13的链表type2
    List *type2_head = (List *) malloc(sizeof(List));
    p = type2_head;
    for (int i = 0; i < 14; i++) {
        p->num = i;
        p->next = (List *) malloc(sizeof(List));
        p = p->next;
    }
    // 生成一个由0到19的链表type3
    List *type3_head = (List *) malloc(sizeof(List));
    p = type3_head;
    for (int i = 0; i < 20; i++) {
        p->num = i;
        p->next = (List *) malloc(sizeof(List));
        p = p->next;
    }
    // 初始化题目栈
    int j;
    List *q;
    // 随机生成50个元素的数组，其中16个元素为1，14个元素为2，20个元素为3
    int type[50];
    for (j = 0; j < 16; j++) {
        type[j] = 1;
    }
    for (j = 16; j < 30; j++) {
        type[j] = 2;
    }
    for (j = 30; j < 50; j++) {
        type[j] = 3;
    }
    // 打乱数组
    for (j = 0; j < 50; j++) {
        int k = rand() % 50;
        int temp = type[j];
        type[j] = type[k];
        type[k] = temp;
    }
    // 判断题目类型
    for (int k = 0; k < 50; k++) {
        int type_num = type[k];
        switch (type_num) {
            case 1:
                // 随机生成题号
                j = rand() % 16;
                // 将题号压入栈
                push(s, type1_head->next->num, type_num);
                // 删除题号
                q = type1_head->next;
                type1_head->next = q->next;
                free(q);
                break;
            case 2:
                // 随机生成题号
                j = rand() % 14;
                // 将题号压入栈
                push(s, type2_head->next->num, type_num);
                // 删除题号
                q = type2_head->next;
                type2_head->next = q->next;
                free(q);
                break;
            case 3:
                // 随机生成题号
                j = rand() % 20;
                // 将题号压入栈
                push(s, type3_head->next->num, type_num);
                // 删除题号
                q = type3_head->next;
                type3_head->next = q->next;
                free(q);
                break;
            default:
                break;
        }
    }
}
