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
        cout << "Student :" << Name << "created succesfully!" <<endl;
    };

    void displayInfo(){
        cout << "name" << Name << "id" << Id << endl;
    };

};

int main(){
    Student *student1 = new Student("amin",2344,12.5);
    student1->displayInfo;
    return 0;
}