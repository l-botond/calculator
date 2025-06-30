#ifndef APP_HPP
#define APP_HPP
#include <vector>
#include "Widget.hpp"

class App
{
    public:
        App(int, int);
        void event_loop();
        void registerWidget(Widget*);

    protected:
        std::vector<Widget*> widget;

    private:
};

#endif // APP_HPP
