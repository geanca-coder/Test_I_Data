//
// Created by geanc on 23 dic. 2021.
//

#include "RunTimeException.h"

string RunTimeException::getMessage() const {
   return error+"\n";
}

RunTimeException::RunTimeException(const string &error) {
    this->error = error;
}
