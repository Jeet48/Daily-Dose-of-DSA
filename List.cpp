#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;


int main() {
	list<int> l;

	list<int> l1{100,673,238,981,392,535,721};
	list<string> l2{"apple","mango","guava","watermellon"};
	l2.push_back("pineapple");
    l1.sort();
    

    for(auto s:l2)
	{
		std::cout<<s<<"-->";
	}
    cout<<endl;


    for(auto it = l1.begin(); it!=l1.end(); it++){
    	cout<<(*it)<<"-->";
    }
    cout<<endl;


    l2.reverse();
    cout<<l2.front()<<endl;
    l2.pop_front();
    l2.push_front("Kiwi");
    // cout<<l2.back();
    l2.pop_back();
     

   for(auto it1 = l2.begin(); it1!=l2.end(); it1++){
    	cout<<(*it1)<<"-->";
    }
    cout<<endl;


	

	return 0;
}