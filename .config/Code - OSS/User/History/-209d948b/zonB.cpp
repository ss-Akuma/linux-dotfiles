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

    //void getNext(int value){
    //    return nextNode;
    //}

};

class List {
    private:
    int size;
    Node head;
    Node tail;
};


int main(){
    Node *node1 = new Node(12);
}