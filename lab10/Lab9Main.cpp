// Lab10Main.cpp
// KV for CSE 2020 in Spring 2024

#include <iostream>
#include "BinarySearchTreeLab9.h"  // completed version
#include "Random.h"
using namespace std;

int main()
{
	rand_seed();
	BinarySearchTree<int> mybst;
	int how_many;
	cout << "How many random values? ";
	cin >> how_many;
	cout << endl << endl;
	std::vector<int> v;
	int temp;
	int temp2;

	for (int i = 1; i <= how_many; i++)
	{
		temp = rand_int(1, 250);
		if (!(mybst.insert(temp))) {
			i--;
		}
		v.push_back(temp);
	}
	cout << endl << how_many << " values entered" << endl << endl;

	cout << "Here are the current values: " << endl;
	mybst.printElements();
	cout << endl << endl;

	cout << "Here is the structure of the BST: " << endl;
	mybst.printInternal();
	cout << endl << endl;

	cout << "Number of values contained in BST: " << mybst.size();
	cout << endl << endl;

	cout <<"Now removing half of BST: ";
	cout << endl << endl;
	temp = v.size()/2;
	for(int i=0; i<temp; i++){
		temp2 = rand_int(0, v.size());
		cout <<"Now removing " << v[temp2] <<endl;
		mybst.remove(v[temp2]);
		v.erase(v.begin()+temp2);
		// mybst.printInternal();
	}
	cout << endl << endl;
	cout << "Here is the new structure of the BST: " << endl;
	mybst.printInternal();
	cout << endl << endl;

	cout << "Number of values contained in BST: " << mybst.size();
	cout << endl << endl;

	return 0;
}
