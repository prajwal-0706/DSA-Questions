#include <iostream>
#include <fstream>
using namespace std;

class Employee
{

public:
  struct Emply
  {
    int id;
    char name[25];
    char designation[15];
    int salary;
  } Records;

  struct Index
  {
    int id;
    int position;
  } index;

  void input()
  {
    cout << "\nEnter id number : ";
    cin >> Records.id;
    cout << "\nEnter name : ";
    cin >> Records.name;
    cout << "\nEnter designation(do not give spaces) : ";
    cin >> Records.designation;
    cout << "\nEnter salary : ";
    cin >> Records.salary;
  }

  void output()
  {

    cout << "\n\t" << Records.id << "\t" << Records.name << "\t" << Records.designation << "\t" << Records.salary;
  }
  void outputIndex()
  {

    cout << "\n\t" << index.id << "\t" << index.position;
  }

  void insert()
  {
    fstream filedata;
    fstream indexfile;
    Employee e1;
    filedata.open("DataFile.txt", ios::app | ios::binary);
    indexfile.open("IndexFile.txt", ios::app | ios::binary);
    int i = 0;
    char ch;
    do
    {
      e1.input();
      filedata.write((char *)&e1, sizeof(e1));
      index.id = e1.Records.id;
      index.position = i;
      i++;
      indexfile.write((char *)&index, sizeof(index));
      cout << "\nDo you want to enter one more record ?(y/n) :";
      cin >> ch;
    } while (ch == 'y');
    filedata.close();
    indexfile.close();
  }

  void display()
  {

    fstream filedata;
    Employee e2;
    filedata.open("DataFile.txt", ios::in | ios::binary);
    while (filedata.read((char *)&e2, sizeof(e2)))
    {
      e2.output();
    }
    filedata.close();
  }

  void displayIndex()
  {
    fstream indexdata;
    Employee e2;
    indexdata.open("IndexFile.txt", ios::in | ios::binary);
    while (indexdata.read((char *)&e2.index, sizeof(e2.index)))
    {
      e2.outputIndex();
    };
    indexdata.close();
  }

  void search(int id)
  {
    fstream filedata;
    fstream indexdata;
    Employee e3;
    indexdata.open("IndexFile.txt", ios::in | ios::binary);
    int k;
    bool found = false;
    while (indexdata.read((char *)&e3.index, sizeof(e3.index)))
    {
      if (e3.index.id == id)
      {
        k = e3.index.position;
        found = true;
        break;
      }
    }
    indexdata.close();
    if (found)
    {
      cout << "\nEmployee found !! " << endl;
      filedata.open("DataFile.txt", ios::in | ios::binary);
      int offset = k * sizeof(e3);
      filedata.seekg(offset);
      filedata.read((char *)&e3, sizeof(e3));
      e3.output();
      filedata.close();
    }
    else
    {
      cout << "\nEmployee Record not found";
    }
  }

  void deleteEmployee(int id)
  {

    // deleteing from indexFile
    fstream indexdata;
    fstream indexdataNew;
    Employee e4;
    indexdata.open("IndexFile.txt", ios::in | ios::out | ios::binary);
    indexdataNew.open("IndexFileNew.txt", ios::out | ios::binary);
    bool found = false;
    int i = 0;
    while (indexdata.read((char *)&e4.index, sizeof(e4.index)))
    {
      if (e4.index.id == id)
      {
        found = true;
      }
      else
      {
        e4.index.position = i;
        indexdataNew.write((char *)&e4.index, sizeof(e4.index));
        i++;
      }
    }
    indexdata.close();
    indexdataNew.close();
    remove("IndexFile.txt");
    rename("IndexFileNew.txt", "IndexFile.txt");

    // deleting from DataFile
    fstream filedata;
    fstream filedataNew;
    Employee e5;
    filedata.open("DataFile.txt", ios::in | ios::binary);
    filedataNew.open("DataFileNew.txt", ios::out | ios::binary);
    while (filedata.read((char *)&e5, sizeof(e5)))
    {

      if (e5.Records.id == id)
      {
        found = true;
      }
      if (e5.Records.id != id)
      {
        filedataNew.write((char *)&e5, sizeof(e5));
      }
    }
    if (!found)
    {
      cout << "\nEmployee not found, so can't delete";
    }
    else
    {
      cout << "\nEmployee deleted ";
    }
    filedata.close();
    filedataNew.close();
    remove("DataFile.txt");
    rename("DataFileNew.txt", "DataFile.txt");
  }
};

int main()
{
  Employee e;
  int ch;
  char c;
  while (true)
  {
    cout << "\n\t---------------MENU-----------------------";
    cout << "\n\tEnter 1 : To add employee record ";
    cout << "\n\tEnter 2 : To delete employee record ";
    cout << "\n\tEnter 3 : To search employee record ";
    cout << "\n\tEnter 4 : To display all  employee record ";
    cout << "\n\tEnter 5 : To display index file record ";
    cout << "\n\tEnter 6 : To exit prgram ";
    cout << "\nEnter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
      e.insert();
      break;
    }
    case 2:
    {
      int a;
      cout << "\nEnter id which is to be deleted : ";
      cin >> a;
      e.deleteEmployee(a);
      break;
    }
    case 3:
    {
      int a;
      cout << "\nEnter id which is to be searched : ";
      cin >> a;
      e.search(a);
      break;
    }
    case 4:
    {
      e.display();
      break;
    }
    case 5:
    {
      e.displayIndex();
      break;
    }
    case 6:
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