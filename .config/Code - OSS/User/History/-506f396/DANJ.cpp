#include <iostream>
#include <string>
#include <vector>

class treeNode {

private:
    
    int vlaue;
    treeNode *parent;
    vector<int> children;


public:

    treeNode(int Value,treeNode *Parent) : vlaue(Value),{}

};


int main(){

    treeNode *node1 = new treeNode(12);

}