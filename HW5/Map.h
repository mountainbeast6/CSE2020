#ifndef MYMAP_H_
#define MYMAP_H_

#include "Map_Set.h"
#include "Pair.h"

using namespace std;

template <typename K, typename V>
class Map
{
public:
	Map() {}

	void printMap()
	{
		typename Set<Pair<K, V> >::iterator itr =
			themap.begin();
		for (; itr != themap.end(); ++itr)
		{
			cout << (*itr).first << ":"
				<< (*itr).second << endl;
		}
		return;
	}


	V& operator [](K index)
	{
		typename Set<Pair<K, V> >::iterator here;
		Pair<K, V> probe(index, V());
		here = themap.insert(probe);
		return (*here).second;   // *itr must again return BY REFERENCE
	}
	void remove(K key)
	{
		Pair<K, V> probe;
		probe.first = key;
		themap.remove(probe);
		return;
	}

	Set<K> keys()
	{
		Set<K> thekeys;
		
		typename Set<Pair<K, V> >::iterator itr = themap.begin();
		for (; itr != themap.end(); ++itr)
			thekeys.insert((*itr).first);
		return thekeys;
	}

	Set<V> values()
	{
		Set<V> thevalues;
		typename Set<Pair<K, V> >::iterator itr = themap.begin();
		for (; itr != themap.end(); ++itr)
			thevalues.insert((*itr).second);
		return thevalues;
	}

	bool isEmpty() const
	{
		return themap.isEmpty();
	}

private:

	Set<Pair<K, V> > themap;
};

#endif