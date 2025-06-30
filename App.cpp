#include "App.hpp"

using namespace genv;

App::App(int w, int h)
{
    gout.open(w, h);

    for(Widget* w : widget)
        w->draw();

    gout << refresh;
}

void App::event_loop()
{
    event ev;
    int focus = -1;
    while(gin >> ev)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            for(size_t i = 0; i < widget.size(); i++)
            {
                if(widget[i]->selected(ev.pos_x, ev.pos_y))
                    focus = i;
            }
        }
        if(focus != -1)
            widget[focus]->handle(ev);

        for(Widget* w : widget)
            w->draw();

        gout << refresh;
    }
}

void App::registerWidget(Widget* w)
{
    widget.push_back(w);
}
