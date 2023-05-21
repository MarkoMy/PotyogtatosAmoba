#include "statictext.hpp"
#include "graphics.hpp"
using namespace genv;

StaticText::StaticText(application* parent,int x, int y, int sx, int sy, int iText)
    : Widget(parent,x,y,sx,sy), _iText(iText)
{

}

void StaticText::draw() const{
    std::string kText;
    if(_iText == Y)
    kText = "Sárga jön";
    else if(_iText == R)
    kText = "Piros jön";
    else if(_iText == D)
    kText = "Döntetlen";
    else if(_iText == YW)
    kText = "Sárga nyert!";
    else if(_iText == RW)
    kText = "Piros nyert!";

    gout<< move_to(_x,_y) << color(0,0,200) << box(_size_x,_size_y)
        << move_to(_x+(_size_x - gout.twidth(kText))/2,
                   _y+(_size_y - gout.cascent()-gout.cdescent())/2)
        <<color(255,255,255)
        <<text(kText);
}

void StaticText::handle(event ev){}

void StaticText::TextSetter(int s){
    _iText = s;
}
