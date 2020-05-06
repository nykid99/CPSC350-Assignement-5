#include "Faculty.h"
#include <iostream>

using namespace std;


Faculty::Faculty(){

}

Faculty::~Faculty(){

}

Faculty::Faculty(int i, string n, string l, string d){
  FacultyID = i;
  FacultyName = n;
  FacultyLevel = l;
  department = d;
}


string Faculty::getDepartment(){
  return department;
}

int Faculty::getFacultyID(){
  return FacultyID;
}
string Faculty::getFacultyName(){
  return FacultyName;
}

void Faculty::printFaculty(){
  cout << "FacultyID: " << FacultyID << endl;
  cout << "FacultyName: " << FacultyName << endl;
  cout << "FacultyLevel: " << FacultyLevel << endl;
  cout << "Department:" << department << endl;
  cout << "list of advisee" << endl;
  adviseeIDList->printList();
  cout << endl;
}

void Faculty::pushToAIDList(int b){
  adviseeIDList->insertBack(b);
}
