#include <iostream>
#include "TreeNode.h"

using namespace std;

template <class T>
class BST{
public:
  BST();
  ~BST();
  //virtual ~BST() - when working with template classes
  void insert(TreeNode<T> *node); //which in this example is also our key
  bool search(int value); //which in this example is also our key
  bool deleteNode(int k);

  bool isEmpty();
  TreeNode<T>* getMin();
  TreeNode<T>* getMax();

  TreeNode<T>* getSuccessor(TreeNode<T> *d);
  void printTree(TreeNode<T> *node);
// private:
  TreeNode<T> *root;
};
template <class T>
BST<T>::BST(){
  root = NULL;
}
template <class T>
BST<T>::~BST(){
  //as always lets build some character
}
template <class T>
void BST<T>::printTree(TreeNode<T> *node){
  if(node == NULL)
  return;
  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);
}

template <class T>
bool BST<T>::isEmpty(){
  return (root == NULL); // or size = 0
}


template <class T>
void BST<T>::insert(TreeNode<T> *node){
  if(root == NULL){
    //we have an empty tree
    root = node;
  }
  else{
    //tree ain't empty we need to find the location
    TreeNode<T> *curr = root;
    TreeNode<T> *parent; //empty node

    while(true){
      //lets find the insertion point
      parent = curr;

      if(node->key < curr->key){
        //go left
        curr = curr->left;
        if(curr == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        //go right
        curr = curr->right;
        if(curr == NULL){
          //we found the nodes home
          parent->right = node;
          break;
        }
      }
    }
  }
}


template <class T>
bool BST<T>::search(int k){
  if(isEmpty()){
    return false;
  }
  else{
    //tree is not empty
    TreeNode<T> *current = root;

    while(current-> key != k){
      if(k < current->key){
        current = current->right;
      }
      else{
        current = current->right;
      }

      if(current == NULL){
        return false;
      }
    }
    return true;
  }
}


template <class T>
bool BST<T>::deleteNode(int k){
  if(isEmpty()){
    return false;
  }
  else if(!search(k)){
    return false;
  }
  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;

  bool isLeft = true;

  while(current->key != k){
    parent = current;
    if(k < current->key){
      isLeft = true;
      current = current->left;
    }
    else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){
      return false;
    }
  }
  if(current->left == NULL && current->right == NULL){
    if(current == root){
      root = NULL;
    }
    else if(isLeft){
      parent->left = NULL;
    }
    else{
      parent->right = NULL;
    }
  }
  else if(current->right == NULL){
    if(current == root){
      root = current->left;
    }
    else if(isLeft){
      parent->left = current->left;
    }
    else{
      parent->right =current->left;
    }
  }
  else if(current->right == NULL){
    if(current == root){
      root = current->right;
    }
    else if(isLeft){
      parent->left = current->right;
    }
    else{
      parent->right =current->right;
    }
  }
  else{
    TreeNode<T> *successor = getSuccessor(current);
    if(current == root){
      root = successor;
    }
    else if(isLeft){
      parent->left = successor;
    }
    else{
      parent->right = successor;
    }
    successor->left = current->left;

    return true;
  }
}
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}
template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *curr = root; //start at the root
  if(root = NULL){
    return NULL; //tree is empty
  }

  while(curr->right != NULL){
    curr = curr->left;
  }
  return curr; // if tree consisted of a numeric type curr->key or curr->value
}

template <class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T> *curr = root; //start at the root
  if(root = NULL){
    return NULL; //tree is empty
  }

  while(curr->right != NULL){
    curr = curr->right;//getmin is opposite of this
  }
  return curr; // if tree consisted of a numeric type curr->key or curr->value
}
