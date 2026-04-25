#ifndef _TIMER_H_
#define _TIMER_H_

#include <SDL2/SDL.h>
#include "types.h"

class Timer
{
	public:
        Timer();
        void start();
        void stop();
        unsigned int get_time();

        //Перегруженная функция
        std::string get_time_string(); //Возвращает текущее время в строку
        std::string get_time_string(unsigned int t); //Возвращает указанное время в строку

        //Запрещает копировать конструктор, чтобы избежать предупреждения в c++11
        Timer(const Timer& t) = delete;
        Timer& operator=(const Timer& t) = delete;
    private:
    	unsigned int start_time;
    	unsigned int time;
};

#endif
