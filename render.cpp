#include "render.h"
#include <SDL2/SDL.h>
#include "mecanics.h"
#include "class.h"

void renderbolinha(SDL_Renderer *ren, SDL_Texture *tex){
    imgbolinha.setEntity("img/bolinha.png");

    SDL_Rect O0 = {50,20,100,100};
    SDL_Rect O1 = {250,20,100,100};
    SDL_Rect O2 = {455,20,100,100};
    SDL_Rect O3 = {50,175,100,100};
    SDL_Rect O4 = {250,175,100,100};
    SDL_Rect O5 = {455,175,100,100};
    SDL_Rect O6 = {50,345,100,100};
    SDL_Rect O7 = {250,345,100,100};
    SDL_Rect O8 = {455,345,100,100};

    if(printO[0] == true){
        SDL_RenderCopy(ren, tex, NULL, &O0);
    }
    if(printO[1] == true){
        SDL_RenderCopy(ren, tex, NULL, &O1);
    }
    if(printO[2] == true){
        SDL_RenderCopy(ren, tex, NULL, &O2);
    }
    if(printO[3] == true){
        SDL_RenderCopy(ren, tex, NULL, &O3);
    }
    if(printO[4] == true){
        SDL_RenderCopy(ren, tex, NULL, &O4);
    }
    if(printO[5] == true){
        SDL_RenderCopy(ren, tex, NULL, &O5);
    }
    if(printO[6] == true){
        SDL_RenderCopy(ren, tex, NULL, &O6);
    }
    if(printO[7] == true){
        SDL_RenderCopy(ren, tex, NULL, &O7);
    }
    if(printO[8] == true){
        SDL_RenderCopy(ren, tex, NULL, &O8);
    }
 }

 void renderX(SDL_Renderer *ren, SDL_Texture *tex){
    imgx.setEntity("img/x.png");

    SDL_Rect x0 = {50,20,100,100};
    SDL_Rect x1 = {250,20,100,100};
    SDL_Rect x2 = {455,20,100,100};
    SDL_Rect x3 = {50,175,100,100};
    SDL_Rect x4 = {250,175,100,100};
    SDL_Rect x5 = {455,175,100,100};
    SDL_Rect x6 = {50,345,100,100};
    SDL_Rect x7 = {250,345,100,100};
    SDL_Rect x8 = {455,345,100,100};

    if(printX[0] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x0);
    }
    if(printX[1] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x1);
    }
    if(printX[2] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x2);
    }
    if(printX[3] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x3);
    }
    if(printX[4] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x4);
    }
    if(printX[5] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x5);
    }
    if(printX[6] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x6);
    }
    if(printX[7] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x7);
    }
    if(printX[8] == true){
    SDL_RenderCopy(ren, tex, NULL ,&x8);
    }
 }

 void renderMenu(SDL_Renderer *ren, char opcao){
    if(opcao == 'x') SDL_RenderCopy(ren, vitoriaX.getEntity(), NULL ,NULL);
    if(opcao == 'o') SDL_RenderCopy(ren, vitoriaO.getEntity(), NULL ,NULL);
    if(opcao == 'm') SDL_RenderCopy(ren, menuimg.getEntity(), NULL ,NULL);
    if(opcao == 'e') SDL_RenderCopy(ren, empate.getEntity(), NULL ,NULL);
 }