#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

namespace cst{

class Screen{
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Uint32* m_buffer;
    Uint32* m_buffer_blr;
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
public:
    Screen();
    bool init();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    bool processEvents();
    void boxBlur();
    void clear();
    void close();
};

}

#endif
