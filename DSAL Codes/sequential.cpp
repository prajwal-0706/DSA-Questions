#include <iostream>
#include <fstream>
using namespace std;

class Student
{
  int roll;
  char name[30];
  char div;
  char address[50];

  void input()
  {
    cout << "\nEnter roll number : ";
    cin >> roll;
    cout << "\nEnter name : ";
    cin >> name;
    cout << "\nEnter division : ";
    cin >> div;
    cout << "\nEnter address(do not give spaces) : ";
    cin >> address;
  }

  void output()
  {

    cout << "\n\t" << roll << "\t" << name << "\t" << div << "\t" << address;
  }

public:
  void Add()
  {
    fstream obj;
    Student s1;
    s1.input();
    obj.open("StudentRecord.txt", ios::app | ios::binary);
    //(char*) is a typecast operation. It converts the memory address of s1 into a pointer to a char. This means that the code is treating the data in s1 as a sequence of characters.
    obj.write((char *)&s1, sizeof(s1));
    obj.close();
  }

  void display()
  {
    fstream obj2;
    Student s2;
    obj2.open("StudentRecord.txt", ios::in | ios::binary);
    while (obj2.read((char *)&s2, sizeof(s2)))
    {
      s2.output();
    }
    obj2.close();
  }

  void search(int roll)
  {
    fstream obj3;
    Student s3;
    obj3.open("StudentRecord.txt", ios::in | ios::binary);
    bool found = false;
    while (obj3.read((char *)&s3, sizeof(s3)))
    {

      if (s3.roll == roll)
      {
        cout << "\nStudent found ";
        s3.output();
        found = true;
        break;
      }
    }
    if (!found)
    {
      cout << "Student not found";
    }
    obj3.close();
  }

  void deleteStudent(int roll)
  {
    fstream obj3;
    fstream obj;
    Student s3;
    obj3.open("StudentRecord.txt", ios::in | ios::binary);
    obj.open("StudentRecord2.txt", ios::out | ios::binary);
    bool found = false;
    while (obj3.read((char *)&s3, sizeof(s3)))
    {

      if (s3.roll == roll)
      {
        found = true;
      }
      if (s3.roll != roll)
      {
        obj.write((char *)&s3, sizeof(s3));
      }
    }
    if (!found)
    {
      cout << "\nStudent not found, so can't delete";
    }
    obj3.close();
    obj.close();
    remove("StudentRecord.txt");
    rename("StudentRecord2.txt", "StudentRecord.txt");
  }
};

int main()
{
  Student S;
  int ch;
  char c;
  while (true)
  {
    cout << "\n\t---------------MENU-----------------------";
    cout << "\n\tEnter 1 : To add student record ";
    cout << "\n\tEnter 2 : To delete student record ";
    cout << "\n\tEnter 3 : To search student record ";
    cout << "\n\tEnter 4 : To display all students record ";
    cout << "\n\tEnter 5 : To exit prgram ";
    cout << "\nEnter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
      do
      {
        S.Add();
        cout << "Do you want to add more record ? (y/n) : ";
        cin >> c;
      } while (c == 'y');
      break;
    }
    case 2:
    {
      int a;
      cout << "\nEnter roll number which is to be deleted : ";
      cin >> a;
      S.deleteStudent(a);
      break;
    }
    case 3:
    {
      int a;
      cout << "\nEnter roll number which is to be searched : ";
      cin >> a;
      S.search(a);
      break;
    }
    case 4:
    {
      S.display();
      break;
    }
    case 5:
    {
      exit(0);
    }
    default:
      cout << "Invalid choice";
      break;
    }
  }

  return 0;
}