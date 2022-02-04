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

// node* addOneRec(node* head , int &carry)
// {
//     if(head == NULL)
//     {
//         return NULL;
//         carry = 0;
//     }

//     addOneRec(head->next , carry);
//     int sum = head -> data + carry;
//     carry = sum/10;
//     sum = sum%10;
//     head -> data = sum;
// }

   
//    node* addOne(node *head) 
//    {
       
//        int carry = 1;
//        addOneRec(head , carry);
//        node * newHead = head;
//        if(carry!=0)
//        {
//        newHead = new node(carry);
//        newHead -> next = head;
//        return newHead;
//        }
//        else 
//        return head;
//    }

// node* addOne(node *head) 
//    {
//        if(head->next==NULL){
//            head->data +=1;
//            return head;
//        }
       
//        node *sum=addOne(head->next);
//        head->data+=(sum->data/10);
//        sum->data=sum->data%10;
//        return head;
       
//    }

node* reverse(node *head)
{
       node *p = NULL, 
       *c = head, 
       *n = head->next;
       while(c!=NULL){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL) n = n->next;
       }
       return p;
}
node* addOne(node *head) 
{
       head = reverse(head);
       node *temp = head;

       while(temp!=NULL){
            //99999..... case
            if(temp->next==NULL and temp->data==9)
            {
                temp->data = 1;
                node * zeroNode = new node(0);
                zeroNode->next = head;
                head = zeroNode;
                temp = temp->next;
            }
            else if(temp->data==9){
                //9 case
                temp->data = 0;
                temp = temp->next;
            }
            else{
                //other all cases
                temp->data++;
                temp = temp->next;
                break;
            }
        }
        head = reverse(head);
        return head;
    }

int main() {
node *head;
cin>>head;
addOne(head);
cout<<head;


return 0;

}