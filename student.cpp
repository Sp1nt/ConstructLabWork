#include<iostream>
using namespace std;


class Student
{
    char* name;
    char* email;
    int age;
public:
    Student()
    {
        cout << "Constructor by def.\n";
        name = nullptr;
        email = nullptr;
        age = 0;
    }
    Student(const char* n, int a, const char* e)
    {
        name = new char[strlen(n) + 1]; 
        strcpy_s(name, strlen(n) + 1, n);
        email = new char[strlen(e) + 1];
        strcpy_s(email, strlen(e) + 1, e);
        age = a;
        cout << "Constructor 3 params\n";
    }
    Student(const char* n, int a)
    {
        name = new char[strlen(n) + 1]; 
        strcpy_s(name, strlen(n) + 1, n);
        age = a;
        cout << "Constructor 2 params\n";
    }
    void Input()
    {
        char buff[20];
        cout << "Enter name: ";
        cin >> buff;
        if (name != nullptr)
        {
            cout << "Delete -> " << name << "." << endl;
            delete[]name;
        }
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);

        cout << "Enter age: ";
        cin >> age;
    }

    void InputTwo() {
        char buff[50];
        cout << "Enter name: ";
        cin >> buff;
        if (name != nullptr)
        {
            cout << "Delete -> " << name << "." << endl;
            delete[]name;
        }
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter email: ";
        cin >> buff;

        if (email != nullptr)
        {
            cout << "Delete -> " << name << "." << endl;
            delete[]email;
        }

        email = new char[strlen(buff) + 1];
        strcpy_s(email, strlen(buff) + 1, buff);
    }

    void Print()
    {
        cout << "Name: " << name << "\tAge: " << age << endl;
    }
    void PrintTwo() {
        cout << "Name: " << name << "\tAge: " << age << "\temail: " << email << endl;
    }
    ~Student()
    {
        delete[] name; 
        delete[] email;
        cout << "Destructor\n";
    }
};

int main() {
    Student obj1("Oleg", 20);
    obj1.Print();

    Student obj2("Alex", 15, "test@gmail.com");
    obj2.PrintTwo();

    obj2.InputTwo();
    obj2.PrintTwo();
}