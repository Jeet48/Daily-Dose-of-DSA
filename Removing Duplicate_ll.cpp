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

node *removeDuplicate(node *head){
	node *ptr1 = head;
	node *ptr2 = head;
	while(ptr1 != NULL){
		if(ptr2->data!=ptr1->data){
			ptr2->next = ptr1;
			ptr2 = ptr1;
		}
		else if(ptr1->next==NULL)
		{
			ptr2->next=NULL;
		}
		ptr1 = ptr1->next;
	}
	return head;
}

int main() {
node *head;
cin>>head;
removeDuplicate(head);
cout<<"\n After removing the duplicate elements, the linked list becomes\n";
cout<<head;


return 0;

}
