#include <iostream>
#include "timer.h"

Timer::Timer() : start_time(0), time(0)
{

}

void Timer::start()
{
	start_time = SDL_GetTicks();
}

void Timer::stop()
{
	time = SDL_GetTicks() - start_time;
}

unsigned int Timer::get_time()
{
	unsigned int res = 0;
	if(time == 0) //timer not stopped yet
		res = SDL_GetTicks() - start_time;
	else
		res = time;
	return res;
}

std::string Timer::get_time_string()
{
	return get_time_string(get_time());	
}

std::string Timer::get_time_string(unsigned int t)
{
	unsigned int min = t / 60000;
	unsigned int sec = (t / 1000) % 60;
	unsigned int ms = t % 1000;
	std::string res = std::string(min < 10 ? "0" : "") + std::to_string(min) + ":";
	res += std::string(sec < 10 ? "0" : "") + std::to_string(sec);
	res += "." + std::string(ms < 100 ? "0" : "") + std::string(ms < 10 ? "0" : "");
	res += std::to_string(ms);
	return res;
}

/*
Timer& Timer::operator=(Timer t)
{
    return *this;
}
*/