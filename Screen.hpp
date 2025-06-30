#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <Widget.hpp>
#include "string"
#include "graphics.hpp"


class Screen : public Widget
{
    public:
        Screen(App*, int, int, int, int);
        void draw() const override;
        void handle(genv::event) override;
        void setText(std::string);

    protected:
        std::string _text;

    private:
};

#endif // SCREEN_HPP
