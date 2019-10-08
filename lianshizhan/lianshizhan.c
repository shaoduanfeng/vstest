#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) return NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct stack
{
	struct Node* stacktop; //栈顶
	int size; //元素个数
};
//创建栈
struct stack* createStack()
{
	//初始化
	struct stack* mystack = (struct stack*)malloc(sizeof(struct stack));
	if (mystack == NULL) return NULL;
	mystack->stacktop = NULL;
	mystack->size = 0;
	return mystack;
}
//入栈
void push(struct stack* myStack, int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = myStack->stacktop;
	myStack->stacktop = newNode;
	myStack->size++;
}
//获取栈顶元素
int top(struct stack* myStack)
{
	if (myStack->size == 0)
	{
		printf("栈为空");
		system("pause");
		return myStack->size;
	}
	return myStack->stacktop->data;
}
//出栈
void pop(struct stack* myStack)
{
	if (myStack->size == 0)
	{
		printf("栈为空,无法出栈");
		system("pause");
	}
	else
	{
		struct Node* nextNode = myStack->stacktop->next;
		free(myStack->stacktop);
		myStack->stacktop = nextNode;
		myStack->size--;
	}
}
int empty(struct stack* myStack)
{
	if (myStack->size == 0)
		return 0;
	return 1;
}

int main()
{
	struct stack* mystack = createStack();
	push(mystack, 1);
	push(mystack, 2);
	push(mystack, 3);
	while (empty(mystack))
	{
		printf("%d\t", top(mystack));
		pop(mystack);
	}
	printf("\n");
	system("pause");
	return 0;
}