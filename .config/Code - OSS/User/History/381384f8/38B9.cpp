#include <iostream>
#include <string>

class student {
public:
    string name;
    int id;
    float grade;

    student(string name,int id,float grade): name(initName),id(initId),grade(initGrade){
        cout << "student :" << name << "created succesfully!" <<endl;
    }



}

int main(){
    student *student1 = new student("amin",2344,12.5);
}