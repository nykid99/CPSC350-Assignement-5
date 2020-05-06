#include <iostream>
#include "DatabaseController.h"
using namespace std;

int main(int argc, char const *argv[]) {
  DatabaseController *d1 = new DatabaseController();
  d1->textReader();
  int startflag = 1;
  int userInput;
  cout << "Welcome to the Student Database Program" << endl;
  cout << "Here are your options" << endl;
  while(startflag == 1){
    cout << "1. Print all students and their information" << endl; //need to sort
    cout << "2. Print all Faculty members and their information" << endl; // need to sort
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
      d1->printFacultyinTree(d1->masterFaculty.root);
    }
    else if(userInput == 3){
      int sidNum;
      cout << "please enter the id number of the student:";
      cin >> sidNum;
      cout << endl;
      d1->printStudentInfo(sidNum);
    }
    else if(userInput == 4){
      int fidNum;
      cout << "please enter the id number of the Faculty:";
      cin >> fidNum;
      cout << endl;
      d1->printFacultyInfo(fidNum);
    }
    else if(userInput == 5){
      int sidNum;
      cout << "Please enter the id number of the student:";
      cin >> sidNum;
      cout << endl;
      d1->printStudentFacultyAdvisor(sidNum);
    }
    else if(userInput == 6){
      int fidNum;
      cout << "Please enter the id number of the Faculty:";
      cin >> fidNum;
      cout << endl;
      d1->printFacultyAdvisee(fidNum);
    }
    else if(userInput == 7){
      cout << "Adding new student" << endl;
      d1->addStudent();
    }
    else if(userInput == 8){
      int ddsid;
      cout << "Enter the ID number of the student you would like to delete: ";
      cin >> ddsid;
      cout << endl;
      d1->removeStudent(ddsid);
      cout << "Student successfully removed" << endl;
    }
    else if(userInput == 9){
      cout << "Adding new Faculty" << endl;
      d1->addFaculty();
    }
    else if(userInput == 10){
      int ddfid;
      cout << "Enter the ID number of the Faculty member you would like to delete: ";
      cin >> ddfid;
      cout << endl;
      d1->removeFaculty(ddfid);
      cout << "Faculty member successfully removed" << endl;
    }
    else if(userInput == 11){
      int newfidNum;
      int sidNum;
      cout << "Enter the id number of the student:";
      cin >> sidNum;
      cout << endl;
      cout << "Enter the id number of the new faculty member who will be replacing the student's previous advisor:";
      cin >> newfidNum;
      cout << endl;
      d1->changeStudentsAdvisor(sidNum, newfidNum);
    }
    else if(userInput == 12){
      int fidNum;
      int rmAdviseeNum;
      cout << "Enter the id number of the Faculty:";
      cin >> fidNum;
      cout << endl;
      cout << "Enter the id number of the advisee you would like to remove from this faculty member" << endl;
      cin >> rmAdviseeNum;
      cout << endl;
      d1->removeAdvisee(fidNum, rmAdviseeNum);
    }
    else if(userInput == 13){
      //rollBack
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
