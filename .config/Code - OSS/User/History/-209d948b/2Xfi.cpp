//count
//sum
//avg

#include <iostream>
#include <string>

class Node {
    private:
    int value;
    Node *nextNode;


    public:

    Node (int Value,Node *NextNode = nullptr) 
    : value(Value),nextNode(NextNode){
            count << value << "created" << endl;
    }

    setNext(Node *node){
        nextNode = node;
    }

    getNext(int value){
        return nextNode;
    }

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