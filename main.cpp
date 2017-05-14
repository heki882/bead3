#include "graphics.hpp"
#include "widgets.hpp"
#include "numberwidget.hpp"
#include "menuwidget.hpp"
#include "checkbox.hpp"
#include "window.hpp"
#include "iostream"
#include "sstream"
#include "textbox.hpp"
#include <vector>
#include <cstdlib>
using namespace std;
using namespace genv;

///////////////////////////////////////////////////
int _size = 10;


class MyWindow : public Window {
public:
    MyWindow() ;
    static void fv(Window *);
};

MyWindow::MyWindow() {
    for(int j = 0; j < _size; j++)
    {
        for(int i = 0; i < _size; i++)
        {
            ExampleCheckBox * b1 = new ExampleCheckBox(10 + i*38,10 + j*38,40,40);
            widgets.push_back(b1);
        }
    }
}

void thegameisover(int winner, vector<ExampleCheckBox*> &widgets)
{
    std::vector<TextBox*> widgetss;
    widgets.resize(0);

    if(winner == 1)
    {
        TextBox * b1 = new TextBox(10,100,100,50,50,"Player One Win", false);
        widgetss.push_back(b1);
    }
    else if(winner == 2)
    {
        TextBox * b1 = new TextBox(10,100,100,50,50,"Player Two Win", false);
        widgetss.push_back(b1);
    }
    else if(winner == 3)
    {
        TextBox * b1 = new TextBox(15,100,100,50,50,"Draw", false);
        widgetss.push_back(b1);
    }

    TextBox * b2 = new TextBox(53,212,100,50,16,"New Game?", false);
    widgetss.push_back(b2);
    TextBox * b3 = new TextBox(282,212,100,50,16,"Exit", false);
    widgetss.push_back(b3);

    event ev;
    while(gin >> ev )
    {
        gout << move_to(0,0) << color(0,0,0) << box(400,400);
        for (size_t i=0;i<widgetss.size();i++) {
        widgetss[i]->draw();}

        if (ev.type == ev_mouse && ev.button==btn_left && ev.pos_x > 50 && ev.pos_x < 150 && ev.pos_y > 200 && ev.pos_y < 250)
        {
                MyWindow *mywindow = new MyWindow;
                mywindow->event_loop();
        }
        if (ev.type == ev_mouse && ev.button==btn_left && ev.pos_x > 250 && ev.pos_x < 350 && ev.pos_y > 200 && ev.pos_y < 250)
        {
            exit(0);
        }
        gout << refresh;
    }
}

void whowon(int a, vector<ExampleCheckBox*> &widgets)
{
    int playeronepointsx = 1;
    int playeronepointsy = 1;
    int playeronepointsxz = 1;
    int playeronepointsyz = 1;
    int playertwopointsx = 1;
    int playertwopointsy = 1;
    int playertwopointsxz = 1;
    int playertwopointsyz = 1;
    int checkcount = 0;
    if(widgets[a]->_checkedbyplayerone==true)
    {
        for(int i = 1; i < 6; i++) { if(a+i*10 < widgets.size()) { if(widgets[a+i*10]->_checkedbyplayerone==true) { playeronepointsx +=1; } else { break; } } }
        for(int i = 1; i < 6; i++) { if(a-i*10 > -1) { if(widgets[a-i*10]->_checkedbyplayerone==true) { playeronepointsx +=1; } else { break; } } }
        if(playeronepointsx > 4)
        {
            thegameisover(1, widgets);
        }
        else
        {
            playeronepointsx = 1;
        }
        for(int i = 1; i < 6; i++) { if(a+i < widgets.size()) { if(widgets[a+i]->_checkedbyplayerone==true) { playeronepointsy +=1; } else { break; } } }
        for(int i = 1; i < 6; i++) { if(a-i > -1) { if(widgets[a-i]->_checkedbyplayerone==true) { playeronepointsy +=1; } else { break; } } }
        if(playeronepointsy > 4)
        {
            thegameisover(1, widgets);
        }
        else
        {
            playeronepointsy = 0;
        }
        for(int i = 1; i < 6; i++) { if(a+i*11 < widgets.size()) { if(widgets[a+i*11]->_checkedbyplayerone==true) { playeronepointsxz +=1; } else { break; } } }
        for(int i = 1; i < 6; i++) { if(a-i*11 > -1) { if(widgets[a-i*11]->_checkedbyplayerone==true) { playeronepointsxz +=1; } else { break; } } }
        if(playeronepointsxz > 4)
        {
            thegameisover(1, widgets);
        }
        else
        {
            playeronepointsxz = 1;
        }
        for(int i = 1; i < 6; i++){ if(a+i*9 < widgets.size()) { if(widgets[a+i*9]->_checkedbyplayerone==true) { playeronepointsyz +=1; } else { break; } } }
        for(int i = 1; i < 6; i++){ if(a-i*9 > -1) { if(widgets[a-i*9]->_checkedbyplayerone==true) { playeronepointsyz +=1; } else { break; } } }
        if(playeronepointsyz > 4)
        {
            thegameisover(1, widgets);
        }
        else
        {
            playeronepointsyz = 1;
        }
    }
    if(widgets[a]->_checkedbyplayertwo==true)
    {
        for(int i = 1; i < 6; i++) { if(a+i*10 < widgets.size()) { if(widgets[a+i*10]->_checkedbyplayertwo==true) { playertwopointsx +=1; } else { break; } } }
        for(int i = 1; i < 6; i++) { if(a-i*10 > -1) { if(widgets[a-i*10]->_checkedbyplayertwo==true) { playertwopointsx +=1; } else { break; } } }
        if(playertwopointsx > 4)
        {
            thegameisover(2, widgets);
        }
        else
        {
            playertwopointsx = 1;
        }
        for(int i = 1; i < 6; i++) { if(a+i < widgets.size()) { if(widgets[a+i]->_checkedbyplayertwo==true) { playertwopointsy +=1; } else { break; } } }
        for(int i = 1; i < 6; i++) { if(a-i > -1) { if(widgets[a-i]->_checkedbyplayertwo==true) { playertwopointsy +=1; } else { break; } } }
        if(playertwopointsy > 4)
        {
            thegameisover(2, widgets);
        }
        else
        {
            playertwopointsy = 0;
        }
        for(int i = 1; i < 6; i++) { if(a+i*11 < widgets.size()) { if(widgets[a+i*11]->_checkedbyplayertwo==true) { playertwopointsxz +=1; } else { break; } } }
        for(int i = 1; i < 6; i++) { if(a-i*11 > -1) { if(widgets[a-i*11]->_checkedbyplayertwo==true) { playertwopointsxz +=1; } else { break; } } }
        if(playertwopointsxz > 4)
        {
            thegameisover(2, widgets);
        }
        else
        {
            playertwopointsxz = 1;
        }
        for(int i = 1; i < 6; i++){ if(a+i*9 < widgets.size()) { if(widgets[a+i*9]->_checkedbyplayertwo==true) { playertwopointsyz +=1; } else { break; } } }
        for(int i = 1; i < 6; i++){ if(a-i*9 > -1) { if(widgets[a-i*9]->_checkedbyplayertwo==true) { playertwopointsyz +=1; } else { break; } } }
        if(playertwopointsyz > 4)
        {
            thegameisover(2, widgets);
        }
        else
        {
            playertwopointsyz = 1;
        }
    }
    for(int i = 0; i < widgets.size(); i++)
    {
        if(widgets[i]->_checkedbyplayerone == true or widgets[i]->_checkedbyplayertwo == true)
        {
            checkcount +=1;
        }
    }
    if(checkcount == widgets.size())
    {
        thegameisover(3, widgets);
    }
}

void Window::event_loop() {
    int playernumber = 0;
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                        if(playernumber != 1 && widgets[focus]->_checkedbyplayerone == false && widgets[focus]->_checkedbyplayertwo == false)
                        {
                            playernumber = 1;
                        }
                        else if(playernumber == 1 && widgets[focus]->_checkedbyplayerone == false && widgets[focus]->_checkedbyplayertwo == false)
                        {
                            playernumber = 2;
                        }
                }
            }
        }
        if (focus!=-1) {
            if(playernumber == 1 && widgets[focus]->_checkedbyplayerone == false && widgets[focus]->_checkedbyplayertwo == false)
            {
                widgets[focus]->checkedbyplayerone();
            }
            if(playernumber == 2 && widgets[focus]->_checkedbyplayerone == false && widgets[focus]->_checkedbyplayertwo == false)
            {
                widgets[focus]->checkedbyplayertwo();
            }
            whowon(focus, widgets);

        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}


int main()
{
    gout.open(400,400);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}
