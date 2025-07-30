#ifndef EXCEPTIONS
#define EXCEPTIONS

#include "includes.hpp"

class NotFound : public exception {
public:
    const char* what() const noexcept override {
        return NOT_FOUND.c_str();
    }
};

class BadRequest : public exception {
public:
    const char* what() const noexcept override {
        return BAD_REQUEST.c_str();
    }
};

class Empty : public exception {
public:
    const char* what() const noexcept override {
        return EMPTY.c_str();
    }
};

#endif
