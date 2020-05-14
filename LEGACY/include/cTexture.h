#ifndef CTEXTURE_H
#define CTEXTURE_H

class cTexture
{
    public:
        cTexture();
        virtual ~cTexture();

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

#endif // CTEXTURE_H
