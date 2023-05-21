#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widgets.hpp"
#include <functional>

class Button : public Widget
{
protected:
    std::string _text;
    std::function<void()> _f;
public:
    Button(application*,int x, int y, int sx, int sy,
           std::string, std::function<void()>);

    void action();
    void draw() const override;
    void handle(genv::event) override;
};

#endif // BUTTON_HPP
