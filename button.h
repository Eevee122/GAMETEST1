#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL2/SDL.h>
#include "types.h"

class Button
{
	public:
        Button(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
        bool is_mouse_over(unsigned short mouse_x, unsigned short mouse_y); // Возвращает значение true, если указанные координаты находятся внутри кнопки
        //Запрещает копировать конструктор, чтобы избежать предупреждения в c++11
        Button(const Button& b) : Button(b.x, b.y, b.w, b.h) {};
        Button& operator=(const Button& b) = delete;
    private:
        unsigned short x, y, w, h;
};

#endif
