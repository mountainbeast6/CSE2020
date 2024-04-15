// PARTIAL implementation of BinarySearchTree
// insert and printing only
// version for Lab9, 2024 ... to be completed

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cassert>
#include "Vector.h"
using namespace std;


template <typename T>
class BinarySearchTree
{
private:
    struct BinaryNode
    {
        T element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(theElement), left(lt), right(rt)
        {}

        BinaryNode(const T&& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(std::move(theElement)), left(lt), right(rt)
        {}
    };

public:

    BinarySearchTree() : root(0) {}

    ~BinarySearchTree()
    {
        makeEmpty();
    }

    bool isEmpty() const
    {
        return root == 0;
    }
    const T & findMin(){
      assert(!isEmpty());
      return findMin(root)->element;
    }
    bool insert(const T& x)
    {
        // calls private insert ...
        return insert(x, root);     // ==> LAB 10: add private fct from Module 6.2
    }

    // LAB 10: print all elements (values) in line

    void printElements() const
    {
        if (isEmpty())
            cout << "Empty tree" << endl;
        else
            printElements(root);  // => LAB 10: define private fct below
    }

    // LAB 10: returns number of elements in BST

    int size() const
    {
        return size(root);  // LAB 10: define private fct below
    }

    void printInternal() const
    {
        if (isEmpty())
            cout << "Empty tree" << endl;
        else
            printInternal(root, 0);
    }

    // for destructor to call...
    void makeEmpty()
    {
        makeEmpty(root);
    }
    void remove(const T & x){
      remove(x, root);
    }
private:
    int big =0;
    BinaryNode* root;


    //the private member fcts that do all the work...

    bool insert(const T& x, BinaryNode*& t)
    {
        if(t==nullptr){
          t= new BinaryNode{x, nullptr, nullptr};
          return true;
        }
        else if(t->element > x){
          return insert(x, t->right);
        }
        else if(t->element < x){
          return insert(x, t->left);
        }
        return false;
    }
    BinaryNode * findMin(BinaryNode *t) const{
      if(t==0){
        return 0;
      }
      if(t->left==0){
        return t;
      }
      return findMin(t->left);
    }
    void makeEmpty(BinaryNode*& t)
    {
        if (t != 0)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = 0;
    }
    void remove(const T& x, BinaryNode*& t){

      int asdf=0;
      // std::cin >> asdf;
      if(t->element==0){
        // cout<<"1"<<endl;
        return;
      }
      if(x > t->element){
        // cout<<"2: Current Value = "<<t->element<<"-- Target = "<< x <<endl;
        remove(x, t->left);
        return;
      }
      else if(t->element > x) {
        // cout<<"3: Current Value = "<<t->element<<"-- Target = "<< x <<endl;
        remove(x, t->right);
        return;
      }
      else{
        if(!(t->right ==nullptr)){
          // cout<<"4: Current Value = "<<t->element<<"-- Target = "<< x <<endl;
          // std::cin >> asdf;
          t->element=findMin(t->right)->element;
          remove(t->element, t->right);
          return;

        }
        else{
         if (!(t->left==nullptr)){
           // std::cout << "5" << '\n';
           t=t->left;
           return;
        }
        else{
          t=nullptr;
          return;
        }
      }
      }
    }
    void printInternal(BinaryNode* t, int offset) const
    {
        for (int i = 1; i <= offset; i++)
            cout << "..";
        if (t == 0)
        {
            cout << "#" << endl;
            return;
        }
        cout << t->element << endl;
        printInternal(t->left, offset + 1);
        printInternal(t->right, offset + 1);
        return;
    }

    // LAB 10: COMPLETE; to print in-line all elements in BST rooted in t;

    void printElements(BinaryNode* t) const
    {
        if (t != 0)
        {

            if(t->left  !=nullptr)
              printElements(t->left);

            cout<<t->element<<endl;

            if(t->right!=nullptr)
              printElements(t->right);



        }
    }


    // LAB 10: COMPLETE; returns the number of elements  stored in BST
    //         rooted in t;

    int size(BinaryNode* t) const
    {
        int yeet=0;
        if(t->left!=nullptr){
          yeet +=size(t->left);
        }
        if(t->right!=nullptr){
          yeet +=size(t->right);
        }
        yeet+=1;
        return yeet;
    }

};





#endif
