#pragma once

#include <sstream>
#include <string>
#include <exception>

#include "CoreMinimal.h"
#include "ClassUtils.h"
#include "Screen.h"

template <class T>
class NullPointerException : public std::exception {
private:
    T* Reference;

public:
    NullPointerException(T* reference) { this->Reference = reference; }

    const char* what() const throw() {
        std::string ClassName = ClassUtils::ClassNameOf<T>(Reference);
        std::stringstream messageStream;
        messageStream << "Error: Null " << ClassName << " reference!";
        std::string message = messageStream.str();
        return message.c_str();
    }
};
