// # Cpsc350-Assignment-5
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the cpp file for the DatabaseController class

#include <string>
#include <fstream>
#include <iostream>
#include "DatabaseController.h"

using namespace std;

DatabaseController::DatabaseController(){};
DatabaseController::~DatabaseController(){};


void DatabaseController::printStudentWithNode(TreeNode<Student> *s){
  s->data.printStudent();
}
void DatabaseController::printFacultyWithNode(TreeNode<Faculty> *f){
  f->data.printFaculty();
}

void DatabaseController::textStudentWithNode(string fName, TreeNode<Student> *ostudent){
  ofstream ofnode;
  ofnode.open(fName);
  if(ostudent != NULL)
  {
    ofnode << ostudent->data.StudentID << "\n"<< ostudent->data.StudentName << "\n" << ostudent->data.Studentlevel << "\n" << ostudent->data.major << "\n" << ostudent->data.gpa << "\n" << ostudent->data.advisorID << "\n";

      if (ostudent->left != NULL)
      {
          textStudentWithNode(fName, ostudent->left);
      }
      if (ostudent->right != NULL)
      {
          textStudentWithNode(fName, ostudent->right);
      }
  }
  ofnode.close();
}

void DatabaseController::textFacultyWithNode(string ffName, TreeNode<Faculty> *oFaculty){
  ofstream offnode;
  offnode.open(ffName);
  if (oFaculty != NULL)
  {
    offnode << oFaculty->data.FacultyID << endl << oFaculty->data.FacultyName << endl << oFaculty->data.FacultyLevel << endl << oFaculty->data.department << endl << oFaculty->data.adviseeIDList->size << endl;
    GenListNode<int> *currfac = oFaculty->data.adviseeIDList->front;
    if(oFaculty->data.adviseeIDList->isEmpty()){
      offnode << "advisee list is empty" << endl;
    }
    else{
      while(currfac!=NULL){
        offnode << currfac->data << endl;
        currfac = currfac->next;
      }
    }
    if (oFaculty->left != NULL)
    {
        textFacultyWithNode(ffName, oFaculty->left);
    }
    if (oFaculty->right != NULL)
    {
        textFacultyWithNode(ffName, oFaculty->right);
    }
  }
  offnode.close();
}

void DatabaseController::textWriter(){
  ofstream StudentoutFile; // these are for marking the number of students/Faculty
  ofstream FacultyoutFile;

  StudentoutFile.open("studentTable.txt");
  if(StudentoutFile.is_open()){
    StudentoutFile << masterStudent.size << endl;
    TreeNode<Student> *ofstudent = masterStudent.root;
    textStudentWithNode("studentTable.txt", ofstudent);
  }
  StudentoutFile.close();
  FacultyoutFile.open("facultyTable.txt");
  if(FacultyoutFile.is_open()){
    FacultyoutFile << masterFaculty.size << endl;
    // TreeNode<Faculty> *
  }
}
void DatabaseController::removeStudent(int dSID){
  if(masterStudent.search(dSID)){
    masterStudent.deleteNode(dSID);
  }
  else{
    cout << "This student doesn't exist in the database" << endl;
  }
}
void DatabaseController::removeFaculty(int dFID){
  if(masterFaculty.search(dFID)){
    masterFaculty.deleteNode(dFID);
  }
  else{
    cout << "This Faculty doesn't exist in the database" << endl;
  }
}

void DatabaseController::removeAdvisee(int facID, int adviseeID){
  if(masterFaculty.search(facID) && masterFaculty.search(adviseeID)){
    int position = 0;
    TreeNode<Faculty> *newFacultyNode = new TreeNode<Faculty>();
    newFacultyNode = masterFaculty.returnData(facID);
    position = newFacultyNode->data.adviseeIDList->search(adviseeID);
    newFacultyNode->data.adviseeIDList->removeAtpos(position);
    cout << "Advisee successfully removed" << endl;
  }
  else{
    cout << "Faculty ID entered doesn't exist check both inputs" << endl;
  }
}
void DatabaseController::changeStudentsAdvisor(int newSID, int newFID){
  if(masterStudent.search(newSID) && masterFaculty.search(newFID)){
    TreeNode<Student> *newStudentNode = new TreeNode<Student>();
    newStudentNode = masterStudent.returnData(newSID);
    newStudentNode->data.advisorID = newFID;
    cout << "student's advisor successfully changed" << endl;
  }
  else{
    cout << "Either the student or the faculty doesn't exist" << endl;
  }
}
void DatabaseController::printFacultyAdvisee(int fd){
  if(masterFaculty.search(fd)){
    TreeNode<Faculty> *tempData = new TreeNode<Faculty>();
    tempData = masterFaculty.returnData(fd);
    tempData->data.adviseeIDList->printList();
  }
  else{
    cout << "This Faculty doesn't exist" << endl;
  }
}
void DatabaseController::printStudentFacultyAdvisor(int sd){ //number 5
  if(masterStudent.search(sd)){
    int adviID;
    TreeNode<Student> *tempData = new TreeNode<Student>();
    tempData = masterStudent.returnData(sd);
    adviID = tempData->data.advisorID;
    if(masterFaculty.search(adviID)){
      printFacultyInfo(adviID);
    }
    else{
      cout << "This faculty member doesn't exist" << endl;
    }
  }
  else{
    cout << "This student doesn't exist" << endl;
  }
}
void DatabaseController::printStudentinTree(TreeNode<Student> *n){
  if (n != NULL)
    {

        if (n->left != NULL)
        {
            printStudentinTree(n->left);
        }
        // arrayVector.push_back(n->data.StudentID);
        n->data.printStudent();
        if (n->right != NULL)
        {
            printStudentinTree(n->right);
        }
    }
    else
    {
        cout << ">> Tree is empty<<" << endl;
    }

}

void DatabaseController::printFacultyinTree(TreeNode<Faculty> *x){
  if (x != NULL)
    {
        if (x->left != NULL)
        {
            printFacultyinTree(x->left);
        }
        x->data.printFaculty();
        if (x->right != NULL)
        {
            printFacultyinTree(x->right);
        }
    }
    else
    {
        cout << ">> Tree is empty<<" << endl;
    }
}

void DatabaseController::addStudent(){
  string n;
  int di;
  string sl;
  string mj;
  double pga;
  int adi;
  cout << "Enter the name of the student: ";
  cin >> n;
  cout << "Enter the id number of the student: ";
  cin >> di;
  cout << "Enter the level of the student: ";
  cin >> sl;
  cout << "Enter the gpa of the student: ";
  cin >> pga;
  cout << "Enter the advisor ID of the student: ";
  cin >> adi;
  Student *newStudent = new Student(di, n, sl, mj, pga, adi);
  TreeNode<Student> *newStudentNode = new TreeNode<Student>(*newStudent, di);
  masterStudent.insert(newStudentNode);
}
void DatabaseController::addFaculty(){
  int fid;
  int fadCount = 1;
  int fadNum;
  string fn;
  string fl;
  string fdp;
  cout << "Enter the name of the Faculty: ";
  cin >> fn;
  cout << "Enter the id number of the Faculty: ";
  cin >> fid;
  cout << "Enter the level of the Faculty: ";
  cin >> fl;
  cout << "Enter the department of the Faculty: ";
  cin >> fdp;
  Faculty *newFaculty = new Faculty(fid, fn, fl, fdp);
  TreeNode<Faculty> *newFacultyNode = new TreeNode<Faculty>(*newFaculty, fid);
  cout << "Enter the number of advisees this Faculty has: ";
  cin >> fadNum;
  for(int y = 0; y < fadNum; ++y){
    int newADVID;
    cout << "Enter advisee ID number " << fadCount << ": ";
    cin >> newADVID;
    newFacultyNode->data.adviseeIDList->insertBack(newADVID);
  }
  masterFaculty.insert(newFacultyNode);
  cout << "Faculty Successfully added" << endl;
}
void DatabaseController::printStudentInfo(int y){
  if(masterStudent.search(y)){
    printStudentWithNode(masterStudent.returnData(y));
  }
  else{
    cout << "Student doesn't exist in the system" << endl;
  }
}

void DatabaseController::printFacultyInfo(int g){
  if(masterFaculty.search(g)){
    printFacultyWithNode(masterFaculty.returnData(g));
  }
  else{
    cout << "Faculty doesn't exist in the system" << endl;
  }
}

void DatabaseController::textReader(){
  ifstream studentInFile;
  ifstream facultyInFile;
  int fsid;
  string fsname;
  string fslevel;
  string fsmajor;
  double fsgpa = 3.1;
  int fsadvisorID;
  string line;
  int numOfStudents;
  int tempDouble;

  studentInFile.open("studentTable.txt");

  if(studentInFile.is_open()){
    getline(studentInFile,line);
    numOfStudents = stoi(line);
    for(int i = 0; i<numOfStudents;++i){
      getline(studentInFile,line);
      fsid = stoi(line);
      getline(studentInFile,line);
      fsname = line;
      getline(studentInFile,line);
      fslevel = line;
      getline(studentInFile,line);
      fsmajor = line;
      getline(studentInFile,line);
      fsgpa = stod(line);
      getline(studentInFile,line);
      fsadvisorID = stoi(line);
      Student *newFstudent = new Student(fsid, fsname, fslevel, fsmajor, fsgpa, fsadvisorID);
      TreeNode<Student> *studNode = new TreeNode<Student>(*newFstudent, fsid);
      masterStudent.insert(studNode);
    }
    studentInFile.close();
  }
  else{
    cout << "masterStudent didn't open up" << endl;
  }

  int numOfFaculty;
  int ffID;
  string ffname;
  string fflevel;
  string ffdepartment;
  int numOfAdvisee;
  int tempAID;


  facultyInFile.open("facultyTable.txt");
  if(facultyInFile.is_open()){
    getline(facultyInFile,line);
    numOfFaculty = stoi(line);
    for(int i = 0; i<numOfFaculty;++i){
      getline(facultyInFile,line);
      ffID = stoi(line);
      getline(facultyInFile,line);
      ffname = line;
      getline(facultyInFile,line);
      fflevel = line;
      getline(facultyInFile,line);
      ffdepartment = line;
      Faculty *newFFaculty = new Faculty(ffID, ffname, fflevel, ffdepartment);
      TreeNode<Faculty> *FacNode = new TreeNode<Faculty>(*newFFaculty, ffID);
      masterFaculty.insert(FacNode);
      getline(facultyInFile,line);
      numOfAdvisee = stoi(line);
      for(int u = 0; u < numOfAdvisee; ++u){
        getline(facultyInFile,line);
        tempAID = stoi(line);
        FacNode->data.pushToAIDList(tempAID);
      }
    }
    facultyInFile.close();
  }
  else{
    cout << "masterFaculty didn't open up";
  }
}
