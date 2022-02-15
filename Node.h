//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_NODE_H
#define STACK_NODE_H
#include <iostream>
#include <sstream>
using namespace std;
template <class Type>
class Node{
    Type *dato;
    Node *siguiente;

public:
    explicit Node(Type *dato = nullptr, Node*  siguiente  = nullptr);


    Type *getDato();

    void setDato(Type* dato);

    Node* getSiguiente();

    void setSiguiente(Node* siguiente);

    string toString();


};

template<class Type>
Node<Type>::Node(Type *dato, Node *siguiente): dato(dato), siguiente(siguiente) {

}

template<class Type>
Type *Node<Type>::getDato() {
    return dato;
}

template<class Type>
void Node<Type>::setDato(Type *dato) {
    this->dato = dato;
}

template<class Type>
Node<Type> *Node<Type>::getSiguiente() {
    return siguiente;
}

template<class Type>
void Node<Type>::setSiguiente(Node *siguiente) {
    this->siguiente = siguiente;
}
template<class Type>
string Node<Type>::toString() {
    stringstream ss;
    ss<<*dato;
    return ss.str();
}

#endif //STACK_NODE_H
