#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next,prev;
    Node(int data){
        this->data = data;
        next = prev = nullptr;
    }
};

struct DLL{
    Node* head,tail;
    DLL(){
        head = tail = nullptr;
    }
    void insertAtBeg(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    Void deleteNode(Node* ptr){
        if(ptr == nullptr or head==nullptr){
            return;
        }
        
        if(head ==  ptr)
            head = ptr->next;
        
        if(ptr->next != nullptr)
            ptr->next->prev = ptr->prev;
        
        if(ptr->prev != nullptr)
            ptr->prev->next = ptr->next;
        
        delete(ptr);
    }
    void print(){
        Node* temp = head;

        while (temp != nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}


