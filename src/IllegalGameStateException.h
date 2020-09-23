//
// Created by Max Yu on 9/22/20.
//

#ifndef STATEMACHINE_ILLEGALGAMESTATEEXCEPTION_H
#define STATEMACHINE_ILLEGALGAMESTATEEXCEPTION_H

#include <exception>

class IllegalGameStateException : public std::exception {
    virtual const char* what() const noexcept;
private:
    const char* msg;
public:
    explicit IllegalGameStateException(const char*);
};


#endif //STATEMACHINE_ILLEGALGAMESTATEEXCEPTION_H
