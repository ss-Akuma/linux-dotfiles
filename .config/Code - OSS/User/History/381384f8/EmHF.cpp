#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string Name;
    int Id;
    float Grade;

    Student(string name,int id,float grade)
    : Name(name),Id(id),Grade(grade){
        cout << "Student :" << name << "created succesfully!" <<endl;
    }

    void displayInfo(){
        cout << "name" << name << "id" << id << endl;
    }

    ~Student(){}



}

int main(){
    //Student *student = new Student("amin",2344,12.5);
    Student student1("amin",222,12.5);
    student1.displayInfo;
    return 0;
}