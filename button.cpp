#include <iostream>
#include "button.h"

Button::Button(unsigned short x, unsigned short y, unsigned short w, unsigned short h) : x(x), y(y), w(w), h(h)
{

}

bool Button::is_mouse_over(unsigned short mouse_x, unsigned short mouse_y)
{
	bool is_over = mouse_x < x || mouse_y < y || mouse_x > x + w || mouse_y > y + h ? false : true;
    return is_over;
}