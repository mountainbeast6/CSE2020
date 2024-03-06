#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class List{
private:
  struct Node{
    T data;
    Node *prev;
    Node *next;
    Node (const T & d =T{},Node * p = nullptr,
          Node * n =nullptr)
          :data{d}, prev{p},next{n}{}
  };
  class const_iterator{

  };
  class iterator{
  public:
    iterator()
    :current(nullptr)
    {}
    iterator(Node* p)
    :current(p){}
    T & operator* (){
      return current->data;
    }

  };
public:
  List(){
      init();
    }
  List(List&& rhs):size{rhs.size},head{rhs.head},tail{rhs.tail}{
    rhs.size=0;
    rhs.head =nullptr;
    rhs.tail=nullptr;
  }
  List& operator= (List&& rhs){
    std::swap(size, rhs.size);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);

    return  *this;
  }
  bool empty(){
    if(size>0){
      return false;
    }
    return true;
  }
  iterator remove(iterator itr){
    Node *p = itr.current;
    iterator retValue(p->next);
    p->next->prev = p->prev;
    p->prev->next= p->next;
    delete p;
    --size;
    return retValue;
  }
  iterator insert(iterator itr, const T & x){
    Node *p = itr.current;
    ++size;
    return iterator(p->prev=p->prev->next=new Node{x, p.prev, p});
  }
  void push_front(const T & x){
    insert(head->next, x);
  }
  // void push_back(const T & x){
  //   insert(end(), x);
  // }
  // void popFront(){
  //   erase (begin());
  // }
  // void popBack(){
  //   erase (end());
  // }
  // void clear(){
  //   while (!empty()) {
  //     popFront();
  //   }
private:
  int size;
  Node * head;
  Node * tail;
  void init(){
    size =0;
    head = nullptr;
    tail = nullptr;
  }
};
