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

void insertAtHead(node*&head,int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}
void insertAtTail(node *&head,int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}
int length(node *head){
    int cnt = 0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
void insertAtMiddle(node*&head,int data,int p){
    if(head == NULL || p == 0){
        insertAtHead(head,data);
        return;
    }
    else if(p>length(head)){
       insertAtTail(head,data);
    }
    else{
        int jump=1;
        node*temp=head;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
        }
        node *n = new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}
void print(node*&head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}

node* take_input() {
    int d;
    cin>>d;

    node*head=NULL;

    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;
    }
    return head;
}

ostream& operator<<(ostream &os, node*&head){
    print(head);
    return os;
}

istream& operator>>(istream &is,node*&head){
    head = take_input();
    return is;
}

node *detectLoop(node *head){
	node *temp ;
	while(head != NULL) {
		if(head->next == NULL ) {
			return NULL;
		}
        
        if(head->next==temp){
        	break;
        }

        node *nex = head->next;

        head->next = temp;

        head = nex;

	}
	return head;
}


void deletNode(node*head){
    if(head==NULL){
        return;
    }
    node *temp=head->next;
    delete head;
    head=temp;
}


node *removeDuplicate(node *head){
	unordered_set<int> s;

    node *p = head;
    while(p->next){
        s.insert(p->data);
        if(s.find(p->next->data) != s.end()) p->next = p->next->next;
        else p = p->next;
    }
    return head;
}

void moveToFront(node **head)
{
    if((*head==NULL) || ((*head)->next==NULL)){
        return ;
    }
    node *seclast = NULL;
    node *last = *head;

    while(last->next != NULL)
    {
        seclast = last;
        last = last->next;
    }

    seclast->next = NULL;

    last->next = *head;

    *head = last;
}

int main() {
node *head;
cin>>head;
moveToFront(&head);
cout<<"\n After removing the duplicate elements, the linked list becomes\n";
cout<<head;


return 0;

}