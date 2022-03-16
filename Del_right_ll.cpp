#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void reverseList(struct Node** headref);
void _delLesserNodes(struct Node* head);

void _delLesserNodes(struct Node**head_ref)
{
	reverseList(head_ref);

	_delLesserNodes(*head_ref);

	reverseList(head_ref);
}

void _delLesserNodes(struct Node* head)
{
	struct Node* current=head;

	struct Node* maxnode = head;
	struct Node* temp;

	while(current!=NULL && current->next!=NULL)
	{
		if(current->next->data<maxnode->data)
		{
			temp=current->next;
			current->next=temp->next;
			free(temp);
		}

		else
		{
         current=current->next;
         maxnode=current;
		}
	}
}


void push(struct Node**head_ref, int new_data)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}

void reverseList(struct Node**headref)
{
	struct Node* current = *headref;
	struct Node* prev = NULL;
	struct Node* next;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*headref=prev;
}

void printList(struct Node* head)
{
	while(head!=NULL)
	{
		cout<<" "<<head->data;
		head=head->next;
	}
	cout<<"\n";
}

int main()
{
	struct Node* head = NULL;

	push(&head, 3);
	push(&head, 2);
	push(&head, 6);
	push(&head, 5);
	push(&head, 11);
	push(&head, 10);
	push(&head, 15);
	push(&head, 12);

	cout<<"Given Linked List \n";
	printList(head);

	_delLesserNodes(&head);

	cout<<"Modified Linked List" ;
	printList(head);
	return 0;

}