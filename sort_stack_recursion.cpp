#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 

void sortedInsert(stack<int> &stack, int key)
{
    
    if (stack.empty() || key > stack.top())
    {
        stack.push(key);
        return;
    }
 
    
 
    
    int top = stack.top();
    stack.pop();
 
   
    sortedInsert(stack, key);
 
   
    stack.push(top);
}
 

void sortstack(stack<int> &stack)
{
    
    if (stack.empty()) {
        return;
    }
 
    
    int top = stack.top();
    stack.pop();
 
    
    sortstack(stack);
 
    
    sortedInsert(stack, top);
}
 
void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
 
int main()
{
    vector<int> list = { 5, -2, 9, -7, 3 };
 
    stack<int> stack;
    for (int i: list) {
        stack.push(i);
    }
 
    cout << "Stack before sorting: ";
    printStack(stack);
 
    sortstack(stack);
 
    cout << "Stack after sorting: ";
    printStack(stack);
 
    return 0;
}
