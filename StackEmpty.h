//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_STACKEMPTY_H
#define STACK_STACKEMPTY_H

#include "RunTimeException.h"
class StackEmpty: public RunTimeException{
public:
    explicit StackEmpty(const string &error);

};


#endif //STACK_STACKEMPTY_H
