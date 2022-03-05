#include<iostream>
using namespace std;

class Node
{
public:
	char data;
	Node *next;
	Node *pre;

	Node(int data)
	{
		this->data = data;
		pre = NULL;
		next = NULL;

	}
};

void insertAtHead(Node* &head, int data)
{
	Node* n = new Node(data);
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head->pre=n;
	head=n;
	return;
}

void insertAtTail(Node* &head,int data)
{
	if(head==NULL)
	{
		insertAtHead(head,data);
		return;
	}
	Node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node* n = new Node(data);
	temp->next=n;
	n->pre=temp;
	return;
}

void display(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL\n";
}

void rotateByN(Node *&head,int pos)
{
	if(pos==0)
		return;
	Node *cur = head;

	while(pos)
	{
		cur = cur->next;
		pos--;
	}

	Node *tail = cur->pre;
	Node *NewHead = cur;
	tail->next = NULL;
	cur->pre = NULL;

	while(cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->next = head;
	head->pre = cur;
	head = NewHead;
}


int main()
{
	Node *head = NULL;
	insertAtTail(head,'a');
	insertAtTail(head,'b');
	insertAtTail(head,'c');
	insertAtTail(head,'d');
	insertAtTail(head,'e');

	int n;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"\nBefore rotation :\n";
	display(head);
	rotateByN(head,n);
	cout<<"\nAfter rotation\n";
	display(head);

	return 0;
}