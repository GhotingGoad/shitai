#ifndef WTEXTURE_H
#define WTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>


class wTexture
{
    public:
        wTexture();
        virtual ~wTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path, SDL_Renderer* gameRenderer);

        //Deallocates texture
        void clearTexture();

        void renderBackground(SDL_Renderer* gameRenderer);

        //Renders texture at given point
        void renderSprite( int x, int y, SDL_Rect* clip, SDL_Renderer* gameRenderer);


    protected:

    private:
        //The actual hardware texture
        SDL_Texture* texture;
        int textureWidth;
        int textureHeight;
};

#endif // WTEXTURE_H
