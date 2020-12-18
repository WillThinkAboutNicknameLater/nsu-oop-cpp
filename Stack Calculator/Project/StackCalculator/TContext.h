#pragma once

#include <iostream>
#include <stack>
#include <map>

class TContext {
public:
    bool stackIsEmpty() const;

    void pushStackValue(double number);

    double popStackValue();

    size_t getStackSize() const;

    double getStackTopValue() const;

    void addVariable(std::string& name, double value);
    
    double getValueOfVariable(std::string& name) const;

private:
	std::stack<double> _stack;
	std::map<std::string, double> _variables;
};

