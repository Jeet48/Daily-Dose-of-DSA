

#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int d){
		data = d;
		next = NULL;
	}

};

node* newNode(int data)
{
    node* temp = new node(data);
    temp->data = data;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
// Function to detect first node of loop
// in a linked list that may contain loop
node* detectLoop(node* head)
{
 
    // Create a temporary node
    node* temp ;
    while (head != NULL) {
 
        // This condition is for the case
        // when there is no loop
        if (head->next == NULL) {
            return NULL;
        }
 
        // Check if next is already
        // pointing to temp
        if (head->next == temp) {
            break;
        }
 
        // Store the pointer to the next node
        // in order to get to it in the next step
        node* nex = head->next;
 
        // Make next point to temp
        head->next = temp;
 
        // Get to the next node in the list
        head = nex;
    }
 
    return head;
}
 
/* Driver program to test above function*/
int main()
{
    node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    node* res = detectLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->data;
 
    return 0;
}