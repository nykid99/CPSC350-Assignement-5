#include <iostream>

using namespace std;

class Person
{
public:
  int id;
  string name;
  string status;
  string level;
  Person();
  ~Person();

  int getID();
  void setID(int i);
  string getLevel();
  string getName();
  string getStatus();
};
