#include<bits/stdc++.h> 
using namespace std; 

int pre(char ch) 
{ 
  if(ch == '^') 
  return 3; 
  else if(ch == '*' || ch == '/') 
  return 2; 
  else if(ch == '+' || ch == '-') 
  return 1; 
  else
  return -1; 
} 

void infixToPostfix(string s) 
{ 
  std::stack<char> st; 
  st.push('N'); 
  int l = s.length(); 
  string ns; 
  for(int i = 0; i < l; i++) 
  { 
     
    if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
    ns+=s[i]; 

      else if(s[i] == '(') 
    
    st.push('('); 
  
    else if(s[i] == ')') 
    { 
      while(st.top() != 'N' && st.top() != '(') 
      { 
        char ch = st.top(); 
        st.pop(); 
      ns += ch; 
      } 
      if(st.top() == '(') 
      { 
        char ch = st.top(); 
        st.pop(); 
      } 
    } 
    
    else{ 
      while(st.top() != 'N' && pre(s[i]) <= pre(st.top())) 
      { 
        char ch = st.top(); 
        st.pop(); 
        ns += ch; 
      } 
      st.push(s[i]); 
    } 

  } 

  while(st.top() != 'N') 
  { 
    char ch = st.top(); 
    st.pop(); 
    ns += ch; 
  } 
  
  cout << ns << endl; 

} 

int main() 
{ 
  string sol;
  cout<<"Enter the string";
  cin>>sol;
  infixToPostfix(sol); 
  return 0; 
} 