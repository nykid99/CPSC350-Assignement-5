#include "Student.h"

using namespace std;

Student::Student(){

}

Student::Student(int i, string n, string l, string m, double g, int aid){
  id = i;
  name = n;
  level = l;
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
