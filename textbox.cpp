#include "textbox.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
using namespace genv;

TextBox::TextBox(int x, int y, int sx, int sy, int textsize, std::string stringwithin, bool line)
    : Widget(x,y,sx,sy)
{
    _textsize = textsize;
    _stringwithin = stringwithin;
    _line = line;
}

void TextBox::draw() const
{
    if(_line == true)
    {
        gout << move_to(_x-10, _y-10) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2-10, _y+2-10) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout << move_to(_x,_y) << color(255,255,255) << font("BOOKOS.ttf",_textsize) << text(_stringwithin);
    }
    if(_line == false)
    {
        gout << move_to(_x,_y) << color(255,255,255) << font("BOOKOS.ttf",_textsize) << text(_stringwithin);
    }

}

void TextBox::handle(event ev)
{
/*    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
*/
}
