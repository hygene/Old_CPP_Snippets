#include <iostream>
#include <list>
#include <stack>

using namespace std;

void printList_Reverse(list<int> inList) {
    std::stack<int> nodes;
    list<int>::iterator itList = inList.begin();
    
    cout << "create stack" << endl;
    while(itList != inList.end()) {
        nodes.push(*itList);
        ++itList;
    }
    
    cout << "print stack" << endl;
    int data = 0;
    while(!nodes.empty()) {
        int data = nodes.top();
        cout << data << ", " << endl; 
        nodes.pop();
    }
}

int main()
{
    std::list<int> intList;
    
    cout << "create test set" << endl;
    for(int i=0; i<10; i++) {
        intList.push_back(i);
    }
    
    cout << "call function" << endl;
    printList_Reverse(intList);
   
    return 0;
}