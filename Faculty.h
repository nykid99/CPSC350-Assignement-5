// # Cpsc350-Assignment-5
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the Faculty object



#include "DoubleGenList.h"
#include <list>
#include <iostream>

using namespace std;

class Faculty{
public:

  Faculty();
  Faculty(int i, string n, string l, string d);
  ~Faculty();
  int FacultyID;
  string FacultyName;
  string department;
  string FacultyLevel;
  DoubleGenList<int> *adviseeIDList = new DoubleGenList<int>();
  string getDepartment();
  int getFacultyID();
  string getFacultyName();
  void printFaculty();
  void pushToAIDList(int b);

};
