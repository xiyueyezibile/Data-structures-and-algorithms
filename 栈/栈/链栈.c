#include<stdio.h>
typedef struct LinkNode {
    int data; //������
    struct LinkNode* next; //ָ����
}*LiStack; //ջ���Ͷ���
LiStack initSqStack() {
    LiStack init = (LiStack)malloc(sizeof(LiStack));
    init->data = 0;
    return init;
}
int main() {
	return 0;
}