#ifndef MENUWIDGET_HPP_INCLUDED
#define MENUWIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>

class MenuWidget : public Widget {
protected:
    bool _checked;
public:
    std::vector<std::string> menupoints;
    bool adding = false;
    std::string wat2add = "";
    int _min = 0;
    int _max;
    int chosenone = -1;
    MenuWidget(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void _fill() ;
    virtual void edges() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
};


#endif
