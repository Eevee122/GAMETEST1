#ifndef _MENU_H_
#define _MENU_H_

#include <SDL2/SDL.h>
#include "map.h"
#include "button.h"
#include "timer.h"
#include "leaderboard.h"
#include "types.h"
#include "types.h"

enum CurrentMenu {None, Main, Pause, GameOver, Win, Help};
enum Difficulty {Easy, Normal, Hard};
enum SoundVolume {NoSound, LowSound, NormalSound};

class Menu
{
	public:
        Menu();
        bool check_hover(unsigned short button_id); //Возвращает true, если курсор мыши находится над кнопкой, и вызывает функцию handme_click, если нажата кнопка мыши
        void handle_click(unsigned short button_id); //Обрабатывает логику кнопок
        bool wants_to_quit = false; //Возвращает true, если игрок хочет закрыть игру
        CurrentMenu current = Main; //Правильно показывает меню
        bool mouse_down = false; //Если в течение этого кадра нажата кнопка мыши, это обрабатывается классом Player
        Difficulty difficulty = Normal;
        SoundVolume sound = LowSound;
        Timer timer;
        Leaderboard leaderboard;
        Button buttons[9]; //UI buttons

        ~Menu();

    private:
        
};

#endif
