#include <iostream>
#include "Vector.h"
#include "Stack.h"
using namespace std;
int main(){
  Stack<Vector<int> > myStack;
  bool cont = true;
  string exp;
  string resp;
  while (cont = true){

    cout <<"Enter An Expression To Check For Matching Brackets: ";
    std::cin >> exp;

    for(int i=0; i<exp.length(); i++){
      if(*exp.at(i)=="{"||*exp.at(i)=="["||*exp.at(i)=="("||*exp.at(i)=="<"){
        myStack.push(*exp.at(i));
      } else if (*exp.at(i)==">"||*exp.at(i)==")"||*exp.at(i)=="]"||*exp.at(i)=="}"){
        if(*exp.at(i)== myStack.top()){
          myStack.pop();
        }
        else{
          cout<<"Doesnt Match!";
          break;
        }
      }
    }

    cout<< "Do you want to continue? (y/n): ";
    std::cin >> resp;
    if(resp!="y"){
      cont = false;
    }
    else{
      myStack.clear();
    }
  }
}
