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

    void isRoot(){
        if (parent == nullptr){
            cout << "is root " << endl;
        }
    }
};


int main(){

    treeNode *root = new treeNode(12);
    treeNode *child1 = new treeNode(13,root);
    treeNode *child2 = new treeNode(33,root);
    treeNode *gChild1 = new treeNode(11,child1);
    treeNode *gChild2 = new treeNode(11,child2);

    child1->isRoot();


}