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

    void insert(const T& x)
    {
        // calls private insert ...
        insert(x, root);     // ==> LAB 10: add private fct from Module 6.2
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

private:
    int size =0;
    BinaryNode* root;


    //the private member fcts that do all the work...

    void insert(const T& x, BinaryNode*& t)
    {
        if(t==NULL){
          t= new BinaryNode{x, nullptr, nullptr};
        }
        else if(t->element > x){
          return insert(x, t->right);
        }
        else if(t->element < x){
          return insert(x, t->left);
        }
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
        size=0;
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
        return size; // temp PLACE HOLDER for the actual code
    }

};





#endif
