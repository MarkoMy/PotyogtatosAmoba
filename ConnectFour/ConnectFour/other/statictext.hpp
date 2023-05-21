#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widgets.hpp"

#include <functional>

enum tfield{Y,R};

class StaticText : public Widget
{
protected:
    int _iText;
public:
    StaticText(application*,int, int, int, int, int _iText);
    virtual ~StaticText(){

    }
    virtual void draw() const;
    virtual void handle(genv::event);
    virtual void TextSetter(int);
};

#endif // STATICTEXT_HPP
