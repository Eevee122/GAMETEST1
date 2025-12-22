#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "player.h"
#include "types.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const float fov = 60 * M_PI / 180.0;

const SDL_Color ttf_color_white = {255, 255, 255, 255};
const SDL_Color ttf_color_banana = {209, 182, 6, 255};
const SDL_Color ttf_color_red = {255, 0, 0, 255};

class Renderer
{
    public:
        Renderer(Player* p, Map* ma, Menu* me);
        bool init_sdl(const char* title, unsigned short width, unsigned short height); //initializes SDL and necessary data for rendering
        void draw(unsigned int fps); //renders the game and UI and displays it
        ~Renderer();

        //forbids copy constructor to avoid warning in c++11
        Renderer(const Renderer& r) = delete;
        Renderer& operator=(const Renderer& r) = delete;
        
    private:
        void set_pixel(unsigned short x, unsigned short y, unsigned int32 pixel); //sets a pixel on the screen
        unsigned int32 get_pixel_tex(unsigned short itex, unsigned short x, unsigned short y, bool sprite = false); //gets a pixel from the texture file

        unsigned int32 rgb_to_int(unsigned char r, unsigned char g, unsigned char b); //convert an RGB value to a unsigned int32 used by SDL
        unsigned int32 apply_light(unsigned int32 color, float factor); //darkens a color using a factor, 1 = no change, 0 = black

        void draw_sprite(Sprite s); //draws a sprite in the world
        void draw_2d_sprite(unsigned short itex, unsigned short x, unsigned short y, float size); //draws a sprite as a flat texture on the screen 
        void draw_text(unsigned short x, unsigned short y, std::string text, bool big_text, SDL_Color ttf_color); //draws text using sdl_ttf

        //UI display
        void display_normal(int fps);
        void display_menu();
        void display_pause_menu();
        void display_game_over();
        void display_win();
        void display_help();

        SDL_Window* window;
        SDL_Renderer* sdl_renderer;
        SDL_Texture* render_texture;

        unsigned int32* pixels; //all the pixels rendered on screen
        unsigned short screen_w; //screen width
        unsigned short screen_h; //screen height

        SDL_Surface* wall_textures;
        SDL_Surface* sprites_textures;
        TTF_Font *font_big; //font with a size of 100
        TTF_Font *font_medium; //font with a size of 60
        float* zbuffer; //array containing all distances

        Player* player;
        Map* map;
        Menu* menu;
};

#endif

