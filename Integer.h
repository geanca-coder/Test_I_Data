//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_INTEGER_H
#define STACK_INTEGER_H


#include <iostream>
#include <sstream>
using namespace std;
class Integer {
private:
    int integer;
public:
    explicit Integer(int integer);

    int getInteger() const;

    void setInteger(int integer);
    string toString();

    friend ostream &operator<<(ostream &os, const Integer &integer);

    virtual ~Integer();

};


#endif //STACK_INTEGER_H
