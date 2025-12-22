#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL2/SDL.h>
#include "types.h"

class Button
{
	public:
        Button(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
        bool is_mouse_over(unsigned short mouse_x, unsigned short mouse_y); // returns true if the specified coordinates are inside the button

        //forbids copy constructor to avoid warning in c++11
        Button(const Button& b) : Button(b.x, b.y, b.w, b.h) {};
        Button& operator=(const Button& b) = delete;
    private:
        unsigned short x, y, w, h;
};

#endif