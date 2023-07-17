#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MaxSize 100 //定义栈中元素的最大个数
typedef struct SqStack {
    int data[MaxSize]; //存放栈中的元素
    int top; //栈顶指针
}SqStack;
// 栈的初始化
SqStack* initSqStack() {
    SqStack* init = (SqStack*)malloc(sizeof(SqStack));
    init->top = -1;
    return init;
}
// 判空
int EmptySqStack(SqStack* p) {
    if (p->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
// 入栈
void pushSqStack(SqStack* p,int x) {
    if (p->top == MaxSize - 1) {
        return;
    }
    p->top += 1;
    p->data[p->top] = x;
}
// 出栈
void popSqStack(SqStack* p) {
    if (!EmptySqStack(p)) {
        p->top -= 1;
    }
}
// 读取栈顶元素
int readTopSqStack(SqStack* p) {
    if (!EmptySqStack(p)) {
        printf("%d\n", p->data[p->top]);
        return p->data[p->top];
    }
    return -1;
}
void forEachSqStack(SqStack* p) {
    for (int i = 0; i <= p->top; i++) {
        printf("%d\n", p->data[i]);
    }
}
// 顺序栈测试
void testSqStack() {
    SqStack* m = initSqStack();
    printf("%d\n", EmptySqStack(m));// 1
    pushSqStack(m, 1);
    pushSqStack(m, 2);
    pushSqStack(m, 3);
    pushSqStack(m, 4);
    pushSqStack(m, 5);
    forEachSqStack(m);// 1 2 3 4 5
    popSqStack(m);
    popSqStack(m);
    forEachSqStack(m);// 1 2 3
    readTopSqStack(m);// 3
}

// 链栈
typedef struct LinkNode {
    int data; //数据域
    struct LinkNode* next; //指针域
}LiStack; //栈类型定义
// 入栈
LiStack* pushLiStack(LiStack* p,int x) {
    LiStack* node = (LiStack*)malloc(sizeof(LiStack));
    node->next = NULL;
    node->data = x;
    if (p == NULL) {
        return node;
    }
    LiStack* m = p;
    while (m->next != NULL) {
        m = m->next;
    }
    m->next = node;
    return p;
}
// 出栈
LiStack* popLiStack(LiStack* p) {
    assert(p);
    if (p->next == NULL) {
        return NULL;
    }
    LiStack* m = p->next;
    LiStack* pre = p;
    while (m->next) {
        pre = m;
        m = m->next;
    }
    pre->next = NULL;
    free(m);
    return p;
}
// 遍历栈
void forEachLiStack(LiStack* p) {
    while (p) {
        printf("%d\n",p->data);
        p = p->next;
    }
}
// 链栈测试
void testLinkStack() {
    LiStack* p = NULL;
    p = pushLiStack(p, 1);
    p = pushLiStack(p, 2);
    p = pushLiStack(p, 3);
    p = pushLiStack(p, 4);
    p = pushLiStack(p, 5);
    forEachLiStack(p);
    p = popLiStack(p);
    p = popLiStack(p);
    forEachLiStack(p);
}
int main() {
   // testSqStack();
    testLinkStack();
}