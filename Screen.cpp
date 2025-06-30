#include "Screen.hpp"
#include "graphics.hpp"
#include "Widget.hpp"

using namespace genv;

Screen::Screen(App* parent, int x, int y, int sx, int sy) :
    Widget(parent,x,y,sx,sy), _text("0")
{

}

void Screen::draw() const
{
    gout.load_font("LiberationSans-Regular.ttf", 48);

    gout << move_to(_x, _y)
         << color(255, 255, 255)
         << box_to(_size_x + 10, _size_y)
         << color(0, 0, 0)
         << move_to(_x + _size_x - 5 - gout.twidth(_text),
                    _y + 5)
         << text(_text);
}

void Screen::handle(genv::event)
{

}

void Screen::setText(std::string text)
{
    _text = text;
}
