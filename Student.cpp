// # Cpsc350-Assignment-5
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the Student object


#include "Student.h"

using namespace std;

Student::Student(){//default constructor

}

Student::Student(int i, string n, string l, string m, double g, int aid){ //overloaded constructor
  StudentID = i;
  StudentName = n;
  Studentlevel = l;
  major = m;
  gpa = g;
  advisorID = aid;
}

Student::~Student(){ //destructor

};

string Student::getMajor(){ //returns major
  return major;
}

double Student::getGPA(){ //returns gpa
  return gpa;
}

int Student::getAdvisorID(){ //returns advisor id
  return advisorID;
}
int Student::getStudentID(){ //returns student id
  return StudentID;
}
string Student::getStudentName(){ //returns name of student
  return StudentName;
}

void Student::printStudent(){ //prints student info
  cout << "ID: " << StudentID << endl;
  cout << "Name: " << StudentName << endl;
  cout << "Level: " << Studentlevel << endl;
  cout << "major: "<< major << endl;
  cout << "gpa: " << gpa << endl;
  cout << "advisorID: " << advisorID << endl;
  cout << endl;
}
