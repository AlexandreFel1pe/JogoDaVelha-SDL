#define SDL_MAIN_HANDLED

#include "class.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture *loadTexture(const std::string &file, SDL_Renderer *ren){
    SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str()); 
    return texture;
}

extern SDL_Renderer *renderer;

extern SDL_Texture *loadTexture(const std::string &file, SDL_Renderer *ren);

using namespace std;

void Entity::setEntity(const std::string &file){
            id = 1;
            nome = "Bolinha";
            texture = loadTexture(file.c_str(), renderer);
        }

SDL_Texture *Entity::getEntity(){
            return texture;
        }

void Entity::DestroyTexture(){
    SDL_DestroyTexture(texture);
    texture = NULL;
}

Entity imgtabuleiro;
Entity menuimg;
Entity vitoriaX;
Entity vitoriaO;
Entity empate;
Entity imgx;;
Entity imgbolinha;