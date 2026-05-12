#include <iostream>
#include <queue> 
#include <stack>
#include <string>

using namespace std;

template <typename T>
struct TicketNode {
    T data;
    TicketNode* next;
    TicketNode* left;
    TicketNode* right;
    
    TicketNode(T d){
        data = d;
        next = nullptr;
        left = nullptr;
        right = nullptr;

    }
    
};


int main(){

    TicketNode<string>* a1 = new TicketNode<string>("Wifi");
    TicketNode<string>* a2 = new TicketNode<string>("Mouse");
    TicketNode<string>* a3 = new TicketNode<string>("Computer");

    a1->next = a2;
    a2->next = a3;

    TicketNode<string>* curr = a1;
    while(curr){
        cout << curr->data << " " << endl;
        curr = curr->next;
    }

    TicketNode<int>* arc1 = new TicketNode<int>(50);
    TicketNode<int>* arc2 = new TicketNode<int>(25);
    TicketNode<int>* arc3 = new TicketNode<int>(75);

    arc1->left = arc2;
    arc1->right = arc3;

    queue<string> holdLine;

    for (int i = 1; i < 11; i++){
        holdLine.push("User #");
    }

    while(!holdLine.empty()){
        cout << holdLine.front() << " " << endl;
        holdLine.pop();
    }

    stack<int> undoHist;

    for (int i = 1; i < 11; i++){
        undoHist.push(i);
    }

    while(!undoHist.empty()){
        cout << undoHist.top() << " " << endl;
        undoHist.pop();
    }

    return 0;
}