/* let's take a linked list1                      1->2->3->4->5->6
   another linked List2                           1->2->3->4->5->6
   then sum be like                              --------------------
                                                  2->4->6->9->1->2
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** node,int data)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->data=data;
	if(*node==NULL){
		*node=temp;
		return;
	}
	struct Node* temp1=*node;
	*node=temp;
	temp->next=temp1;
}
reverse(struct Node** head)
{
	struct Node* t1=(struct Node*)malloc(sizeof(struct Node));
	struct Node* t2=(struct Node*)malloc(sizeof(struct Node));
	struct Node* t3=(struct Node*)malloc(sizeof(struct Node));
	t1=*head;
	t3=NULL;
	while(t1->next!=NULL)
	{

		t2=t1->next;
		t1->next=t3;
		t3=t1;
		t1=t2;
	}
	t1->next=t3;
	*head=t1;
	
}
listPrint(struct Node** node)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));	
	temp=*node;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

int main()
{
	struct Node* head1 = NULL;
    push(&head1, 9);  /* Last node of Linked List */
    push(&head1, 9);
    push(&head1, 9);
    push(&head1, 9);
    push(&head1, 9);
    push(&head1, 9); /* First node of Linked List */
    struct Node* head2 = NULL;
    push(&head2, 9);  /* Last node of Linked List */
    push(&head2, 9);
    push(&head2, 9);
    push(&head2, 9);
    push(&head2, 9);
    push(&head2, 9); /* First node of Linked List */
    
 	printf("%s\n","Linked List : " );
	printf("\t");
    listPrint(&head1);
    printf("\n");
    
    
    printf("\t");
    listPrint(&head2);
    printf("\n");
 	reverse(&head1);
 	reverse(&head2);
  struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
	temp1=head1;    
	struct Node* temp2=(struct Node*)malloc(sizeof(struct Node));
	temp2=head2;
	int sum=0;
	int c=0;
	struct Node* NewNode=NULL;
	while(temp1!=NULL)
	{
		sum+=temp1->data+temp2->data;
		c=sum%10;
		sum=sum/10;
		push(&NewNode,c);
		temp1=temp1->next;
		temp2=temp2->next;
	}
	push(&NewNode,sum);
	//reverse(&NewNode);
	
	printf("---------------------------------------------------------------------------------------------\n");
	listPrint(&NewNode);
    return 0;
}
