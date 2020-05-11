// # Cpsc350-Assignment-4
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the DoubleGenList template class

#include <iostream>
#include <string>
#include "GenListNode.h" //includes GenListNode
using namespace std;

template <typename T>
class DoubleGenList{ //this is the template class for the DoubleGenList
public:
  GenListNode<T> *front; //front and back from GenListNode
  GenListNode<T> *back;
  unsigned int size;
  DoubleGenList();//default constructor
  DoubleGenList(int d); // overloaded constructor
  ~DoubleGenList(); // destructor

  T getFront();
  void insertFront(T data);
  void insertBack(T data);
  T removeFront();
  int search(int val);// will return position
  void removeAtpos(int pos);

  unsigned int getSize();
  bool isEmpty();
  void printList();
};

template <typename T>
DoubleGenList<T>::DoubleGenList(){
	front = NULL;
	back = NULL;
  size = 0;
};

template <typename T>
DoubleGenList<T>::~DoubleGenList(){

};


template <typename T>
DoubleGenList<T>::DoubleGenList(int d){
  size = d;
  front = NULL;
  back = NULL;
};


template <typename T>
bool DoubleGenList<T>::isEmpty(){ //checks if empty
  return size == 0;
}

template <typename T>
T DoubleGenList<T>::getFront(){ //gets the front data
  return front->data;
}

template <typename T>
void DoubleGenList<T>::insertFront(T data){ //inserts to the front
  GenListNode<T> *node = new GenListNode<T>(data);
  //check if empty
  if(isEmpty()){
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;

    //not empty
  }
  size++;
}

template <typename T>
void DoubleGenList<T>::insertBack(T data){ //inserts to the back
  GenListNode<T> *node = new GenListNode<T>(data);
  //check if empty
  if(isEmpty()){
    front = node;
  }
  else{
    back->next = node;
    node->prev = back;

    //not empty
  }
  back = node;
  size++;
}

template <typename T>
T DoubleGenList<T>::removeFront(){
  int temp = front->data; //stores the value
  GenListNode<T> *ft = front; //second node to keep a track of the pointer.
  front = front->next;
  ft->next = NULL;
  delete ft;

  size--;
  return temp;
}



template <typename T>
int DoubleGenList<T>::search(int val){ //returns the index of the info
  int position = -1;
  GenListNode<T> *curr = front;

  while(curr != NULL){

    position++;

    if(curr->data == val){
      break;
    }
    else{
      curr = curr->next;
    }
  }
  if(curr == NULL){
    position = -1;
  }
  if(position == -1){
    cout << "This advisee doesn't exist in this list" << endl;

  }
  else{
      return position;
  }
}
template <typename T>
void DoubleGenList<T>::removeAtpos(int pos){ 
  if (front == NULL)
			return;
		GenListNode<T>* temp = front;
		if (pos == 0){
			front = temp->next;
			if (front){
        front->prev = NULL;
      }
			delete temp;
			return;
		}
		for (int i = 0; i < pos && temp != NULL; i++)
			temp = temp->next;
		if (temp == NULL)
			return;
		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		delete temp;
}

template <typename T>
unsigned int DoubleGenList<T>::getSize(){ //returns the size
  return size;

}


template <typename T>
void DoubleGenList<T>::printList(){ //prints the entire list
  GenListNode<T> *curr = front;
  if(isEmpty()){
    cout << "list is empty" << endl;
  }
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}
