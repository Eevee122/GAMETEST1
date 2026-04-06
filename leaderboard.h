#ifndef _LEADERBOARD_H_
#define _LEADERBOARD_H_
#include <fstream>
#include <SDL2/SDL.h>
#include "types.h"

const std::string scores_file("scores.txt");

class Leaderboard 
{
	public:
		Leaderboard(); //Читает файл и создает таблицу лидеров
		~Leaderboard(); //Освобождает место и сохраняет результаты на диск в виде файлика

		Leaderboard(const Leaderboard& l) = delete; //Запрещает использование копирования для избежания ошибок
        Leaderboard& operator=(const Leaderboard& l) = delete;

		void add_score(int score); //Добавляет оценку в массив и сохраняет на диск

		int* scores;

	private:
		void read_file(); //Загружает очки из файла
		void write_file(); //Сохраняет очки в файл
		void sort_scores(); //Сортирует весь массив очков

};

#endif
