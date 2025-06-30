#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "graphics.hpp"
#include "App.hpp"
#include "Button.hpp"

enum State
{
    ADD,
    SUB,
    DIV,
    MUL,
    EQ,
    OTH,
    POW,
    C
};


class Calculator
{
    public:
        Calculator();
        void addNumber(int);
        void operation(State);
        int result();

    protected:
        int op1, op2;
        State state;

    private:
};

#endif // CALCULATOR_HPP
