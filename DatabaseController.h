#include <iostream>
#include "BST.h"
#include "GenStack.h"

using namespace std;

class DatabaseController{
public:
  DatabaseController();
  ~DatabaseController();
  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;

  void printStudentinTree(TreeNode<Student> *n);
  void printFacultyinTree(TreeNode<Faculty> *x);
  void addStudent();
  void addFaculty();
  void printStudentInfo(int y);
  void printFacultyInfo(int z);
  void textReader();
  void printStudentWithNode(TreeNode<Student> *s);
  void printFacultyWithNode(TreeNode<Faculty> *f);
  void printStudentFacultyAdvisor(int sd);
  void printFacultyAdvisee(int fd);
  void changeStudentsAdvisor(int newSID, int newFID);
  void removeAdvisee(int facID, int adviseeID);
};
