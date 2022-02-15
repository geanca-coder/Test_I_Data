//
// Created by geanc on 23 dic. 2021.
//

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include "Hanoi.h"
#include "Validate.h"
class Interface {
private:
    Hanoi* game;
public:
    Interface();
    void menuPrincipal();
    void menuJugar();
    ~Interface();
};


#endif //STACK_INTERFACE_H
