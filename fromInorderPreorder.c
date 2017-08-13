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
struct Node* buildtree(int in[],int pre[],int l,int h)
{
	if(l>h)
		return NULL;
	static int i=0;
	int r=pre[i];
	i++;
	struct Node* root=NewNode(r);
	if(l==h)
		return root;
	int j;
	for(j=l;j<=h;j++)
		if(in[j]==r)
			break;
	root->left=buildtree(in,pre,l,j-1);
	root->right=buildtree(in,pre,j+1,h);
	return root;

}
void display(struct Node* root)
{
	
	if(root->left)
		display(root->left);
	if(root->right)
		display(root->right);
	printf("%d\t",root->data);
}
int main()
{
	int in[]={4, 2, 5, 1, 3, 6};
	int pre[]={1, 2, 4, 5, 3, 6};
	
	struct Node* root=buildtree(in,pre,0,5);
	display(root);

	return 0;
}