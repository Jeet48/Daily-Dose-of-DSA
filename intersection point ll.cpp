// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node* next;
};


int getIntesectionNode(Node* head1, Node* head2)
{
	Node* current1 = head1;
	Node* current2 = head2;

	
	if (!current1 or !current2)
		return -1;

	
	while (current1 and current2and current1 != current2) {
		current1 = current1->next;
		current2 = current2->next;

		
		if (current1 == current2)
			return current1->data;

		
		if (!current1)
			current1 = head2;
		if (!current2)
			current2 = head1;
	}

	return current1->data;
}


int main()
{
	

	Node* newNode;

	// Addition of new nodes
	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << getIntesectionNode(head1, head2);

	return 0;
}

