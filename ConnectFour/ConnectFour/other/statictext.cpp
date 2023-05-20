#include "statictext.hpp"
#include "graphics.hpp"
using namespace genv;

StaticText::StaticText(application* parent,int x, int y, int sx, int sy,int iText, std::function<void()> f)
    : Widget(parent,x,y,sx,sy), _iText(iText), _f(f)
{

}

void StaticText::draw() const{
    std::string kText;

    if(_iText == Y)
        kText = "Sárga";
    else if(_iText == R)
        kText = "Piros";
    /*else if(_iText == TIE)
        kText = "Döntetlen!";
    else if(_iText == WYELLOW)
        kText = "Sárga nyert!";
    else if(_iText == WRED)
        kText = "Piros nyert!";*/


    gout << move_to(_x,_y) << color(0,0,255) << box(_size_x,_size_y)<<
                move_to(_x+(_size_x - gout.twidth(kText))/2,
                        _y+(_size_y - gout.cascent()-gout.cdescent())/2)
             <<color(0,0,0)
             <<text(kText);
}

void StaticText::handle(event ev){
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _f();
    }
}
