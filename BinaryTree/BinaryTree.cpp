#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{
	TElemType  data;
	struct BiTNode  *lchild, *rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *T)
{
	TElemType ch;
	cin >> ch;
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T) exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

void visit(TElemType e)
{
	cout << e << " ";
}

//层数
void visit_dep(TElemType e, int level)
{
	cout << e << "在第" << level << "层" << endl;
}

//先序
void PreOrderTraverse(BiTree T, int level)
{
	if (T == NULL) return;
	visit(T->data);
	//visit_dep(T->data, level);
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
}

//中序
void MidOrderTraverse(BiTree T, int level)
{
	if (T == NULL) return;
	PreOrderTraverse(T->lchild, level + 1);
	visit(T->data);
	//visit_dep(T->data, level);
	PreOrderTraverse(T->rchild, level + 1);
}
//后序
void PostOrderTraverse(BiTree T, int level)
{
	if (T == NULL) return;
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
	visit(T->data);
	//visit_dep(T->data, level);
}

int main()
{
	int level = 1;
	BiTree T = NULL;
	cout << "以先序遍历的方式输入二叉树：" << endl;
	CreateBiTree(&T);

	cout << "递归先序遍历输出：" << endl;
	PreOrderTraverse(T, level);
	cout << endl;

	cout << "递归中序遍历输出：" << endl;
	MidOrderTraverse(T, level);
	cout << endl;

	cout << "递归后序遍历输出：" << endl;
	PostOrderTraverse(T, level);
	cout << endl;

	cout << endl;
	return 0;
}