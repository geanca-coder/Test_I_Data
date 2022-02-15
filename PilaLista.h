//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_PILALISTA_H
#define STACK_PILALISTA_H

#include "List.h"
#include "StackEmpty.h"
template <class Type>
class PilaLista{
private:
    List<Type>* list;
    int n;
public:
    PilaLista();
    ~PilaLista();
    int size();
    bool empty() const;
    Type *top() ;
    void push(Type * type);
    void pop( ) ;
    string toString();
};

template<class Type>
PilaLista<Type>::PilaLista() :list(new List<Type>), n(0){

}

template<class Type>
PilaLista<Type>::~PilaLista() {
    delete list;
}

template<class Type>
int PilaLista<Type>::size() {
    return n;
}

template<class Type>
bool PilaLista<Type>::empty() const {
    return  n ==0;
}

template<class Type>
Type *PilaLista<Type>::top()
{
    if(empty())
        throw StackEmpty("top sobre stack vacio");
    return list->inicio();
}

template<class Type>
void PilaLista<Type>::push(Type *type) {
    n++;
    list->agregaInicio(type);
}

template<class Type>
void PilaLista<Type>::pop()
{

    if(empty())
        throw StackEmpty("El stack esta vacio");
    list->borraInicio();
    n--;
}

template<class Type>
string PilaLista<Type>::toString() {
    stringstream ss;
    ss<<list->toString();
    return ss.str();
}


#endif //STACK_PILALISTA_H
