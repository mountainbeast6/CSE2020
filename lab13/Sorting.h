#ifndef SORTING_H_
#define SORTING_H_
#include "Vector.h"
using namespace std;
template <typename T>
void insertionSort(Vector<T>& a){
  T temp;
  int j;
  for(int p=1; p<a.size(); p++){
    j=p;
    temp=a[j];
    while((j>0)&&(a[j-1]>temp)){
      a[j]=a[j-1];
      j--;
    }
    a[j]=temp;
  }
}
template <typename T>
void selectionSort(Vector<T>& a){
  T temp;
  int tempint;
  for(int i= a.size()-1; i>0; i--){
    temp = a[0];
    tempint =0;
    for(int j=1; j<i; j++){
      if(temp<a[j]){
        temp =a[j];
        tempint =j;
      }
    }
    if(temp>a[i]){
      a[tempint]=a[i];
      a[i]=temp;
    }
  }
}
#endif



// p=2
// j=1
// temp=2
//      4| 5| 2| 3
//      4| 5| 2| 3
//      4| 5| 5| 3
//
//
//
//
