/* Printing a tree in Level Order but in reverseway.
                        
                                  1
                                /   \
                               2      3
                              / \    / \
                             4   5  6   7
Output Will be Like this ::  4  5 6 7 2 3 1
*/

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
struct Node* queue[100];
int stack[100];
int top=-1;
int rear=0;
int front =0;
void enqueue(struct Node* root)
{
    queue[rear]=root;
    rear++;
}
struct Node* Dequeue()
{
    struct Node* root =queue[front];
    front++;
    return root;
}
void push(int data)
{
    int i;
    for(i=top;i>=0;i--)
        stack[i+1]=stack[i];
    stack[0]=data;
    top++;
}
int isEmpty()
{
    return rear==front;
}
int pop()
{
    int i;
    int root=stack[0];
    for(i=0;i<top;i++)
        stack[i]=stack[i+1];
    top--;
    return root;
}
void LevelOrder(struct Node* root)
{
    enqueue(root);
    while(!isEmpty())
    {
        //printf("Anuj\t top=%d\n",top);
        struct Node* temp=Dequeue();
        push(temp->data);
        
        if(temp->right)
            enqueue(temp->right);
        if(temp->left)
            enqueue(temp->left);
    }
    while(top!=-1)
        printf("%d\t",pop());
}
int main()
{
    struct Node *root = NewNode(1);
    root->left        = NewNode(2);
    root->right       = NewNode(3);
    root->left->left  = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left  = NewNode(6);
    root->right->right = NewNode(7);
 
    //cout << "Level Order traversal of binary tree is \n";
    LevelOrder(root);
}
