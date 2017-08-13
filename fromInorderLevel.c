#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* NewNode(int data)
{
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
int a[100];
struct Node* buildtree(int in[],int level[],int l,int h)
{
	if(l>h)
		return NULL;
	int r=level[0];
	struct Node* root=NewNode(r);
	if(l==h)
		return root;
	int j,i;
	for(j=l;j<=h;j++)
		if(in[j]==r)
			break;
	int k=0,m;
	for(m=l;m<=h;m++)
	{
		for(i=0;i<j;i++)
			if(level[m]==in[i])
				a[k++]=level[m];
	}
	root->left=buildtree(in,a,l,j-1);
	k=0;
	for(m=l;m<=h;m++)
	{
		for(i=j+1;i<=h;i++)
			if(level[m]==in[i])
				a[k++]=level[m];
	}
	root->right=buildtree(in,a,j+1,h);
	return root;
}
void display(struct Node* root)
{
	
	if(root->left)
		display(root->left);
	printf("%d\t",root->data);
	if(root->right)
		display(root->right);
	
}
int main()
{
	int in[]={4, 8, 10, 12, 14, 20, 22};
	int level[]={20, 8, 22, 4, 12, 10, 14};
	
	struct Node* root=buildtree(in,level,0,6);
	display(root);

	return 0;
}