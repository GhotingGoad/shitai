#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

SDL_Window* gameWindow = NULL;
//window renderer
SDL_Renderer* gameRenderer = NULL;

class renderFrame{
	public:
		//Initializes variables
		renderFrame();

		//Deallocates memory
		~renderFrame();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Deallocates texture
		void clearTexture();

		//Renders texture at given point
		void render( int x, int y , SDL_Rect* clip);

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* texture;

		//Image dimensions
		int textureWidth;
		int textureHeight;
};

renderFrame::renderFrame(){
	//Initialize
	texture = NULL;
	textureWidth = 0;
	textureHeight = 0;
}

renderFrame::~renderFrame(){
	//Deallocate
    clearTexture();
}

bool renderFrame::loadFromFile(std::string path){
	//Get rid of preexisting texture
	clearTexture();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* surfaceImageLoaded = IMG_Load( path.c_str());
	if( surfaceImageLoaded == NULL){
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}else{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gameRenderer, surfaceImageLoaded);
		if(newTexture == NULL){
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}else{
			//Get image dimensions
			textureWidth = surfaceImageLoaded->w;
			textureHeight = surfaceImageLoaded->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(surfaceImageLoaded);
	}

	//Return success
	texture = newTexture;
	return texture != NULL;
}

void renderFrame::clearTexture(){
	//Free texture if it exists
	if( texture != NULL )
	{
		SDL_DestroyTexture( texture );
		texture = NULL;
		textureWidth = 0;
		textureHeight = 0;
	}
}

void renderFrame::render( int x, int y, SDL_Rect* clip){
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, textureWidth, textureHeight };
    if( clip != NULL ){
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
	}
	SDL_RenderCopy( gameRenderer, texture, clip, &renderQuad );
}

int renderFrame::getWidth(){
	return textureWidth;
}

int renderFrame::getHeight(){
	return textureHeight;
}

renderFrame textureTetramino;
SDL_Rect gSpriteClips[4];

bool createWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, bool flagError){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL cannot initialize due to %s", SDL_GetError());
        flagError = true;
    }else{
        printf("SDL successfully initialized.");
        		gameWindow = SDL_CreateWindow("SDL Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gameWindow == NULL){
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			flagError = true;
		}else{
		    //initialize SDL_Image
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)){
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            }else{
                gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
                printf("Window successfully created.");
            }
		}
    }
    return flagError;
}


void loadMedia(){
	if( !textureTetramino.loadFromFile("media/tetramino.png")){
		printf("Failed to load tetramino texture image!\n");
	}else{
		gSpriteClips[ 0 ].x = 0;
		gSpriteClips[ 0 ].y = 0;
		gSpriteClips[ 0 ].w = 80;
		gSpriteClips[ 0 ].h = 120;

		gSpriteClips[ 1 ].x = 80;
		gSpriteClips[ 1 ].y = 0;
		gSpriteClips[ 1 ].w = 80;
		gSpriteClips[ 1 ].h = 120;

		gSpriteClips[ 2 ].x = 160;
		gSpriteClips[ 2 ].y = 0;
		gSpriteClips[ 2 ].w = 80;
		gSpriteClips[ 2 ].h = 120;

		//Set bottom right sprite
		gSpriteClips[ 3 ].x = 240;
		gSpriteClips[ 3 ].y = 0;
		gSpriteClips[ 3 ].w = 40;
		gSpriteClips[ 3 ].h = 160;
	}
}

void refreshWindow(int playerPositionX, int playerPositionY){
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gameRenderer);

    loadMedia();

    //Render Player Sprite to the screen
    textureTetramino.render(playerPositionX, playerPositionY, &gSpriteClips[0]);
    textureTetramino.render(400, 400, &gSpriteClips[1]);
    //Update screen
    SDL_RenderPresent(gameRenderer);
}

void quit(){
	//Free loaded images
	textureTetramino.clearTexture();

	//Destroy window
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;
	gameRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

