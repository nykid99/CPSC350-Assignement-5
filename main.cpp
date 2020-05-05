#include <iostream>
#include "DatabaseController.h"
using namespace std;

int main(int argc, char const *argv[]) {
  //for testing BST Functions
  // BST<int> *bst = new BST<int>();
  // TreeNode<int> *x= new TreeNode<int>(0, 3542);
  // TreeNode<int> *y= new TreeNode<int>(4, 5356);
  // TreeNode<int> *z= new TreeNode<int>(1, 4264);
  // TreeNode<int> *q= new TreeNode<int>(2, 2228);
  // TreeNode<int> *tester = new TreeNode<int>();
  // bst->insert(x);
  // bst->insert(y);
  // bst->insert(z);
  // bst->insert(q);
  // cout << bst->deleteNode(2228) << endl;
  // bst->printTree(bst->root);


  // for testing DatabaseController
  // DatabaseController d1;
  // d1.addFaculty();
  // int x;
  // cout << "Enter id number" << endl;
  // cin >> x;
  // d1.printFacultyInfo(x);

  // DoubleGenList<int> *dll = new DoubleGenList<int>();
  // dll->insertBack(1);
  // dll->insertBack(2);
  // dll->insertBack(3);
  // dll->insertBack(4);
  // dll->removeAtpos(3);
  //
  // dll->printList();



  // TreeNode<Faculty> *tempFacN = new TreeNode<Faculty>();
  // TreeNode<Student> *tempFaN = new TreeNode<Student>();
  // tempFaN = d1->masterStudent.returnData(2325383);
  DatabaseController *d1 = new DatabaseController();
  d1->textReader();
  //actual main
  int startflag = 1;
  int userInput;
  cout << "Welcome to the Student Database Program" << endl;
  cout << "Here are your options" << endl;
  while(startflag == 1){
    cout << "1. Print all students and their information" << endl; //need to sort
    cout << "2. Print all students and their information" << endl; // need to sort
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new Faculty member" << endl;
    cout << "10. Delete a faculty member given the id" << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cin >> userInput;
    if(userInput == 1){
      d1->printStudentinTree(d1->masterStudent.root);
    }
    else if(userInput == 2){
    }
    else if(userInput == 3){
    }
    else if(userInput == 4){
    }
    else if(userInput == 5){
    }
    else if(userInput == 6){
    }
    else if(userInput == 7){
    }
    else if(userInput == 8){
    }
    else if(userInput == 9){
    }
    else if(userInput == 10){
    }
    else if(userInput == 11){
    }
    else if(userInput == 12){
    }
    else if(userInput == 13){
    }
    else if(userInput == 14){
      cout << "Exiting Program" << endl;
      exit(0);
    }
    else{
      cout << "Invalid input, Please try again" << endl;
    }
  }
  return 0;
}
