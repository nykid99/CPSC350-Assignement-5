#include "Student.h"

using namespace std;

Student::Student(){

}

Student::Student(int i, string n, string l, string m, double g, int aid){
  StudentID = i;
  StudentName = n;
  Studentlevel = l;
  major = m;
  gpa = g;
  advisorID = aid;
}

Student::~Student(){

};

string Student::getMajor(){
  return major;
}

double Student::getGPA(){
  return gpa;
}

int Student::getAdvisorID(){
  return advisorID;
}
int Student::getStudentID(){
  return StudentID;
}
string Student::getStudentName(){
  return StudentName;
}

void Student::printStudent(){
  cout << "ID: " << StudentID << endl;
  cout << "Name: " << StudentName << endl;
  cout << "Level: " << Studentlevel << endl;
  cout << "major: "<< major << endl;
  cout << "gpa: " << gpa << endl;
  cout << "advisorID: " << advisorID << endl;
  cout << endl;
}
