#include "menuwidget.hpp"
#include "graphics.hpp"
#include "iostream"
#include "sstream"
#include <time.h>
#include <random>
#include <cmath>
#include "fstream"
using namespace std;
using namespace genv;

MenuWidget::MenuWidget(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    MenuWidget::_fill();
    MenuWidget::edges();
}

void MenuWidget::_fill()
{
    for(int i = 0; i < 27; i++)
    {
        int a = rand() % 27;
        if(a == 0)
        {
            menupoints.push_back("a");
        }
        else if(a == 1)
        {
            menupoints.push_back("b");
        }
        else if(a == 3)
        {
            menupoints.push_back("c");
        }
        else if(a == 4)
        {
            menupoints.push_back("d");
        }
        else if(a == 5)
        {
            menupoints.push_back("e");
        }
        else if(a == 6)
        {
            menupoints.push_back("f");
        }
        else if(a == 7)
        {
            menupoints.push_back("g");
        }
        else if(a == 8)
        {
            menupoints.push_back("h");
        }
        else if(a == 9)
        {
            menupoints.push_back("i");
        }
        else if(a == 10)
        {
            menupoints.push_back("j");
        }
        else if(a == 11)
        {
            menupoints.push_back("k");
        }
        else if(a == 12)
        {
            menupoints.push_back("l");
        }
        else if(a == 13)
        {
            menupoints.push_back("m");
        }
        else if(a == 14)
        {
            menupoints.push_back("n");
        }
        else if(a == 15)
        {
            menupoints.push_back("o");
        }
        else if(a == 16)
        {
            menupoints.push_back("p");
        }
        else if(a == 17)
        {
            menupoints.push_back("q");
        }
        else if(a == 18)
        {
            menupoints.push_back("r");
        }
        else if(a == 19)
        {
            menupoints.push_back("s");
        }
        else if(a == 20)
        {
            menupoints.push_back("t");
        }
        else if(a == 21)
        {
            menupoints.push_back("u");
        }
        else if(a == 22)
        {
            menupoints.push_back("v");
        }
        else if(a == 23)
        {
            menupoints.push_back("w");
        }
        else if(a == 24)
        {
            menupoints.push_back("x");
        }
        else if(a == 25)
        {
            menupoints.push_back("y");
        }
        else if(a == 26)
        {
            menupoints.push_back("z");
        }
    }
}

void MenuWidget::edges()
{
    _max = ceil(((_size_y -25) / 23));
    if(_max > menupoints.size())
    {
        _max = menupoints.size();
    }
}


void MenuWidget::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y-25);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-25-4);

    gout << move_to(_x, _y+_size_y-25 - 2) << color(255,255,255) << box(_size_x,25);
    gout << move_to(_x + 2, _y+_size_y-25) << color(0,0,0) << box(_size_x - 4, 25-4);

    gout << move_to(_x + _size_x - 2,_y) << color(255,255,255) << box(25,25);
    gout << move_to(_x + _size_x,_y + 2) << color(0,0,0) << box(21,21);
    gout << move_to(_x + _size_x + 6,_y + 18) << color(255,255,255) << text("-");

    gout << move_to(_x + _size_x - 2,_y + _size_y-25 - 2) << color(255,255,255) << box(25,25);
    gout << move_to(_x + _size_x,_y +_size_y-25) << color(0,0,0) << box(21,21);
    gout << move_to(_x + _size_x + 6,_y + _size_y-25 + 15) << color(255,255,255) << text("+");

    if(adding == false)
    {
        gout << move_to(_x + 5, _y + _size_y-25 + 17) << color(255,255,255) << text("Add");
    }
    else
    {
        gout << move_to(_x + 5, _y + _size_y-25 + 17) << color(255,255,255) << text(wat2add + "|");
    }

    for(int i = 0; i < _max-_min; i++)
    {
        if(_min + i == chosenone)
        {
            gout << move_to(_x, _y + i*23) << color(255,255,255) << box(_size_x,25);
            gout << move_to(_x + 5, _y + i*23 + 17) << color(0,0,0) << text(menupoints[i + _min]);
        }
        else
        {
            gout << move_to(_x, _y + i*23) << color(255,255,255) << box(_size_x,25);
            gout << move_to(_x+2, _y+2 + i*23) << color(0,0,0) << box(_size_x-4, 25-4);
            gout << move_to(_x + 5, _y + i*23 + 17) << color(255,255,255) << text(menupoints[i + _min]);
        }
    }
}

void MenuWidget::handle(event ev)
{
    if( gout.twidth(wat2add) > _size_x - 15 )
    {
        _size_x = gout.twidth(wat2add) + 15;
    }
    if (ev.pos_x > (_x ) && ev.pos_x < (_x + _size_x) && ev.pos_y > (_y + _size_y-25 ) && ev.pos_y < (_y + _size_y-25 + 25) && ev.button==btn_left && adding == false) {
            adding = true;
    }
//DELETE gombbal ki lehet törölni a kijelölt elemet.
    if(ev.keycode == key_delete && chosenone >= 0 && menupoints.size() > 1)
    {
        menupoints.erase(menupoints.begin() + chosenone);
        chosenone = -1;
        _min = 0;
        MenuWidget::edges();
    }
//Bal egér gombbal tudunk kiválasztani, illetve a kiválasztást visszavonni.
    for(int i = 0; i < _max-_min; i++)
    {
        if (ev.pos_y > _y + i*23 && ev.pos_y < _y + 23 + i*23 && ev.pos_x > _x && ev.pos_x < _x + _size_x && ev.button == btn_left)
        {
            if(chosenone == _min + i)
            {
                chosenone = -1;
            }
            else
            {
                chosenone = _min + i;
            }
        }
    }
    if (ev.pos_x > (_x + _size_x - 2) && ev.pos_x < (_x + _size_x + 23) && ev.pos_y > (_y + _size_y-25 - 2) && ev.pos_y < (_y + _size_y-25 +23) && ev.button==btn_left) {
        if(_max < menupoints.size())
        {
            _min +=1;
            _max +=1;
        }
    }
//Görgövel / Fel-el is lehet görgetni a menüben
    if(ev.keycode == key_down)
    {
        if(_max < menupoints.size())
        {
            _min +=1;
            _max +=1;
        }
    }
    if(ev.button == btn_wheeldown)
    {
        if(_max < menupoints.size())
        {
            _min +=1;
            _max +=1;
        }
    }
//ESC-vel ki tudunk lépni az "Addingból"
    if(ev.keycode == key_escape && adding == true)
    {
        cout << "FALSE";
        adding = false;
    }

    if (ev.pos_x > (_x + _size_x - 2) && ev.pos_x < (_x + _size_x + 23) && ev.pos_y > (_y - 2) && ev.pos_y < (_y +23) && ev.button==btn_left) {
        if(_min - 1 > -1)
        {
            _min -=1;
            _max -=1;
        }
    }
    if(ev.keycode == key_up)
    {
        if(_min - 1 > -1)
        {
            _min -=1;
            _max -=1;
        }
    }
    if(ev.button == btn_wheelup)
    {
        if(_min - 1 > -1)
        {
            _min -=1;
            _max -=1;
        }
    }
//Ha elírnánk a hozzáadandó elemet, lehet törölni is betûket.
    if (adding == true)
    {
        if(ev.keycode == key_backspace)
        {
            if(wat2add.size() > 0)
            {
                wat2add.erase(wat2add.begin()+wat2add.size() - 1);
            }
        }
        if(ev.keycode == key_enter)
        {
            menupoints.push_back(wat2add);
            adding = false;
            wat2add.resize(0);
            _min = 0;
            MenuWidget::edges();
        }
        if(ev.keycode == key_space)
        {
            wat2add = wat2add + "  ";
        }
        if(ev.keycode == 97)
        {
            wat2add = wat2add + "a";
        }
        if(ev.keycode == 98)
        {
            wat2add = wat2add + "b";
        }
        if(ev.keycode == 99)
        {
            wat2add = wat2add + "c";
        }
        if(ev.keycode == 100)
        {
            wat2add = wat2add + "d";
        }
        if(ev.keycode == 101)
        {
            wat2add = wat2add + "e";
        }
        if(ev.keycode == 102)
        {
            wat2add = wat2add + "f";
        }
        if(ev.keycode == 103)
        {
            wat2add = wat2add + "g";
        }
        if(ev.keycode == 104)
        {
            wat2add = wat2add + "h";
        }
        if(ev.keycode == 105)
        {
            wat2add = wat2add + "i";
        }
        if(ev.keycode == 106)
        {
            wat2add = wat2add + "j";
        }
        if(ev.keycode == 107)
        {
            wat2add = wat2add + "k";
        }
        if(ev.keycode == 108)
        {
            wat2add = wat2add + "l";
        }
        if(ev.keycode == 109)
        {
            wat2add = wat2add + "m";
        }
        if(ev.keycode == 110)
        {
            wat2add = wat2add + "n";
        }
        if(ev.keycode == 111)
        {
            wat2add = wat2add + "o";
        }
        if(ev.keycode == 112)
        {
            wat2add = wat2add + "p";
        }
        if(ev.keycode == 113)
        {
            wat2add = wat2add + "q";
        }
        if(ev.keycode == 114)
        {
            wat2add = wat2add + "r";
        }
        if(ev.keycode == 115)
        {
            wat2add = wat2add + "s";
        }
        if(ev.keycode == 116)
        {
            wat2add = wat2add + "t";
        }
        if(ev.keycode == 117)
        {
            wat2add = wat2add + "u";
        }
        if(ev.keycode == 118)
        {
            wat2add = wat2add + "v";
        }
        if(ev.keycode == 119)
        {
            wat2add = wat2add + "w";
        }
        if(ev.keycode == 120)
        {
            wat2add = wat2add + "x";
        }
        if(ev.keycode == 121)
        {
            wat2add = wat2add + "y";
        }
        if(ev.keycode == 122)
        {
            wat2add = wat2add + "z";
        }

        if(ev.keycode == 65)
        {
            wat2add = wat2add + "A";
        }
        if(ev.keycode == 66)
        {
            wat2add = wat2add + "B";
        }
        if(ev.keycode == 67)
        {
            wat2add = wat2add + "C";
        }
        if(ev.keycode == 68)
        {
            wat2add = wat2add + "D";
        }
        if(ev.keycode == 69)
        {
            wat2add = wat2add + "E";
        }
        if(ev.keycode == 70)
        {
            wat2add = wat2add + "F";
        }
        if(ev.keycode == 71)
        {
            wat2add = wat2add + "G";
        }
        if(ev.keycode == 72)
        {
            wat2add = wat2add + "H";
        }
        if(ev.keycode == 73)
        {
            wat2add = wat2add + "I";
        }
        if(ev.keycode == 74)
        {
            wat2add = wat2add + "J";
        }
        if(ev.keycode == 75)
        {
            wat2add = wat2add + "K";
        }
        if(ev.keycode == 76)
        {
            wat2add = wat2add + "L";
        }
        if(ev.keycode == 77)
        {
            wat2add = wat2add + "M";
        }
        if(ev.keycode == 78)
        {
            wat2add = wat2add + "N";
        }
        if(ev.keycode == 79)
        {
            wat2add = wat2add + "O";
        }
        if(ev.keycode == 80)
        {
            wat2add = wat2add + "P";
        }
        if(ev.keycode == 81)
        {
            wat2add = wat2add + "Q";
        }
        if(ev.keycode == 82)
        {
            wat2add = wat2add + "R";
        }
        if(ev.keycode == 83)
        {
            wat2add = wat2add + "S";
        }
        if(ev.keycode == 84)
        {
            wat2add = wat2add + "T";
        }
        if(ev.keycode == 85)
        {
            wat2add = wat2add + "U";
        }
        if(ev.keycode == 86)
        {
            wat2add = wat2add + "V";
        }
        if(ev.keycode == 87)
        {
            wat2add = wat2add + "W";
        }
        if(ev.keycode == 88)
        {
            wat2add = wat2add + "X";
        }
        if(ev.keycode == 89)
        {
            wat2add = wat2add + "Y";
        }
        if(ev.keycode == 90)
        {
            wat2add = wat2add + "Z";
        }
        if(ev.keycode == 48)
        {
            wat2add = wat2add + "0";
        }
        if(ev.keycode == 49)
        {
            wat2add = wat2add + "1";
        }
        if(ev.keycode == 50)
        {
            wat2add = wat2add + "2";
        }
        if(ev.keycode == 51)
        {
            wat2add = wat2add + "3";
        }
        if(ev.keycode == 52)
        {
            wat2add = wat2add + "4";
        }
        if(ev.keycode == 53)
        {
            wat2add = wat2add + "5";
        }
        if(ev.keycode == 54)
        {
            wat2add = wat2add + "6";
        }
        if(ev.keycode == 55)
        {
            wat2add = wat2add + "7";
        }
        if(ev.keycode == 56)
        {
            wat2add = wat2add + "8";
        }
        if(ev.keycode == 57)
        {
            wat2add = wat2add + "9";
        }
    }
}
bool MenuWidget::is_checked() const
{
    return _checked;
}
