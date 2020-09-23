//
// Created by Max Yu on 9/22/20.
//

#include "IllegalGameStateException.h"

IllegalGameStateException::IllegalGameStateException(const char* msg) {
    IllegalGameStateException::msg = msg;
}

const char *IllegalGameStateException::what() const noexcept {
    return msg;
}
