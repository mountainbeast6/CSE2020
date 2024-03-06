#include <iostream>
#include "Vector.h"
#include "Stack.h"
using namespace std;
int main(){
  Stack<Vector<int> > myStack;
  for(int i=1; i<=10; i++){
    cout<<"Push Onto Stack: "<<i<<" "<< endl;
    myStack.push(i);
  }
  cout<<endl<<endl;
  cout<< "Popping the stack one element at a time..."<< endl<<endl;
  while(!myStack.empty()){
    int tp = myStack.top();
    cout << tp << " ";
    myStack.pop();
  }
  cout << endl << endl;
  return 0;
}
