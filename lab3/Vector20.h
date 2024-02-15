// Still a Simple Basic Vector Data Structure, but
// KV, Feb 2024

#ifndef VECTOR20_H
#define VECTOR20_H

#include <iostream>
#include <cassert>

using namespace std;


template <typename T>
class Vector20
{
public:
	Vector20()
		: theSize{ 0 }, theCapacity{ 20}
	{ data = new T[theCapacity]; }

	Vector20(const Vector20& rhs)
		: theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, data{ nullptr }
	{
		data = new T[theCapacity];
		for (int k = 0; k < theSize; ++k)
			data[k] = rhs.data[k];
	}

	Vector20& operator= (const Vector20& rhs)
	{
		for (int k = 0; k < theSize; ++k)
			data[k] = rhs.data[k];
		return *this;
	}

	~Vector20()
	{
		delete[] data;
	}

	bool empty() const
	{
		return theSize == 0;
	}
	int size() const
	{
		return theSize;
	}

	int capacity() const
	{
		return theCapacity;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < theSize);
		return data[index];
	}

	T& back() const
	{
		return data[theSize - 1];
	}

	T& front() const
	{
		return data[0];
	}
	typedef T* iterator;
	typedef const T* constIterator;
	iterator begin(){
		return &data[0];
	}
	constIterator begin() const{
		return &data[0];
	}
	iterator end(){
		return &data[theSize];
	}
	constIterator end() const{
		return &data[theSize];
	}
	void push_back(const T& x)
	{
		if (theSize < theCapacity)
		{
			//cout << "within capacity ..." << endl;
			data[theSize] = x;
			theSize++;
		}
		else
		{
			//cout << "EXPAND capacity ..." << endl;
			T* moredata = new T[theCapacity * 2 + 1];
			for (int i = 0; i < theSize; ++i)
			{
				moredata[i] = std::move(data[i]);
			}
			std::swap(data, moredata);
			delete[] moredata;
			theCapacity = theCapacity * 2 + 1;

			data[theSize] = x;
			theSize++;
		}
	}
	void pop_back() {
		--theSize;
	}
	void erase(int index)
	{
		assert(index>=0&&index<theSize);
		for (int i = index+1; i < theSize; i++) {
			data[i-1]=data[i];
		}
		pop_back();
		return;
	}

	// to be added in LAB WEEK-4
	// to be written by you
	void insert(int index, int value)
	{
			assert(index>=0&&index<theSize);
			push_back(back());
			int i;
			for(i=theSize-1; i>index; i--){
				data[i]=data[(i-1)];
			}
			data[i]=value;
			return;
	}
	void insert(iterator itr, int value){
		if (itr==end()){
			push_back (value);
			return;
		}
		assert (itr>=begin()&&itr<end());
		push_back(back());
		iterator front = end()-2;
		iterator back = end()-1;
		while(front>=itr){
			*back=*front;
			front--;
			back--;
		}
		*itr=value;
		return;
	}
	void RInsert(int index, int value)
	{
			assert(index>=0&&index<theSize);
			push_back(data[index]);
			data[index]=value;
	}
	void RErase(int index)
	{
			assert(index>=0&&index<theSize);
			data[index]=data[size-1];
			pop_back;
	}
private:
	int theSize;
	int theCapacity;
	T* data;
};

#endif
