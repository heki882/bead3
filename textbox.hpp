#ifndef TEXTKBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "sstream"

class TextBox : public Widget {
public:
    int _textsize;
    std::string _stringwithin;
    bool _line;
    TextBox(int x, int y, int sx, int sy, int textsize, std::string stringwithin, bool line);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
