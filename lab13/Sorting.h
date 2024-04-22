#ifndef SORTING_H_
#define SORTING_H_
#include "Vector.h"
using namespace std;
template <typename T>
void insertionSort(Vector<T>& a){
  T temp;
  int j;
  for(int p=1; p<a.size; p++){
    j=p;
    temp=a[j];
    for(; (j>0)&&(a[j-1]>a[j]); j--){
      a[j]=a[j-1];
    }
    a[j]=temp;
  }
}
void selectionSort(Vector<T>& a){

}
#endif
