#include "application.hpp"
#include "widgets.hpp"

using namespace genv;

void application::event_loop(int x, int y) {
    start(x,y);

    event ev;
    int focus = -1;
    while(gin >> ev ) {
           if (ev.type == ev_mouse && ev.button==btn_left) {
               for (size_t i=0;i<widgets.size();i++) {
                   if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                           focus = i;
                   }
               }
           }

           if (focus!=-1) {
               widgets[focus]->handle(ev);
           }
           for (Widget * w : widgets) {
               w->draw();
           }
           gout << refresh;
       }
   }


void application::register_widget(Widget * w){
    widgets.push_back(w);
}

void application::start(int x, int y){
    gout.open(x,y);
    gout.load_font("LiberationSans-Regular.ttf",25);
    gout<< move_to(0,0) << color(0,0,255) << box(x-200,y)
        << move_to(x-200,0) << color(0,0,150) << box(200,y);
}
