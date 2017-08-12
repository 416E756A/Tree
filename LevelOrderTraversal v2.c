#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* newnode(int data)
{
	struct Node* root=(struct Node*)malloc(sizeof(struct Node));
	root->left=NULL;
	root->right=NULL;
	root->data=data;
	return root;
}

struct Node* queue[100];
int rear=0;
int front=-1;
void enqueue(struct Node* node)
{
	queue[rear++]=node;
}
struct Node* dequeue()
{
	return queue[++front];
}
void levelOrder(struct Node* root)
{
	struct Node* temp=root;
	while(temp)
	{
		printf("%d\t",temp->data);
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
		temp=dequeue();
	}
}
int main()
{
	struct Node* root=newnode(2);
	root->left             = newnode(3);
    root->right           = newnode(4);
    root->left->left     = newnode(7);
    root->left->left->left   = newnode(1);

    levelOrder(root);
    return 0;
}