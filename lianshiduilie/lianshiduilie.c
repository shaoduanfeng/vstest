#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* CreatNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) return NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct Queue
{
	struct Node* frontNode;
	struct Node* tailNode;
	int size;
};
struct Queue* CreateQueue()
{
	struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
	if (myQueue == NULL) return NULL;
	myQueue->frontNode  = myQueue->tailNode = NULL;
	myQueue->size = 0;
	return myQueue;
}
void push(struct Queue* myQueue,int data)
{
	struct Node* newNode = CreatNode(data);
	if (myQueue->size == 0)
	{
		myQueue->frontNode = myQueue->tailNode = newNode;
	}
	else
	{
		myQueue->tailNode->next = newNode;
		myQueue->tailNode = newNode;
	}
	myQueue->size++;
}
void pop(struct Queue* myQueue)
{
	if (myQueue->size == 0)
	{
		printf("队列为空");
		system("pause");
	}
	else
	{
		struct Node* nextNode = myQueue->frontNode->next;
		free(myQueue->frontNode);
		myQueue->frontNode = nextNode;
		myQueue->size--;
	}
}
int front(struct Queue* myQueue)
{
	if (myQueue->size == 0)
	{
		printf("队列为空，无法获取队头");
		system("pause");
		return myQueue->size;
	}
	return myQueue->frontNode->data;
}
int empty(struct Queue* myQueue)
{
	if (myQueue->size == 0)
		return 0;
	else return 1;
}

int main()
{
	struct Queue* myQueue = CreateQueue();
	push(myQueue, 1);
	push(myQueue, 2);
	push(myQueue, 3);

	while (empty(myQueue))
	{
		printf("%d\t",front(myQueue));
		pop(myQueue);
	}
	printf("\n");

	system("pause");
	return 0;
}