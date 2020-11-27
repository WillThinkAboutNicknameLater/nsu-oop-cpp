#pragma once

#include <iostream>

class TErrorHandler : public std::exception {
protected:

    std::string _text;

public:

    virtual std::string what() = 0;

};

class TListIsEmpty : public TErrorHandler {
public:

    TListIsEmpty() {
        _text = "Error! List is empty.";
    }

    TListIsEmpty(std::string text) { 
        _text = text;
    }

    std::string what() { 
        return _text; 
    }

};

class TIncorrectPosition final : public TErrorHandler {
public:

    TIncorrectPosition() {
        _text = "Error! Incorrect position.";
    }

    TIncorrectPosition(std::string text) {
        _text = text;
    }

    std::string what() {
        return _text;
    }

};