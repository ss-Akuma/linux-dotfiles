#include <iostream>
#include <string>
#include <vector>

using namespace std;

class treeNode {

private:
    
    int value;
    treeNode *parent;
    vector<int> children;


public:

    treeNode(int Value,treeNode *Parent = nullptr) : value(Value), parent(Parent){
        cout << value << "created" << endl;
    }

};


int main(){

    treeNode *node1 = new treeNode(12);

}