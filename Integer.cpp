//
// Created by geanc on 23 dic. 2021.
//

#include "Integer.h"

Integer::Integer(int integer) : integer(integer) {}

Integer::~Integer() {

}

int Integer::getInteger() const {
    return integer;
}

void Integer::setInteger(int integer)
{
    Integer::integer = integer;
}
ostream &operator<<(ostream &os, const Integer &integer) {
    os << integer.integer;
    return os;
}

