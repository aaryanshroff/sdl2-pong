#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h> // cannot use forward declaration since SDL_Rect is not a pointer
#include <vector>
#include "player.h"

// forward declarations
class GameObject;
//

class Game
{
    static Game *instance;

    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    std::vector<GameObject *> gameObjects;

    bool running;
    int currentFrame;

    Game(); // private ctor to enable singleton pattern.
            // to instantiate, use the static instance() method instead.

public:
    static Game *Instance();
    bool init(const char *title, int x, int y, int width, int height, SDL_WindowFlags flags);
    void update();
    void render();
    void handleEvents();
    void clean();

    // getters
    bool isRunning() const;
    SDL_Renderer *getRenderer() const;

}; // class Game

typedef Game TheGame;

#endif // _GAME_H_