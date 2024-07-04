//count
//sum
//avg

#include <iostream>
#include <string>
using namespace std;

class Node {
    private:
    int value;
    Node *nextNode;


    public:

    Node (int Value,Node *NextNode = nullptr) 
    : value(Value),nextNode(NextNode){
            cout << value << "created" << endl;
    }

    void setNext(Node *node){
        nextNode = node;
    }

    //auto getNext(){
    //    return nextNode;
    //}

};

class List {
    private:
    int size;
    Node head;
    Node tail;

    public:

    List (): size(0), head(),tail() {
        
    }
};


int main(){
    Node *node1 = new Node(12);
    Node *node2 = new Node(15);
    node1->setNext(node2);
    node1->getNext();
}