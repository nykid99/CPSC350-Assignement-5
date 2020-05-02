#include "Faculty.h"
#include <iostream>

using namespace std;


Faculty::Faculty(){

}

Faculty::~Faculty(){

}

Faculty::Faculty(int i, string n, string l, string d){
  id = i;
  name = n;
  level = l;
  department = d;
}


string Faculty::getDepartment(){
  return department;
}
