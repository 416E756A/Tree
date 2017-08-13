/* Constructing a tree from given preorder and post order */

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
int top=-1;
void enqueue(struct Node* node)
{
	queue[rear++]=node;
	top++;
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
void reverse(int a[],int n)
{
	int i;
	for(i=0;i<n/2;i++)
	{
		int t=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=t;
	}
}
int find(int a[],int x,int n)
{
	int i=0;
	for(i=0;i<n;i++)
		if(a[i]==x)
			return i;
	return 0;
}
void create(struct Node** root,int pre[],int post[],int n)
{
	*root=newnode(pre[0]);
	enqueue(*root);
	int i=0;
	while(top!=n-1)
	{
		i++;
		struct Node* temp=dequeue();
		int z=temp->data;
		//printf("%d\n",z);
		int p=find(pre,z,n);
		int q=find(post,z,n);
		//printf("%d\t%d",p,q);
		temp->left=newnode(pre[p+1]);
		temp->right=newnode(post[q+1]);
		enqueue(temp->left);
		enqueue(temp->right);
	}
}
void inorder(struct Node* root)
{
	if(root->left)
		inorder(root->left);
	printf("%d\t",root->data);
	if(root->right)
		inorder(root->right);
}
int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
 	reverse(post,size);
 	struct Node* root=NULL;
    create(&root,pre, post, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    //levelOrder(root);
 	inorder(root);
    return 0;
}
