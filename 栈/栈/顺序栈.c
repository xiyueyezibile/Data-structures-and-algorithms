#include<stdio.h>
#include<stdlib.h>
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
int main() {
    SqStack* m = initSqStack();
    pushSqStack(m, 1);
    pushSqStack(m, 2);
    pushSqStack(m, 3);
    pushSqStack(m, 4);
    pushSqStack(m, 5);
    forEachSqStack(m);
    popSqStack(m);
    popSqStack(m);
    forEachSqStack(m);
    readTopSqStack(m);
}