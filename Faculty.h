#include "Person.h"
#include "DoubleGenList.h"

#include <iostream>

using namespace std;

class Faculty:public Person{
public:

  Faculty();
  Faculty(int i, string n, string l, string d);
  ~Faculty();
  string department;
  DoubleGenList<string> studentList;
  string getDepartment();
};
