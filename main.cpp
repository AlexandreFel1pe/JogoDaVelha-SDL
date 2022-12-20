#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "class.h"
#include "mecanics.h"
#include "render.h"

using namespace std;

void menu();
void game();
void inittabuleiro();
void reset();
char SDLQuit();

SDL_Renderer *renderer;
SDL_Window *window;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
char menurender = 'm';
int intPontosX = 0;
int intPontosO = 0;

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Jogo Da Velha", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    imgtabuleiro.setEntity("img/tabuleiro.png");
    vitoriaX.setEntity("img/xganhou.png");
    vitoriaO.setEntity("img/oganhou.png");
    menuimg.setEntity("img/menu.png");
    empate.setEntity("img/empate.png");

    menu();
    
    SDLQuit();
    printf("%c", SDLQuit());
}

void game(){
    local = 1;
    reset();
    inittabuleiro();
    cont = 0;

    SDL_Event e;
    bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN){
                x = e.button.x;
                y = e.button.y;
                jogada();
            }
            if(verificavitoria() == 1){
                menurender = 'x';
                menu();
                quit = true;
            }
            if(verificavitoria() == 2){
                menurender = 'o';
                menu();
                quit = true;
            }
            if(cont == 9){
                menurender = 'e';
                menu();
                quit = true;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, imgtabuleiro.getEntity(), NULL, NULL);
        renderX(renderer, imgx.getEntity());
        renderbolinha(renderer,imgbolinha.getEntity());
        SDL_RenderPresent(renderer);
    }
}

void menu(){ 
    std::string pontos = " ";
    string stringPontosX = "Pontos X:";
    string stringPontosO = " Pontos O:";

    if(verificavitoria() == 1){
        intPontosX = intPontosX + 1;
    }
    if(verificavitoria() == 2){
        intPontosO = intPontosO + 1;
    }

    pontos = stringPontosX + pontos + std::to_string(intPontosX) + stringPontosO + pontos + std::to_string(intPontosO);

	char arr[pontos.length() + 1]; 
	strcpy(arr, pontos.c_str()); 

    SDL_Rect texto;
    texto.x = 0;
    texto.y = 0;
    texto.h = 24;
    texto.w = 200;
    TTF_Init();
    SDL_Color color = { 255, 215, 0 };
	TTF_Font *font = TTF_OpenFont("arial.ttf", 24);
    SDL_Surface *surf = TTF_RenderText_Blended(font, arr, color);
    SDL_Texture *placar = SDL_CreateTextureFromSurface(renderer, surf);

    SDL_Event e;
    bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN){
                x = e.button.x;
                y = e.button.y;
                if((x > 220 && x < 395) && (y > 245 && y < 315)){
                    quit = true;
                    game();
                }
            }
        }
        SDL_RenderClear(renderer);
        renderMenu(renderer, menurender);
        SDL_RenderCopy(renderer, placar, NULL, &texto);
        SDL_RenderPresent(renderer);
    }
}

void inittabuleiro()
{
    for(int i = 1; i < 4; i++){
        for(int t = 1; t < 4; t++){
            tabuleiro[i][t] = 0;
        }
    }
}

 void reset(){
    for(int i = 0; i <= 9; i++){
        printO[i] = false;
        printX[i] = false;
    }
 }

 char SDLQuit(){
    imgtabuleiro.DestroyTexture();
    menuimg.DestroyTexture();
    vitoriaX.DestroyTexture();
    vitoriaO.DestroyTexture();
    empate.DestroyTexture();
    imgx.DestroyTexture();
    imgbolinha.DestroyTexture();
    SDL_Quit();
    return 't';
 }