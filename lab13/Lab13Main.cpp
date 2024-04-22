#include <iostream>
#include "Sorting.h"  // completed version
#include "Random.h"
using namespace std;

int main()
{
  rand_seed();
  Vector<int> v;
  int how_many;
  cout << "How many random values? ";
  cin >> how_many;
  cout << endl << endl;
  int temp;
  int temp2;
  for (int i=0; i< v.size(); i++){
    cout<< v[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= how_many; i++)
  {
    temp = rand_int(1, 250);
    v.push_back(temp);
  }
  for (int i=0; i< v.size(); i++){
    cout<< v[i] << " ";
  }
  return 0;
}
