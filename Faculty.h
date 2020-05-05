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
  list<int> *advIDList;
  string getDepartment();
  int getFacultyID();
  string getFacultyName();
  void printFaculty();
  void pushToAIDList(int b);

};
