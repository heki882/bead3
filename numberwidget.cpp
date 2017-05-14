#include "numberwidget.hpp"
#include "graphics.hpp"
#include "iostream"
#include "sstream"
#include "fstream"
using namespace std;
using namespace genv;

string converter(int number)
{
    string str;
    stringstream ss;
    ss << number;
    ss >> str;
    return str;
}

NumberWidget::NumberWidget(int x, int y, int sx, int sy, int rangemin, int rangemax)
    : Widget(x,y,sx,sy)
{
    _plus=false;
    numberwithin = rangemin;
    _rangemin = rangemin;
    _rangemax = rangemax;
    stringwithin = converter(numberwithin);
}

void NumberWidget::plusone()
{
    if(numberwithin < _rangemax)
    {
        numberwithin +=1;
        stringwithin = converter(numberwithin);
    }
}

void NumberWidget::minusone()
{
    if(numberwithin > _rangemin)
    {
        numberwithin -=1;
        stringwithin = converter(numberwithin);
    }
}

void NumberWidget::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << color(255,255,255)
         << move_to(_x + _size_x - (_size_y / 2), _y) << line_to(_x + _size_x - (_size_y / 2), _y + _size_y - 1)
         << move_to(_x + _size_x - (_size_y / 2), _y + (_size_y / 2)) << line_to(_x + _size_x - 1, _y + (_size_y / 2))
         << move_to(_x + 10 / 2 ,_y + (_size_y / 2) + 1) << color(255,255,255) << text(stringwithin)
         << move_to(_x + _size_x - (_size_y / 2) + (_size_x / 10) - 2, _y + (_size_y/3)  + 2) << text("+")
         << move_to(_x + _size_x - (_size_y / 2) + (_size_x / 10) - 2, _y + _size_y  -10 ) << text("-");
}

void NumberWidget::handle(event ev)
{
    if(gout.twidth(stringwithin) > _size_x - 35)
    {
        _size_x = gout.twidth(stringwithin) + 35;
    }
    if(ev.keycode == key_f1)
    {
        ofstream myfile;
        myfile.open ("Widgets.txt", ofstream::out | ofstream::app);
        myfile << "Displayed number: " << numberwithin << endl;
        myfile.close();
    }
    if (ev.pos_x>(_x + _size_x - (_size_y / 2)) && ev.pos_x<_x+_size_x && ev.pos_y>_y && ev.pos_y < (_y + (_size_y / 2)) && ev.button == btn_left) {
            NumberWidget::plusone();
    }
    if(ev.keycode == key_up)
    {
        NumberWidget::plusone();
    }
    if(ev.button == btn_wheelup)
    {
        NumberWidget::plusone();
    }
    if (ev.pos_x>(_x + _size_x - (_size_y / 2)) && ev.pos_x<_x+_size_x && ev.pos_y < _y + _size_y && ev.pos_y > (_y + (_size_y / 2)) && ev.button==btn_left) {
            NumberWidget::minusone();
    }
    if(ev.keycode == key_down)
    {
        NumberWidget::minusone();
    }
    if(ev.button == btn_wheeldown)
    {
        NumberWidget::minusone();
    }
}
bool NumberWidget::is_checked() const
{
    return _plus;
}
