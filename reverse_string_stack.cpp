#include<bits/stdc++.h>
#include<string>
using namespace std;

class Stack
{
public:
	int top;
	int capacity;
	char *arr;
};

Stack *createStack(int capacity)
{
	Stack * stack = new Stack();
	stack->capacity=capacity;
	stack->top=-1;
	stack->arr = new char[(stack->capacity * sizeof(char))];
	return stack;
}

int isFull(Stack *stack)
{ return stack->top==stack->capacity -1;}

int isEmpty(Stack *stack)
{ return stack->top == -1;}

void push(Stack *stack, char item)
{
	if(isFull(stack))
		return;
	stack->arr[++stack->top]=item;
}

char pop(Stack *stack)
{
	if(isEmpty(stack))
		return -1;
	return stack->arr[stack->top--];
}

void reverse(char str[])
{
	int n = strlen(str);
	Stack *stack = createStack(n);

	
	for(int i=0;i<n;i++)
		push(stack, str[i]);


	for(int i=0;i<n;i++)
		str[i] = pop(stack);
}

int main() {
	char str[100];
	cout<<"Enter a string ";
	cin>>str;

	reverse(str);
	cout<<"reversed string is "<<str;

	return 0;
}