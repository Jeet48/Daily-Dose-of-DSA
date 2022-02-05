#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// A Linked List Node
struct Node
{
    int data;
    Node *next;
 
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
 
// Comparison object to be used to order the min-heap
struct comp
{
    bool operator()(const Node *lhs, const Node *rhs) const {
        return lhs->data > rhs->data;
    }
};
 
// Utility function to print contents of a linked list
void printList(Node* node)
{
    while (node != nullptr)
    {
        cout << node->data << "-->";
        node = node->next;
    }
    cout << "nullptr";
}
 
// The main function to merge given `k` sorted linked lists.
// It takes array `lists` of size `k` and generates the sorted output
Node *mergeKLists(vector<Node*> const &lists)
{
    // create an empty min-heap
    priority_queue<Node*, vector<Node*>, comp> pq;
 
    // push the first node of each list into the min-heap
    for (Node* list: lists) {
        pq.push(list);
    }
 
    // take two pointers, head and tail, where the head points to the first node
    // of the output list and tail points to its last node
    Node *head = nullptr, *last = nullptr;
 
    // run till min-heap is empty
    while (!pq.empty())
    {
        // extract the minimum node from the min-heap
        Node* min = pq.top();
        pq.pop();
 
        // add the minimum node to the output list
        if (head == nullptr) {
            head = last = min;
        }
        else {
            last->next = min;
            last = min;
        }
 
        // take the next node from the "same" list and insert it into the min-heap
        if (min->next != nullptr) {
            pq.push(min->next);
        }
    }
 
    // return head node of the merged list
    return head;
}
 
int main()
{
    int k = 3;    // total number of linked lists
 
    // an array to store the head nodes of the linked lists
    vector<Node*> lists(k);
 
    lists[0] = new Node(1);
    lists[0]->next = new Node(5);
    lists[0]->next->next = new Node(7);
 
    lists[1] = new Node(2);
    lists[1]->next = new Node(3);
    lists[1]->next->next = new Node(6);
    lists[1]->next->next->next = new Node(9);
 
    lists[2] = new Node(4);
    lists[2]->next = new Node(8);
    lists[2]->next->next = new Node(10);
 
    // Merge all lists into one
    Node* head = mergeKLists(lists);
    printList(head);
 
    return 0;
}