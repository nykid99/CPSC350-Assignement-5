#include <iostream>

using namespace std;

class Student{
public:
  string StudentName;
  int StudentID;
  string Studentlevel;
  string major;
  double gpa;
  int advisorID;

  Student();
  Student(int i, string n, string l, string m, double g, int aid);
  ~Student();
  string getStudentName();
  int getStudentID();
  string getMajor();
  double getGPA();
  int getAdvisorID();
  void printStudent();
};
