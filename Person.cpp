#include "Person.h"

using namespace std;

Person::Person(){

}

Person::~Person(){

}

int Person::getID(){
  return id;
}
void Person::setID(int i){
  id = i;
}
string Person::getStatus(){
  return status;
}

string Person::getName(){
  return name;
}
