#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
public:
    bool _checkedbyplayerone;
    bool _checkedbyplayertwo;
	int ertek;
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void checkedbyplayerone();
    virtual void checkedbyplayertwo();
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
