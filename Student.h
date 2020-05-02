#include <iostream>
#include "Person.h"

using namespace std;

class Student:public Person{
public:
  string major;
  double gpa;
  int advisorID;
  string level;

  Student();
  Student(int i, string n, string l, string m, double g, int aid);
  ~Student();

  string getMajor();
  double getGPA();
  int getAdvisorID();
};
