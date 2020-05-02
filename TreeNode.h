#include <iostream>

using namespace std;

template <class T>
class TreeNode{
public:
  TreeNode();
  TreeNode(T d,int k);
  ~TreeNode();

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
