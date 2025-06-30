#include "graphics.hpp"
#include "Widget.hpp"
#include "App.hpp"
#include "Button.hpp"
#include "Screen.hpp"
#include "Calculator.hpp"
using namespace genv;
using namespace std;

class MyApp: public App
{
public:
    MyApp(int w, int h):
        App(w, h), op(0)
    {
        sc = new Screen(this, 10, 10, 280, 60);

        for(int i = 0; i < 9; i++)
        {
            numbtns.push_back(new Button(this,
                                       10 + 70 * (i % 3),
                                       80 + 70 * (i / 3), 60, 60,
                                       to_string(i + 1),
                                       [=](){numeric(i + 1);                //[=] érték szerint átadás
                                            update();}));
        }

            add = new Button(this,
                           230, 80, 60, 60,
                           "+",
                           [&](){operation(ADD);
                                update();});

            sub = new Button(this,
                           230, 150, 60, 60,
                           "-",
                           [&](){operation(SUB);
                                update();});

            mul = new Button(this,
                           230, 220, 60, 60,
                           "*",
                           [&](){operation(MUL);
                                update();});

            div = new Button(this,
                           230, 290, 60, 60,
                           "/",
                           [&](){operation(DIV);
                                update();});

            pow = new Button(this,
                           10, 290, 60, 60,
                           "^",
                           [&](){operation(POW);
                                update();});

            eq = new Button(this,
                          230, 360, 60, 60,
                          "=",
                          [&](){operation(EQ);
                                update();});

    }

    void numeric(int n)
    {
        op = op * 10 + n;

        calc.addNumber(op);
    }

    void operation(State oper)
    {
        calc.operation(oper);
    }

    void update()
    {
        op = calc.result();

        sc->setText(to_string(op));
    }

protected:
    Calculator calc;

    Screen *sc;
    vector<Button*> numbtns;

    Button *add, *sub, *mul, *div, *eq, *pow;

    int op;
};

int main()
{

    MyApp App(400, 600);

    App.event_loop();

    return 0;
}
