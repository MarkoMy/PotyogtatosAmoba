#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include "application.hpp"

class Widget {
protected:
    application*_parent;
    int _x, _y, _size_x, _size_y;
public:
    Widget(application*,int x, int y, int sx, int sy);
    virtual ~Widget(){

    }
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGETS_HPP_INCLUDED
