#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 //����ջ��Ԫ�ص�������
typedef struct SqStack {
    int data[MaxSize]; //���ջ�е�Ԫ��
    int top; //ջ��ָ��
}SqStack;
// ջ�ĳ�ʼ��
SqStack* initSqStack() {
    SqStack* init = (SqStack*)malloc(sizeof(SqStack));
    init->top = -1;
    return init;
}
// �п�
int EmptySqStack(SqStack* p) {
    if (p->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
// ��ջ
void pushSqStack(SqStack* p,int x) {
    if (p->top == MaxSize - 1) {
        return;
    }
    p->top += 1;
    p->data[p->top] = x;
}
// ��ջ
void popSqStack(SqStack* p) {
    if (!EmptySqStack(p)) {
        p->top -= 1;
    }
}
// ��ȡջ��Ԫ��
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