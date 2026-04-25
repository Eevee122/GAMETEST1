#ifndef _MAP_H_
#define _MAP_H_

#include <SDL2/SDL.h>
#include <vector>
#include "types.h"

enum SpriteType {Decoration, Enemy, Key, Temporary};

struct Sprite
{
	float x, y = 0;
	unsigned short size = 600;
	unsigned short itex = 0;
	SpriteType type = Decoration;
	//Квадрат расстояния от игрока используется для сортировки спрайтов, поэтому нет необходимости извлекать квадратный корень.
	float sqr_dist = 0;
	Uint32 start_time = 0;

	bool operator < (const Sprite& s) const
	{
		//Спрайты, расположенные дальше, сортируются перед ближайшими спрайтами
		return sqr_dist > s.sqr_dist;
	}

	Sprite() : x(0), y(0), size(600), itex(0), type(Decoration), sqr_dist(0), start_time(SDL_GetTicks()) {}
};

struct Door
{
	unsigned short x, y = 0;
	float animationState = 1; //0 = fully opened, 0.5 = half opened, 1 = fully closed

	Door() : x(0), y(0), animationState(1) {}
};

class Map
{
	public:
        Map();
        unsigned short w = 0;
		unsigned short h = 0;

		float speed = 0.03; //Скорость противника меняется в зависимости от сложности
		int damage = 0; //Урон, наносимый каждым врагом, меняется в зависимости от сложности
		int enemy_count = 0;
		
		char get_tile(unsigned short x, unsigned short y);
		void set_tile(unsigned short x, unsigned short y, char tile);
		void sort_sprites(float player_x, float player_y); //Сортирует спрайты в векторе в зависимости от расстояния до игрока
		std::vector<Sprite> const& get_sprites();
		void delete_sprite(unsigned short id); //Удаляет спрайт с указанным индексом в векторе
		void update_sprites(float player_x, float player_y, float dt); //Перемещает врагов так, чтобы они следовали за игроком, и изменяет размер временных спрайтов
		Door get_door(unsigned short x, unsigned short y); //Пытается найти дверь по указанным координатам, возвращает 0, если не найдена
		bool update_doors(float player_x, float player_y, float dt); //Обновляет состояние анимации, если игрок находится достаточно близко
		void animate_sprites(); //Меняет спрайты для анимации индеек
		int damage_player(); //Возвращает количество урона, которое игрок должен получить в зависимости от сложности и количества находящихся поблизости индеек
		bool pickup_keys(); //Возвращает значение true и удаляет ключ с карты, если игрок находится достаточно близко, возвращает значение false, если ключ не найден.
		void add_temp_sprite(unsigned short itex, float x, float y, unsigned short size); //adds a sprite to the map that is delete 500ms later (for explosions)
		void update_dist_map(unsigned short px, unsigned short py);
		~Map();

		//forbids copy constructor to avoid warning in c++11
        Map(const Map& m) = delete;
        Map& operator=(const Map& m) = delete;

	private:
		char* map;
		unsigned short* dist;
		std::vector<Sprite> sprites;
		std::vector<Door> doors;
		Uint32 get_pixel(SDL_Surface* source, unsigned short x, unsigned short y);
};

#endif
