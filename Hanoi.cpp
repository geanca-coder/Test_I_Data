//
// Created by geanc on 23 dic. 2021.
//

#include "Hanoi.h"
Hanoi::Hanoi(int n) {

    stack1 = new PilaLista<Integer>;
    stack2 = new PilaLista<Integer>;
    stack3 = new PilaLista<Integer>;
    for(int i = n-1; i >=0;i--)
    {
        stack1->push(new Integer((i+5)*pow((i+10),i+1)));
    }
}
Hanoi::Hanoi(){
    stack1 = new PilaLista<Integer>;
    stack2 = new PilaLista<Integer>;
    stack3 = new PilaLista<Integer>;
}

int Hanoi::getN() {
    return stack1->size()+stack2->size()+stack3->size();
}
void Hanoi::setN(int n) {
    for(int i = n-1; i >=0;i--)
    {
        stack1->push(new Integer((i+5)*pow((i+10),i+1)));
    }
}

void Hanoi::restart(int n) {
        delete stack1;
        delete stack2;
        delete stack3;
        stack1 = new PilaLista<Integer>;
        stack2 = new PilaLista<Integer>;
        stack3 = new PilaLista<Integer>;
        setN(n);
}
int Hanoi::minimoMovimientos(int n) {
    return pow(2,n)-1;
}

string Hanoi::solucionRecursiva(int n,string &message ,int t1, int t2, int t3){
    if(n==1) {
        message+= "Mover disco de la torre " + to_string(t1)+ " hacia la torre " +to_string(t3)+ "\n";
    }else{
        solucionRecursiva(n - 1, message,t1, t3, t2);
        message+= "Mover disco de la torre " + to_string(t1)+ " hacia la torre " +to_string(t3)+ "\n";
        solucionRecursiva(n-1,message,t2,t1,t3);
    }
    return message;
}
Hanoi::~Hanoi() {
    delete stack1;
    delete stack2;
    delete stack3;
}

string Hanoi::toString() {
    stringstream ss;

    ss << stack1->toString()<<endl;
    ss << stack2->toString()<<endl;
    ss << stack3->toString()<<endl;

    return ss.str();
}

PilaLista<Integer> *Hanoi::getStack1() const {
    return stack1;
}

void Hanoi::setStack1(PilaLista<Integer> *stack1) {
    Hanoi::stack1 = stack1;
}

PilaLista<Integer> *Hanoi::getStack2() const {
    return stack2;
}

void Hanoi::setStack2(PilaLista<Integer> *stack2) {
    Hanoi::stack2 = stack2;
}

PilaLista<Integer> *Hanoi::getStack3() const {
    return stack3;
}

void Hanoi::setStack3(PilaLista<Integer> *stack3) {
    Hanoi::stack3 = stack3;
}

string Hanoi::makeMove(int from, int to) {
    string message = "Ingreso exitoso!";
    if (from == 1 and to == 2){
        if(!stack1->empty()){
            if(stack2->empty()) {
                stack2->push(stack1->top());
                stack1->pop();
                return message;
            }
            if(stack2->top()->getInteger() > stack1->top()->getInteger()){
                stack2->push(stack1->top());
                stack1->pop();
                return message;
            }else{
                message = "MOVIMIENTO INVALIDO";
                return message;
            }
        }else {
            message = "MOVIMIENTO INVALIDO";
            return message;
        }
    }
    if (from == 1 and to == 3){
        if(!stack1->empty()){
            if(stack3->empty()) {
                stack3->push(stack1->top());
                stack1->pop();
                return message;
            }
            if(stack3->top()->getInteger() > stack1->top()->getInteger()){
                stack3->push(stack1->top());
                stack1->pop();
                return message;
            }else{
                message = "MOVIMIENTO INVALIDO";
                return message;
            }
        }else {
            message = "MOVIMIENTO INVALIDO";
            return message;
        }
    }

    if (from == 2 and to == 1){
        if(!stack2->empty()){
            if(stack1->empty()) {
                stack1->push(stack2->top());
                stack2->pop();
                return message;
            }
            if(stack1->top()->getInteger() > stack2->top()->getInteger()){
                stack1->push(stack2->top());
                stack2->pop();
                return message;
            }else{
                message = "MOVIMIENTO INVALIDO";
                return message;
            }
        }else {
            message = "MOVIMIENTO INVALIDO";
            return message;
        }
    }
    if (from == 2 and to == 3){
        if(!stack2->empty()){
            if(stack3->empty()) {
                stack3->push(stack2->top());
                stack2->pop();
                return message;
            }
            if(stack3->top()->getInteger() > stack2->top()->getInteger()){
                stack3->push(stack2->top());
                stack2->pop();
                return message;
            }else{
                message = "MOVIMIENTO INVALIDO";
                return message;
            }
        }else {
            message = "MOVIMIENTO INVALIDO";
            return message;
        }
    }
    if (from == 3 and to == 1){
        if(!stack3->empty()){
            if(stack1->empty()) {
                stack1->push(stack3->top());
                stack3->pop();
                return message;
            }
            if(stack1->top()->getInteger() > stack3->top()->getInteger()){
                stack1->push(stack3->top());
                stack3->pop();
                return message;
            }else{
                message = "MOVIMIENTO INVALIDO";
                return message;
            }
        }else {
            message = "MOVIMIENTO INVALIDO";
            return message;
        }
    }
    if (from == 3 and to == 2){
        if(!stack3->empty()){
            if(stack2->empty()) {
                stack2->push(stack3->top());
                stack3->pop();
                return message;
            }
            if(stack2->top()->getInteger() > stack3->top()->getInteger()){
                stack2->push(stack3->top());
                stack3->pop();
                return message;
            }else{
                message = "MOVIMIENTO INVALIDO";
                return message;
            }
        }else {
            message = "MOVIMIENTO INVALIDO";
            return message;
        }
    }
    return message;
}

bool Hanoi::finished() {
    return stack1->empty() and stack2->empty();
}
