#ifndef SEARCHING_H_
#define SEARCHING_H_

#include <iostream>
#include "Vector.h"
#include "List.h"
using namespace std;

template <typename T>
int linear_search_V(const Vector<T>& vec, const T& target){
      for(int i=0; i<vec.size(); i++){
        if (vec[i]==target)
          return i;
      }
      return -1;
}

template <typename T>
typename List<T>::const_iterator linear_search_L(const List<T>& lst, const T& target){
      List<T>::const_iterator itr;
      for(itr=lst.begin(); itr!=lst.end();itr++){
        if(*itr==target){
          return itr;
        }
      }
      return lst.end();
}
template <typename T>
int rec_linear_search_V(int i, const Vector<T> vec, const T& target){
  if(vec.empty()|| i>=vec.size())
    return -1;
  if(vec[i]==target)
    return i;
  return rec_linear_search_V(i+1, vec, target);
}
template <typename T>
typename List<T>::const_iterator rec_linear_search_V (typename List<T>::const_iterator itr,const List<T>& lst, const T& target){
  if(itr == lst.end()){
    return lst.end();
  }
  if(*itr==target){
    return itr;
  }
  itr++;
  return(itr, lst, target);
}
#endif
