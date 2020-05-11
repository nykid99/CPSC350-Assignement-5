// # Cpsc350-Assignment-5
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the cpp file for the Faculty class

#include "Faculty.h"
#include <iostream>

using namespace std;


Faculty::Faculty(){//default constrctor

}

Faculty::~Faculty(){ //destructor

}

Faculty::Faculty(int i, string n, string l, string d){//overloaded constructor
  FacultyID = i;
  FacultyName = n;
  FacultyLevel = l;
  department = d;
}


string Faculty::getDepartment(){ //returns department
  return department;
}

int Faculty::getFacultyID(){ //returns faculty id
  return FacultyID;
}
string Faculty::getFacultyName(){ //returns faculty name
  return FacultyName;
}

void Faculty::printFaculty(){ //prints faculty
  cout << "FacultyID: " << FacultyID << endl;
  cout << "FacultyName: " << FacultyName << endl;
  cout << "FacultyLevel: " << FacultyLevel << endl;
  cout << "Department:" << department << endl;
  cout << "list of advisee" << endl;
  adviseeIDList->printList();
  cout << endl;
}

void Faculty::pushToAIDList(int b){ //pushes id to the faculty's advisee list
  adviseeIDList->insertBack(b);
}
