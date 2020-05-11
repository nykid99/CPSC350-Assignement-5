// # Cpsc350-Assignment-5
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the TreeNode template class

#include <iostream>

using namespace std;

template <class T>
class TreeNode{
public:
  TreeNode(); //default constructor
  TreeNode(T d,int k); //data and key
  ~TreeNode(); //destructor

  T data;
  int key;
  TreeNode<T> *left;
  TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T d,int k){
  data = d;
  key = k;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete data;
  delete left;
  delete right;
}
