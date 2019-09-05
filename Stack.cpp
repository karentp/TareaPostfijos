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

void Stack::push(int data){

    if(isEmpty()) top= new Node(data);
    else{
        Node * newTop = new Node(data);
        newTop->next = top;
        top = newTop;
    }
}
