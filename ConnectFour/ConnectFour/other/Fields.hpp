#ifndef FIELDS_H
#define FIELDS_H

#include "widgets.hpp"

#include <functional>

enum field{YELLOW,RED,EMPTY};

class Fields : public Widget
{
public:
    Fields(application*, int x, int y, int sx, int sy, int szin, bool checked, std::function<void()> f);
    virtual ~Fields(){

    };

    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual bool is_checked();
    virtual void FieldSetter(int x);

protected:
    std::function<void()> _f;
    bool _checked;
    int _r;
    int _szin;
};

#endif // FIELDS_H
