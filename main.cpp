#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char const *argv[]) {
  BST<int> *bst = new BST<int>();
  TreeNode<int> *x= new TreeNode<int>(0, 3542);
  TreeNode<int> *y= new TreeNode<int>(4, 5356);
  TreeNode<int> *z= new TreeNode<int>(1, 4264);
  TreeNode<int> *q= new TreeNode<int>(2, 2228);
  TreeNode<int> *tester = new TreeNode<int>();
  bst->insert(x);
  bst->insert(y);
  bst->insert(z);
  bst->insert(q);
  cout << bst->deleteNode(2228) << endl;
  bst->printTree(bst->root);
  return 0;
}
