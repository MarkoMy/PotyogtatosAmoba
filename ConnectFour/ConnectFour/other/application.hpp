#ifndef APPLICATION_HPP
#define APPLICATION_HPP

class Widget;

#include <vector>
#include <string>

class application
{
public:
    void event_loop(int, int);
    void register_widget(Widget*);
    void start(int, int);
protected:
    std::vector<Widget*> widgets;
    bool startCount = true;
};

#endif // APPLICATION_HPP
