#include<stdio.h>
typedef struct LinkNode {
    int data; //数据域
    struct LinkNode* next; //指针域
}*LiStack; //栈类型定义
LiStack initSqStack() {
    LiStack init = (LiStack)malloc(sizeof(LiStack));
    init->data = 0;
    return init;
}
int main() {
	return 0;
}