#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>

using namespace std;

//Estructura del Nodo para la pila

struct Node {
       char data;
       Node* next;// puntero para enlazar nodos
       Node(char d) {
         data = d;
         next = nullptr;
       }
};

struct NodeInt {
       double data;
       NodeInt* next;// puntero para enlazar nodos
       NodeInt(double d){
         data = d;
         next = nullptr;
       }
};

//Estructura de la Pila

struct Stack{
    Node *top;
    NodeInt *topInt;
    Stack(){
        top = nullptr;
        topInt= nullptr;
    }
    bool isEmpty();
    Node* pop();
    NodeInt* popInt();
    void push(char);
    void pushInt(double);
    Node* peek();

};





#endif // STACK_H
