
#include <iostream>
#include <stack>
using namespace std;
 

 stack<int> s;

void insertAtBottom(int item)
{
    
    if (s.empty())
    {
        s.push(item);
        return;
    }
 
    
    int top = s.top();
    s.pop();
    insertAtBottom(item);
 
    
    s.push(top);
}
 

void reverseStack()
{
    
    if (s.empty()) {
        return;
    }
 
    
    int item = s.top();
    s.pop();
    reverseStack();
 
    
    insertAtBottom(item);
}
 
int main()
{
    stack<int> s;
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    for (int i = 1; i <= n; i++) {
        s.push(i);
    }
 
    reverseStack();
 
    cout << "Reversed stack is ";
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
 
    return 0;
}