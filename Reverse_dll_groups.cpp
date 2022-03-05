
#include <bits/stdc++.h>

using namespace std;


struct Node {
	int data;
	Node *next, *prev;
};


Node* getNode(int data)
{
	// allocate space
	Node* new_node = (Node*)malloc(sizeof(Node));

	// put in the data
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	return new_node;
}


void push(Node** head_ref, Node* new_node)
{

	new_node->prev = NULL;

	
	new_node->next = (*head_ref);

	
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	
	(*head_ref) = new_node;
}

Node* revListInGroupOfGivenSize(Node* head, int k)
{
	Node *current = head;
	Node* next = NULL;
	Node* newHead = NULL;
	int count = 0;
	
	
	while (current != NULL && count < k)
	{
		next = current->next;
		push(&newHead, current);
		current = next;
		count++;
	}
	
	
	if (next != NULL)
	{
		head->next = revListInGroupOfGivenSize(next, k);
		head->next->prev = head;
	}
	
	
	newHead->prev = NULL;
	return newHead;
}


void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	// Start with the empty list
	Node* head = NULL;

	// Create doubly linked: 10<->8<->4<->2
	push(&head, getNode(2));
	push(&head, getNode(4));
	push(&head, getNode(8));
	push(&head, getNode(10));
	
	int k = 2;

	cout << "Original list: ";
	printList(head);

	// Reverse doubly linked list in groups of
	// size 'k'
	head = revListInGroupOfGivenSize(head, k);

	cout << "\nModified list: ";
	printList(head);

	return 0;
}
