#include <iostream>
#include "Sorting.h"  // completed version
#include "Random.h"
using namespace std;

int main()
{
  rand_seed();
  Vector<int> v;
  int how_many;
  cout << "How many random values for insertion sort? ";
  cin >> how_many;
  cout << endl;
  int temp;
  for (int i = 1; i <= how_many; i++){
    temp = rand_int(1, 250);
    v.push_back(temp);
  }
  for (int i=0; i< v.size(); i++){
      cout<< v[i] << " ";
    }
    cout<<endl;
    cout<< endl << "sorted into: "<< endl;
  insertionSort(v);
  for (int i=0; i< v.size(); i++){
    cout<< v[i] << " ";
  }
  cout<<endl;

  cout << "How many random values for selection sort? ";
  cin >> how_many;
  cout << endl;
  v.clear();
  for (int i = 1; i <= how_many; i++)
  {
    temp = rand_int(1, 250);
    v.push_back(temp);
  }
  for (int i=0; i< v.size(); i++){
    cout<< v[i] << " ";
  }
  cout<<endl;
  cout<< endl << "sorted into: "<< endl;
  selectionSort(v);
  for (int i=0; i< v.size(); i++){
    cout<< v[i] << " ";
  }
  cout<<endl;
  return 0;
}
