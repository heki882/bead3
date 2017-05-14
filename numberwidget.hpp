#ifndef NUMBERWIDGET_HPP_INCLUDED
#define NUMBERWIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>

class NumberWidget : public Widget {
protected:
    bool _plus;
	bool _minus;
public:
    std::string stringwithin;
	int numberwithin;
	int _rangemin;
	int _rangemax;
    NumberWidget(int x, int y, int sx, int sy, int rangemin, int rangemax);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual void plusone();
    virtual void minusone();
};


#endif
