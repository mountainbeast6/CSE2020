#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

// all funtions

void printMagic(const vector<vector<int>>&);
void makeMagic(vector<vector<int>>&);
bool testMagic(vector<vector<int>>&, int&);
int rowSum(int, vector<vector<int>>&);
int colSum(int, vector<vector<int>>&);
int diagDownSum(vector<vector<int>>&);
int diagUpSum(vector<vector<int>>&);

int main(){
  vector<vector<int>> magicSquare={{4,4},{4,4}};
  int x = diagUpSum(magicSquare);
  cout<<x<<'\n';
  x=diagDownSum(magicSquare);
  cout<<x<<'\n';
  // cout<<x;
  // makeMagic(magicSquare);
  printMagic(magicSquare);
  cout<<testMagic(magicSquare, x)<<'\n';
  return 0;
}
void printMagic(const vector<vector<int>>& magic){
  for(int i=0;i<magic.size();i++){
    for(int j=0; j<magic[i].size();j++){
      cout<<magic[i][j]<<" ";
    }
    cout<<'\n';
  }
  return;
}
bool testMagic(vector<vector<int>>& magic, int& x){
  int test=diagUpSum(magic);
  for(int i=0; i<magic.size();i++){
    if(!((rowSum(i, magic)==test)&&(colSum(i, magic)==test))){
      return false;
    }
  }
  if (!(test==diagDownSum(magic))) {
    return false;
  }
  return true;
}
// void makeMagic(vector<vector<int>>& magic){
//
// }
int colSum(int c, vector<vector<int>>& magic){
  int sum=0;
  for(int i =0; i<magic.size(); i++){
    if(magic[i].size()>0){
      sum+=magic[i][c];
    }else{
      return 0;
    }
  }
  return sum;
}
int rowSum(int r, vector<vector<int>>& magic){
  int sum=0;
  if (magic.size()>r){
    for(int i=0; i<magic[r].size();i++){
      sum+=magic[r][i];
    }
  }
  return sum;
}
int diagDownSum(vector<vector<int>>& magic){
  int sum=0;
  for(int i =0; i<magic.size(); i++){
    sum+=magic[i][i];
  }
  return sum;
}
int diagUpSum(vector<vector<int>>& magic){
  int sum=0;
  for(int i =0; i<magic.size(); i++){
    sum+=magic[magic.size()-i-1][i];
  }
  return sum;
}
