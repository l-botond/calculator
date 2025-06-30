#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Widget.hpp>
#include "functional"
#include "graphics.hpp"
#include "string"
#include "vector"


class Button : public Widget
{
    public:
        Button(App*, int, int, int, int, std::string, std::function<void()>);
        void draw() const override;
        void handle(genv::event) override;
        void push();
        void unpush();
        void action();

    protected:
        std::string _label;
        bool _pushed;
        std::function<void()> _f;

    private:
};

#endif // BUTTON_HPP
