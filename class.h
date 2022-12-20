#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

SDL_Texture *loadTexture(const std::string &file, SDL_Renderer *ren);

class Entity {
    private:
        int id;
        string nome;
        SDL_Texture *texture;
    public:
        void setEntity(const std::string &file);

        void DestroyTexture();

        SDL_Texture *getEntity();
};

extern Entity imgtabuleiro;
extern Entity menuimg;
extern Entity vitoriaX;
extern Entity vitoriaO;
extern Entity empate;
extern Entity imgx;
extern Entity imgbolinha;
