#include <iostream>
#include <string>
#include <vector>

class treeNode {

private:
    treeNode *Parent;
    treeNode *root ;
    int vlaue;
    vector<int> children;


public:

    treeNode(treeNode *parent = root,int Value) : vlaue(Value), parent(Parent){

    }

};


int main(){

    treeNode *node1 = new treeNode(12);

}