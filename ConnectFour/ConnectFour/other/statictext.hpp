#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widgets.hpp"

#include <functional>

enum tfield{Y,R};

class StaticText : public Widget
{
protected:
    int _iText;
    std::function<void()> _f;
public:
    StaticText(application*,int, int, int, int,int iText, std::function<void()> f);
    virtual ~StaticText(){

    }
    virtual void draw() const;
    virtual void handle(genv::event);
};

#endif // STATICTEXT_HPP
