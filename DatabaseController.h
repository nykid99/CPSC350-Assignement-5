#include <iostream>
#include "BST.h"
#include "GenStack.h"
#include "vector"
#include "algorithm"

using namespace std;

class DatabaseController{
public:
  DatabaseController();
  ~DatabaseController();
  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;
  vector <int> arrayVector;
  vector <int> farrayVector;
  void printStudentinTree(TreeNode<Student> *n);
  void printFacultyinTree(TreeNode<Faculty> *x);
  void printSortedStudent();
  void printSortedFaculty();
  void addStudent();
  void addFaculty();
  void printStudentInfo(int y);
  void printFacultyInfo(int g);
  void textReader();
  void textWriter();
  void removeStudent(int dSID);
  void removeFaculty(int dFID);
  void printStudentWithNode(TreeNode<Student> *s);
  void printFacultyWithNode(TreeNode<Faculty> *f);
  void printStudentFacultyAdvisor(int sd);
  void printFacultyAdvisee(int fd);
  void changeStudentsAdvisor(int newSID, int newFID);
  void removeAdvisee(int facID, int adviseeID);
  int returnStudentAdvisorID(int cid);
};
