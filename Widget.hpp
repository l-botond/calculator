#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class App;

class Widget
{
    public:
        Widget(App*, int, int, int, int);
        virtual bool selected(int mouse_x, int mouse_y);
        virtual void draw() const = 0;
        virtual void handle(genv::event) = 0;


    protected:
        int _x, _y, _size_x, _size_y;
        App* _parent;

    private:
};

#endif // WIDGET_HPP
