//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_HANOI_H
#define STACK_HANOI_H
#include "PilaLista.h"
#include "Integer.h"
#include <cmath>
class Hanoi {
private:
    PilaLista<Integer>* stack1;
    PilaLista<Integer>* stack2;
    PilaLista<Integer>* stack3;
public:
    explicit Hanoi(int n);
    Hanoi();

    string toString();

    string solucionRecursiva(int n, string &message, int t1=1, int t2=2, int t3=3);

    int minimoMovimientos(int n);
    void setN(int n);
    int getN();
    void restart(int n);
    string makeMove(int from, int to);
    bool finished();

    PilaLista<Integer> *getStack1() const;

    void setStack1(PilaLista<Integer> *stack1);

    PilaLista<Integer> *getStack2() const;

    void setStack2(PilaLista<Integer> *stack2);

    PilaLista<Integer> *getStack3() const;

    void setStack3(PilaLista<Integer> *stack3);

    ~Hanoi();

};


#endif //STACK_HANOI_H
