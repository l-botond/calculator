#include "Button.hpp"
#include "Widget.hpp"
#include "graphics.hpp"

using namespace genv;

Button::Button(App* parent,int x, int y, int sx, int sy, std::string label, std::function<void()> f) :
    Widget(parent,x,y,sx,sy), _label(label), _pushed(0), _f(f)
{

}

void Button::draw() const
{
    gout.load_font("LiberationSans-Regular.ttf", 48);

    int text_width = gout.twidth(_label);

    int text_height = gout.cascent() + gout.cdescent();

    gout << move_to(_x, _y)
         << color(128, 128, 128)
         << box(_size_x, _size_y)
         << color(255, 255, 255)
         << move_to(_x + (_size_x - text_width) / 2, _y + (_size_y + text_height) / 8 - gout.cdescent())
         << text(_label);

    if(_pushed)
    {
        gout << move_to(_x, _y)
             << color(128, 128, 128)
             << box(_size_x, _size_y)
             << color(0, 0, 0)
             << move_to(_x + (_size_x - text_width) / 2, _y + (_size_y + text_height) / 8 - gout.cdescent())
             << text(_label);
    }

    else
    {
        gout << move_to(_x, _y)
             << color(128, 128, 128)
             << box(_size_x, _size_y)
             << color(255, 255, 255)
             << move_to(_x + (_size_x - text_width) / 2, _y + (_size_y + text_height) / 8 - gout.cdescent())
             << text(_label);
    }
}

void Button::handle(genv::event ev)
{
    if(ev.type == ev_mouse)
    {
        if(ev.button == btn_left)
        {
            push();
            action();
        }
        if(ev.button == -btn_left)
            unpush();
    }
}

void Button::push()
{
    _pushed = 1;
}

void Button::unpush()
{
    _pushed = 0;
}

void Button::action()
{
    _f();
}
