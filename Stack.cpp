#include <cstdlib>
#include <iostream>
#include "Stack.h"

using namespace std;

bool Stack:: isEmpty(){
    return top== nullptr;
}

//Borrar al inicio
Node* Stack::pop(){

    Node* deleted= top;
    if(!isEmpty()){
        top=top->next;
        deleted->next= nullptr;
    }
    return deleted;
}

Node* Stack::peek(){
    return top;
}

//insertar al inicio

void Stack::push(char data){

    if(isEmpty()) top= new Node(data);
    else{
        Node * newTop = new Node(data);
        newTop->next = top;
        top = newTop;
    }
}

void Stack::pushInt(double data){

    if(topInt==nullptr) topInt= new NodeInt(data);
    else{
        NodeInt * newTop = new NodeInt(data);
        newTop->next = topInt;
        topInt = newTop;
    }
}

NodeInt* Stack::popInt(){
    NodeInt * deleted= topInt;
    if(topInt!=nullptr){
        topInt=topInt->next;
        deleted->next= nullptr;
    }
    return deleted;
}
