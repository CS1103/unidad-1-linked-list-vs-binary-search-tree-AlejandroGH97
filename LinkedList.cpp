//
// Created by alejandro on 4/3/19.
//

#include "LinkedList.h"
#include<iostream>

UTEC::LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

bool UTEC::LinkedList::empty(){
    return head == nullptr;
}

UTEC::Node* UTEC::LinkedList::getHead(){
    return head;
}

UTEC::Node* UTEC::LinkedList::getTail(){
    return tail;
}

int UTEC::LinkedList::getSize(){
    int count = 0;
    Node* current = head;
    if(empty()){return 0;}
    do{
        count++;
        current = current->next;
    }while(current->next!=nullptr);
    return ++count;

}

void UTEC::LinkedList::print(int pos) {
    Node *current = head;
    int count = 0;
    if(pos>=getSize()){
        std::cout<<"Position out of list.\n";
    }
    else{
        while (pos != count++) {
            current = current->next;
        }
        while (current->next != nullptr) {
            std::cout << current->data.getID() << ", ";
            current = current->next;
        };
        std::cout << current->data.getID() << std::endl;
    }
}

void UTEC::LinkedList::add_head(Location location){
    Node* temp = new Node(location);
    if(empty()){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(Location location){
    Node* temp = new Node(location);
    if(empty()){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void UTEC::LinkedList::remove_head(){
    Node* current = head;
    if(current == nullptr){
        std::cout<<"List is empty.";
    }else {
        head->next = head;
    }
}

void UTEC::LinkedList::remove_tail(){
    Node* current = head;
    if(current == nullptr){
        std::cout<<"List is empty.";
    }else {
        while (true) {
            if ((current->next)->next == nullptr) {
                tail = current->next;
                break;
            }
            current = current->next;
        }
    }
}

void UTEC::LinkedList::addInPos(int pos, Location location){

    Node* current = head;
    Node* before = nullptr;
    Node* insert = new Node(location);
    int count = 0;

    if(pos==0 || head == nullptr){
        add_head(location);
    }

    else if(pos == getSize()){
        add_tail(location);
    }

    else if(pos>getSize() || pos<0){
        std::cout<<"Position out of list.\n";
    }
    else{
        while(pos!=count++){
            before = current;
            current = current->next;
        }
        before->next = insert;
        insert->next=current;

    }

}


void UTEC::LinkedList::deleteAll(Node* _head) {
    if (_head) {
    deleteAll(_head->next);
    delete _head;
    }
    head = nullptr;
    tail = nullptr;

}

UTEC::Node* UTEC::LinkedList::find_id(int position_id) {
    Node *current = head;
    while(current->data.getID()!=position_id){
        current = current->next;
    }
    return current;
}


UTEC::LinkedList::~LinkedList() {
    deleteAll(head);
}

