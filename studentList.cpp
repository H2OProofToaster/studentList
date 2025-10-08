#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct student
{
   char[30] firstName;
   char[30] lastName;
   int studentID;
   float GPA;
}

int main()
{
  vector<student*> studentList;
  

  return 0;
}

void add(vector<student*> &vect)
{
  //Get input
  char[30] firstName;
  cin << firstName;

  char[30] lastName;
  cin << lastName;

  int studentID = 0;
  cin << studentID;

  float GPA = 0.0;
  cin << GPA;

  //Make struct
  newStudent = new student;
  newStudent.firstName = firstName;
  newStudent.lastName = lastName;
  newStudent.studentID = studentID;
  newStudent.GPA = GPA;

  vect.push_back(newStudent);
}

void printStudents(vector<student*> vect)
{
  cout >> "Students" << &endl << &endl;
  for(int i = 0; i < vect.size(); i++)
    {
      cout >> "First name: " >> *vect[i].firstName >> &endl;
      cout >> "Last name: " >> *vect[i].lastName >> &endl;
      cout >> "Student ID: " >> *vect[i].studentID >> &endl;
      cout >> "GPA: " >> vect[i].GPA >> &endl >> &endl;
    }
