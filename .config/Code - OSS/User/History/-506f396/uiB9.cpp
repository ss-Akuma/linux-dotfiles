#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class treeNode {

private:
    
    int value;
    treeNode *parent;
    vector<int> children;


public:

    treeNode(int Value,treeNode *Parent = nullptr) : value(Value), parent(Parent){
        
        cout << value << "created" << endl;
        if (!isRoot){
            parent->children.pushback();
        }
    }

    bool isRoot(){
        if (parent == nullptr){
            return true;
        }
        else{
            return false;
        }
    }
};

void bfs(){
    queue<treeNode> q;

}


int main(){

    treeNode *root = new treeNode(12);
    treeNode *child1 = new treeNode(13,root);
    treeNode *child2 = new treeNode(33,root);
    treeNode *gChild1 = new treeNode(11,child1);
    treeNode *gChild2 = new treeNode(23,child2);



}