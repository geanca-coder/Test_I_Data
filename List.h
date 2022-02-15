//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_LIST_H
#define STACK_LIST_H
#include "Node.h"
template <class Type>
class List{
private:
    Node<Type> *head;
    int size;
public:
    List();
    ~List();
    string toString();
    void agregaFinal(Type*);
    void agregaInicio(Type*);
    bool borrar(Type*, string &);
    int length();
    Node<Type>* at(int );
    Type * inicio();
    void borraInicio();

};
template <class Type>
Node<Type> * List<Type>::at(int i) {

    Node<Type>* temp = head->getSiguiente();

    if(i>size){
        return nullptr;
    }else{
        int j = 0;
        while(j<=i){
            temp = temp->getSiguiente();
            j++;
        }
        return temp;
    }
}
template <class Type>
List<Type>::List(){
    head = new Node <Type>;
}

template<class Type>
List<Type>::~List() {
    Node <Type> *temp;
    Node <Type> *anterior;
    if(head->getSiguiente() == nullptr){
        delete head;
    }else{
        while (head->getSiguiente() != nullptr){
            temp = head;
            while (temp->getSiguiente() != nullptr){
                anterior = temp;
                temp = temp->getSiguiente();
            }
            anterior->setSiguiente(nullptr);
            delete temp;
        }
    }
}

template<class Type>
string List<Type>::toString() {
    stringstream ss;
    Node <Type> *temporal = head;
    if(temporal->getSiguiente() == nullptr){
        ss << "-----|" << endl;
    }else{
        temporal = temporal->getSiguiente();
        do{
            ss << temporal->toString();
            ss << "---";
            temporal = temporal->getSiguiente();
        }while(temporal != nullptr);
        ss << "|" << endl;
    }
    return ss.str();
}

template<class Type>
void List<Type>::agregaInicio(Type *p) {
    Node <Type> *nuevo = new Node <Type>;
    nuevo->setDato(p);
    nuevo->setSiguiente(head->getSiguiente());
    head->setSiguiente(nuevo);
    size++;
}

template <class Type>
bool List<Type>::borrar(Type* p, string &mensaje) {
    Node <Type> *temp = head;
    Node <Type> *anterior;

    if(temp->getSiguiente() == nullptr){
        return false;
    }
    if(temp->getDato() == p){
        head->setSiguiente(temp->getSiguiente());
        delete temp;
        mensaje = "Borrado realizado exitosamente \n ";
        return true;
    }else{
        while(temp != nullptr){
            anterior = temp;
            temp = temp->getSiguiente();
            if (temp == nullptr){
                mensaje = "Info no encontrada \n";
                return false;
            }
            if(temp->getDato() == p){
                anterior->setSiguiente(temp->getSiguiente());
                delete temp;
                mensaje = "Borrado exitoso \n";
                size--;
                return true;

            }
        }
    }
}
template<class Type>
int List<Type>::length() {
    return size;
}
template <class Type>
void List<Type>::agregaFinal(Type *p) {
    Node <Type> *nuevo = new Node <Type>;
    nuevo->setDato(p);
    nuevo->setSiguiente(nullptr);
    Node <Type> *temp = head;
    if(temp == nullptr){
        head->setSiguiente(nuevo);
    }else{
        while (temp->getSiguiente() != nullptr){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevo);
    }
    size++;
}

template<class Type>
Type *List<Type>::inicio() {
    Node<Type> *temp = head;
    if(temp->getSiguiente() != nullptr){
        temp = temp->getSiguiente();
        return temp->getDato();
    }
    return nullptr;
}

template<class Type>
void List<Type>::borraInicio() {
    Node<Type> * temp = head;
    if(temp->getSiguiente() != nullptr){
        temp = temp->getSiguiente();
        head->setSiguiente(temp->getSiguiente());
        delete temp;
    }
}



#endif //STACK_LIST_H
