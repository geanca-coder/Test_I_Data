//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_RUNTIMEEXCEPTION_H
#define STACK_RUNTIMEEXCEPTION_H

#include <iostream>
using namespace std;
class RunTimeException{
private:
    string error;

public:
    explicit RunTimeException(const string & error);
    string getMessage()const;
};


#endif //STACK_RUNTIMEEXCEPTION_H
