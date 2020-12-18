#pragma once

#include <iostream>

class TErrorHandler : public std::exception {
public:
    virtual std::string what() = 0;

protected:
    std::string _text{ "Error! " };

};

class TStackIsEmpty : public TErrorHandler {
public:

    TStackIsEmpty() {
        _text += "Stack is empty.";
    }

    TStackIsEmpty(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TWrongStackSize : public TErrorHandler {
public:

    TWrongStackSize() {
        _text += "Wrong stack size.";
    }

    TWrongStackSize(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TWrongNumberOfArguments : public TErrorHandler {
public:

    TWrongNumberOfArguments() {
        _text += "Wrong number of arguments.";
    }

    TWrongNumberOfArguments(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TDivisionByZero : public TErrorHandler {
public:

    TDivisionByZero() {
        _text += "Division by zero.";
    }

    TDivisionByZero(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TNegativeNumber : public TErrorHandler {
public:

    TNegativeNumber() {
        _text += "Negative number.";
    }

    TNegativeNumber(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TWrongDataType : public TErrorHandler {
public:

    TWrongDataType() {
        _text += "Wrong data type.";
    }

    TWrongDataType(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TVariableDoesNotExist : public TErrorHandler {
public:

    TVariableDoesNotExist() {
        _text += "Variable does not exist.";
    }

    TVariableDoesNotExist(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TOperationNameIsTaken : public TErrorHandler {
public:

    TOperationNameIsTaken() {
        _text += "The operation name is taken.";
    }

    TOperationNameIsTaken(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

class TOperationDoesNotExist final : public TErrorHandler {
public:

    TOperationDoesNotExist() {
        _text += "Operation does not exist.";
    }

    TOperationDoesNotExist(std::string& text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};

