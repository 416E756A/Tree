#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* NewNode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	return node;
}
void Inorder(struct node* root)
{
	if(root==NULL)
		return;
	Inorder(root->left);
	printf("%d\t",root->data);
	Inorder(root->right);
}
void Postorder(struct node* root)
{
	if(root==NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d\t",root->data);
}
void preorder(struct node* root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	struct node* root=NewNode(1);
	root->left             = NewNode(2);
     root->right           = NewNode(3);
     root->left->left     = NewNode(4);
     root->left->right   = NewNode(5); 
 
     printf("\nPreorder traversal of binary tree is \n");
     preorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     Inorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     Postorder(root);
     return 0;
 
}