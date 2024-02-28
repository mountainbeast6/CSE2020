// Vector20Main.cpp
// by KV for CSE 2020, Lab4 Feb 2024

#include <iostream>
#include <iomanip>
#include "Vector20.h"
using namespace std;

// printing values in a Vector20 object
void print_Vector20(Vector20<int>);

int main()
{
	Vector20<int> myvec;

	for (int i = 1; i <= 25; i++)
	{
		myvec.push_back(i*11); // entering 25 values into myvec;
	}

	print_Vector20(myvec);  // showing contents of myvec

	// asking for target index and how many times an erase is to happen
	// at this index;

	int target;
	int howmany;
	Vector20<int>::iterator itr;
	cout << "Enter index of element to erase [0 - " << myvec.size() - 1 << "]: ";
	cin >> target;
	cout << endl;
	cout << "Erase at this index how many times [0 - " << myvec.size() - target << "]: ";
	cin >> howmany;
	cout << endl;
	for (int i = 1; i <= howmany; ++i)
	{
		myvec.erase(target);
		print_Vector20(myvec);
		cout << endl;
	}
	cout << "Enter index of element to insert 99 [0 - " << myvec.size() - 1 << "]: ";
	cin >> target;
	cout << endl;
	cout << endl;
	cout << "insert at this index how many times [0 - " << myvec.size() - target << "]: ";
	cin >> howmany;
	cout << endl;
	for (int i = 1; i <= howmany; ++i)
	{
		myvec.insert(target, 99);
		print_Vector20(myvec);
		cout << endl;
	}
	cout <<"How many positions to move the iterator?";
	int moves;
	cin>>moves;
	cout<<endl;
	itr=myvec.begin();
	for(int i=0; i<moves; i++){
		itr++;
	}
	cout<<"What do you want at this position?";
	cin>>target;
	cout<<endl<<endl;
	myvec.insert(itr,target);
	print_Vector20(myvec);
	cout<<endl;
	cout<<"Adding 3 random numbers at 3 random indecies: "<<endl;
	for(int i =0; i<=2; i++){
		myvec.insert(rand()%myvec.size(), rand()%100);
	}
	print_Vector20(myvec);
	cout<<"Removing First, Middle, Last With Iterator."<<endl;
	int begin;
	int middle;
	int end;
	itr=myvec.begin();
	begin = *itr;
	myvec.erase(itr);
	cout<<begin<<endl;
	int j=0;
	itr=myvec.begin();
	while(itr!=myvec.end()){
		itr++;
		j++;
	}
	itr--;
	end = *itr;
	myvec.erase(itr);
	cout<<end<<endl;
	for(int i=0; i<j/2; i++){
		itr--;
	}
	middle = *itr;
	myvec.erase(itr);
	cout<<middle<<endl;
	print_Vector20(myvec);
	return 0;
}

	void print_Vector20(Vector20<int> vec)
	{
		Vector20<int>::iterator itr;
		for (itr=vec.begin(); itr!=vec.end(); itr++)
			cout << *itr << " ";
		cout << endl << endl;
	}
