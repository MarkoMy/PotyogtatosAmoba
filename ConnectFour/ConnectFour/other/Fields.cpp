#include "Fields.hpp"
#include "widgets.hpp"


using namespace genv;
using namespace std;

Fields::Fields(application* parent, int x, int y, int sx, int sy, int szin, bool checked,std::function<void()> f):
    Widget(parent,x,y,sx,sy) , _szin(szin), _checked(checked), _f(f)
{
    _r= _size_x/2;
}

void Fields::draw() const
{
    if(_szin == YELLOW)
    gout << color(255,255,0);
    else if(_szin == RED)
    gout << color(255,0,0);
    else if(_szin == EMPTY)
	gout <<color (255,255,255);

    for (int i = _x; i < _x + 2 * _r; i++) {
        for (int j = _y; j < _y + 2 * _r; j++) {
            int dx = i - (_x + _r);
            int dy = j - (_y + _r);
            if (dx * dx + dy * dy <= (_r-10) * (_r-10)) {
                gout << move_to(i, j) << dot;
            }
        }
    }
}

void Fields::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _f();
    }
}

bool Fields::is_checked()
{
    return _checked;
}

void Fields::FieldSetter(int x){
    _szin = x;
}
