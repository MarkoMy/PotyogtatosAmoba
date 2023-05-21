#include "Button.hpp"

using namespace genv;
Button::Button(application* parent,int x, int y, int sx, int sy, std::string text, std::function<void()> f):
    Widget(parent,x,y,sx,sy), _text(text), _f(f)
{

}


void Button::draw() const{
    gout << move_to(_x,_y) << color(200,200,200) << box(_size_x,_size_y)<<
            move_to(_x+(_size_x - gout.twidth(_text))/2,
                    _y+(_size_y - gout.cascent()-gout.cdescent())/2)
         <<color(0,0,0)
         <<text(_text);
}

void Button:: handle(event ev){
    if(ev.type == ev_mouse && ev.button == btn_left && is_selected(ev.pos_x,ev.pos_y)){
        _f();
    }
}

