#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <map>
#include <string>
#include <SDL2/SDL.h> // cannot use forward declaration since SDL_RendererFlip is not a pointer
// vvv Not using this since it would apply to all files that include this header file.
// using namespace std;

/*
    TextureManager is a singleton class that manages the loading and unloading of textures.
*/

class TextureManager
{
    static TextureManager *instance;
    std::map<std::string, SDL_Texture *> textureMap;
    TextureManager() {} // private constructor to enable the singleton pattern. to instantiate, use the static instance() method instead.

public:
    static TextureManager *Instance()
    {
        // construct instance if it doesn't exist, else just return instance (avoids creating multiple TextureManager objects)
        if (instance == nullptr)
        {
            instance = new TextureManager();
        }
        return instance;
    }
    // loads image at filePath into internal texture directory with the key of `id`
    bool load(std::string filePath, std::string id, SDL_Renderer *renderer);
    // renders texture with `id` to renderer at position (x, y) with `width` and `height`
    // flips it along the axis specified by `flip`
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip);
    // same as draw except renders the frame of a image (spritesheet) at `currentFrame` in row `currentRow`
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip);
};

typedef TextureManager TheTextureManager;

#endif