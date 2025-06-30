#include "Calculator.hpp"
#include "graphics.hpp"

Calculator::Calculator() : state(OTH), op2(0)
{

}

void Calculator::addNumber(int n)
{
    op2 = n;
}

void Calculator::operation(State op)
{
    if(op == EQ)
    {
        switch(state)
        {
        case ADD:
            op2 += op1;
            break;
        case SUB:
            op2 =  op1 - op2;
            break;
        case DIV:
            op2 = op1 / op2;
            break;
        case MUL:
            op2 *= op1;
            break;
        case POW:
            int op2_old = op2;
            op2 = 1;
            for(int i = 0; i < op2_old; i++)
                op2 *= op1;
            break;
        }
    }
    else
    {
        op1 = op2;
        state = op;
        op2 = 0;
    }
}

int Calculator::result()
{
    return op2;
}
