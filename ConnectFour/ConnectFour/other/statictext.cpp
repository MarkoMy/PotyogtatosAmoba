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
    kText = "Sarga jon";
    else if(_iText == R)
    kText = "Piros jon";

    gout<< move_to(_x,_y) << color(0,0,255) << box(_size_x,_size_y)
        << move_to(_x+(_size_x - gout.twidth(kText))/2,
                   _y+(_size_y - gout.cascent()-gout.cdescent())/2)
        <<color(0,0,0)
        <<text(kText);
}

void StaticText::handle(event ev){}

void StaticText::TextSetter(int s){
    _iText = s;
}
