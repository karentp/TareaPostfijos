#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>

using namespace std;

//Estructura del Nodo para la pila

struct Node {
       int data;
       Node* next;// puntero para enlazar nodos
       Node(int d) {
         data = d;
         next = nullptr;
       }
};

//Estructura de la Pila

struct Stack{
    Node *top;
    Stack(){
        top = nullptr;
    }
    bool isEmpty();
    Node* pop();
    void push(int);
    Node* peek();

};





#endif // STACK_H
