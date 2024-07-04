#include <iostream>
#include <string>
#include <vector>

class treeNode {

private:
    treeNode Parent;
    treeNode root ;
    int vlaue;
    vector<int> children;


public:

    treeNode(treeNode parent,int Value) : vlaue(Value), parent(Parent = root){

    }

};


int main(){

    treeNode *node1 = new treeNode(12);

}