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