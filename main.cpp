// # Cpsc350-Assignment-5
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the main.cpp file for the program


#include <iostream>
#include "DatabaseController.h"
using namespace std;

int main(int argc, char const *argv[]) {
  DatabaseController *d1 = new DatabaseController(); //new database controller initialized
  d1->textReader(); //reads the information in the textfiles
  int startflag = 1; //determines the continuation of the program
  int userInput;//user input
  cout << endl;
  cout << "///Welcome to the Student Database Program///" << endl;
  cout << endl;
  cout << "Here are your options:" << endl;
  cout << endl;
  while(startflag == 1){ //these are the options
    cout << "1. Print all students and their information" << endl;
    cout << "2. Print all Faculty members and their information" << endl;
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
    cout << "15. Output current info to textfiles (Doesn't work)" << endl;
    cout << "16. Change Student info (name, level, major, gpa, advisor ID)" << endl;
    cout << "17. Change Faculty info (name, level, department)" << endl;
    cout << "18. Change Student ID" << endl;
    cout << "19. Change Faculty ID" << endl;
    cout << endl;
    cout << "Enter a number:" ;
    cin >> userInput;//userinput gathered here
    if(userInput == 1){//if 1, it prints student tree
      d1->printStudentinTree(d1->masterStudent.root);
    }
    else if(userInput == 2){ // if 2, it prints faculty tree
      d1->printFacultyinTree(d1->masterFaculty.root);
    }
    else if(userInput == 3){ //if 3, it asks user for student id and then prints info
      int sidNum;
      cout << "please enter the id number of the student:";
      cin >> sidNum;
      cout << endl;
      d1->printStudentInfo(sidNum);
    }
    else if(userInput == 4){ //if 4, it asks user for faculty id and then prints info
      int fidNum;
      cout << "please enter the id number of the Faculty:";
      cin >> fidNum;
      cout << endl;
      d1->printFacultyInfo(fidNum);
    }
    else if(userInput == 5){//if 5, it asks for student id and prints the id of their faculty advisor
      int sidNum;
      cout << "Please enter the id number of the student:";
      cin >> sidNum;
      cout << endl;
      d1->printStudentFacultyAdvisor(sidNum);
    }
    else if(userInput == 6){ //if 6, it asks for faculty id and then prints their advisee IDs
      int fidNum;
      cout << "Please enter the id number of the Faculty:";
      cin >> fidNum;
      cout << endl;
      d1->printFacultyAdvisee(fidNum);
    }
    else if(userInput == 7){ //if 7, adds new student
      cout << "Adding new student" << endl;
      d1->addStudent();
    }
    else if(userInput == 8){ //if 8, it asks for the student id number and deletes that student
      int ddsid;
      cout << "Enter the ID number of the student you would like to delete: ";
      cin >> ddsid;
      cout << endl;
      d1->removeStudent(ddsid);
      cout << "Student successfully removed" << endl;
    }
    else if(userInput == 9){//adds faculty
      cout << "Adding new Faculty" << endl;
      d1->addFaculty();
    }
    else if(userInput == 10){ //asks user for faculty id and deletes that faculty
      int ddfid;
      cout << "Enter the ID number of the Faculty member you would like to delete: ";
      cin >> ddfid;
      cout << endl;
      d1->removeFaculty(ddfid);
      cout << "Faculty member successfully removed" << endl;
    }
    else if(userInput == 11){//replaces student advisor
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
    else if(userInput == 12){ //removes advisee from faculty
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
    else if(userInput == 13){ //rollback
      //rollBack doesn't work
    }
    else if(userInput == 14){ //exits program
      cout << "Exiting Program" << endl;
      exit(0);
    }
    else if(userInput == 15){ //writes to text
      d1->textWriter();
      cout << "info successfully outputted" << endl;
    }
    else if(userInput == 16){//changes student info
      //student info change
      int sflag = 1;
      int newStudentId;
      string newStudentName;
      string newStudentlevel;
      string newStudentmajor;
      double newStudentGPA;
      int newStudentAID;
      cout << endl;
      cout << "Changing Student info" << endl; //asks for id of student that the user wihses to modify
      TreeNode<Student> *newS = new TreeNode<Student>();
      cout << "Enter the ID number of the student whose info is going to be modified: ";
      cin >> newStudentId;
      newS = d1->masterStudent.returnData(newStudentId);
      cout << endl;
      while(sflag == 1){ //choices are listed
        int schoice;
        cout << "Here are your options" << endl;
        cout << "1. Change Student name" << endl;
        cout << "2. Change Student level" << endl;
        cout << "3. Change Student major" << endl;
        cout << "4. Change Student GPA" << endl;
        cout << "5. Change Student Advisor ID" << endl;
        cout << "6. exit" << endl;
        cin >> schoice;
        if(schoice == 1){//modifies name
          cout << "Enter new name: ";
          cin >> newStudentName;
          cout << endl;
          newS->data.StudentName = newStudentName;
          cout << "Student name changed" << endl;
        }
        else if(schoice ==2){ //modifies level
          cout << "Enter new level: ";
          cin >> newStudentlevel;
          cout << endl;
          newS->data.Studentlevel = newStudentlevel;
          cout << "Student level changed" << endl;
        }
        else if(schoice == 3){//modifies major
          cout << "Enter new major: ";
          cin >> newStudentmajor;
          cout << endl;
          newS-> data.major = newStudentmajor;
          cout << "Student major changed" << endl;
        }
        else if(schoice == 4){ //modifies GPA
          cout << "Enter new student GPA: ";
          cin >> newStudentGPA;
          cout << endl;
          newS->data.gpa = newStudentGPA;
          cout << "Student GPA changed" << endl;
        }
        else if(schoice == 5){ //modifies advisor ID
          cout << "Enter new student advisor ID: ";
          cin >> newStudentAID;
          cout << endl;
          newS->data.advisorID = newStudentAID;
          cout << "Student Advisor changed" << endl;
        }
        else if(schoice == 6){ //exits loop and returns to main menu
          sflag = 0;
        }

      }
    }
    else if(userInput == 17){ //changes faculty info
      int fflag = 1;
      int newFacultyID;
      string newFacultyName;
      string newFacultyDepartment;
      string newFacultyLevel;
      cout << "Changing Faculty Info" << endl;
      cout << endl;
      cout << "Enter the ID number of the Faculty member that's going to be modified: ";
      cin >> newFacultyID;
      TreeNode<Faculty> *newF = new TreeNode<Faculty>(); //id number gathered
      newF = d1->masterFaculty.returnData(newFacultyID);
      cout << endl;
      while(fflag == 1){//choices listed
        int fchoice;
        cout << "Here are your options" << endl;
        cout << "1. Change Faculty name" << endl;
        cout << "2. Change Faculty Department" << endl;
        cout << "3. Change Faculty Level" << endl;
        cout << "4. exit" << endl;
        cin >> fchoice;
        if(fchoice == 1){ //changes faculty name
          cout << "Enter new name: ";
          cin >> newFacultyName;
          cout << endl;
          newF->data.FacultyName = newFacultyName;
        }
        else if(fchoice == 2){ //changes department
          cout << "Enter new Department: ";
          cin >> newFacultyDepartment;
          cout << endl;
          newF->data.department = newFacultyDepartment;
        }
        else if(fchoice == 3){ //changes level
          cout << "Enter new Level: ";
          cin >> newFacultyLevel;
          cout << endl;
          newF->data.FacultyLevel = newFacultyLevel;
        }
        else if(fchoice == 4){//exits
          fflag = 0;
        }
      }

    }
    else if(userInput == 18){ //changes student id
      int newMSID;
      int oldMSID;
      TreeNode<Student> *oldMS = new TreeNode<Student>();
      cout << "Enter the ID number of the student you would like to change: ";
      cin >> oldMSID;
      cout << "Enter a new ID number for this Student: ";
      cin >> newMSID;
      cout << endl;
      oldMS = d1->masterStudent.returnData(oldMSID);
      Student *newS = new Student(newMSID, oldMS->data.StudentName, oldMS->data.Studentlevel, oldMS->data.major, oldMS->data.gpa, oldMS->data.advisorID);
      TreeNode<Student> *newMS = new TreeNode<Student>(*newS, newMSID);
      d1->masterStudent.deleteNode(oldMSID);
      d1->masterStudent.insert(newMS);
      cout << "Id number successfully changed" << endl;


    }
    else if(userInput == 19){//changes faculty id
      int newFSID;
      int oldFSID;
      TreeNode<Faculty> *oldMF = new TreeNode<Faculty>();
      cout << "Enter the ID number of the faculty you would like to change: ";
      cin >> oldFSID;
      cout << "Enter a new ID number for this faculty member: ";
      cin >> newFSID;
      cout << endl;
      oldMF = d1->masterFaculty.returnData(oldFSID);
      Faculty *newF = new Faculty(newFSID,oldMF->data.FacultyName, oldMF->data.department, oldMF->data.FacultyLevel);
      TreeNode<Faculty> *newMF = new TreeNode<Faculty>(*newF, newFSID);
      d1->masterFaculty.deleteNode(oldFSID);
      d1->masterFaculty.insert(newMF);
      cout << "Id number successfully changed" << endl;
    }
    else{
      cout << "Invalid input, Please try again" << endl;
    }
  }
  return 0;
}
