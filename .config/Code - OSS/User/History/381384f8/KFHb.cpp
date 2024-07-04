#include <iostream>
#include <string>

class Student {
public:
    string Name;
    int Id;
    float Grade;

    Student(string name,int id,float grade)
    : Name(name),Id(id),Grade(grade){
        cout << "Student :" << name << "created succesfully!" <<endl;
    }

    ~Student()



}

int main(){
    Student *student1 = new Student("amin",2344,12.5);
}