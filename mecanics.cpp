#include "mecanics.h"
#include <iostream>
#include <string>

using namespace std;

bool jogadaDoPC();
bool iaVitoria();
bool iaDerrota();

int local = 1;
int tabuleiro[4][4];
bool printX[9];
bool printO[9];
int cont = 0;
int x, y;
bool ta = false;

void tabuleiroprint(){
    printf("\n%d|%d|%d", tabuleiro[1][1], tabuleiro[1][2], tabuleiro[1][3]);
    printf("\n%d|%d|%d", tabuleiro[2][1], tabuleiro[2][2], tabuleiro[2][3]);
    printf("\n%d|%d|%d", tabuleiro[3][1], tabuleiro[3][2], tabuleiro[3][3]);
}

bool verifica(int x, int y){
    if(tabuleiro[x][y] == 0){
    return true;
    }
    else{
        printf("Lugar ja ocupado");
    }
    return false;
}

void trocajogador(){
    if(local == 1){
        local = 2;
    }
    else{
        local = 1;
    }
}

char verificavitoria(){
    for(int i = 1; i < 4; i++){
    if(tabuleiro[i][1]==1 && tabuleiro[i][2]==1 && tabuleiro[i][3]==1) {return (1);}
    }

    for(int i = 1; i < 4; i++){
    if(tabuleiro[1][i]==1 && tabuleiro[2][i]==1 && tabuleiro[3][i]==1) {return (1);}
    }

    if(tabuleiro[1][1]==1 && tabuleiro[2][2]==1 && tabuleiro[3][3]==1) {return (1);}

    if(tabuleiro[1][3]==1 && tabuleiro[2][2]==1 && tabuleiro[3][1]==1) {return (1);}

    for(int i = 1; i < 4; i++){
    if(tabuleiro[i][1]==2 && tabuleiro[i][2]==2 && tabuleiro[i][3]==2) {return (2);}
    }

    for(int i = 1; i < 4; i++){
    if(tabuleiro[1][i]==2 && tabuleiro[2][i]==2 && tabuleiro[3][i]==2) {return (2);}
    }

    if(tabuleiro[1][1]==2 && tabuleiro[2][2]==2 && tabuleiro[3][3]==2) {return (2);}

    if(tabuleiro[1][3]==2 && tabuleiro[2][2]==2 && tabuleiro[3][1]==2) {return (2);}

    return('a');
}

void jogadorContraJogador(){

    //Linha 1
    if (x < 202 && y < 140){
        if(verifica(1,1) == true){
            tabuleiro[1][1] = local;
            if(local == 1){printX[0] = true;} else {printO[0] = true;}
            tabuleiroprint();
            verificavitoria();
            trocajogador();
            cont = cont + 1;
        }
        return;
    }
    if ((x > 202 && x < 435) && y < 140){
        if(verifica(1,2) == true){
        tabuleiro[1][2] = local;
        if(local == 1){printX[1] = true;} else {printO[1] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }
    if (x > 435 && y < 140){
        if(verifica(1,3) == true){
        tabuleiro[1][3] = local;
        if(local == 1){printX[2] = true;} else {printO[2] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }

    //Linha 2
    if (x < 202 && (y > 145 && y < 310 )){
        if(verifica(2,1) == true){
        tabuleiro[2][1] = local;
        if(local == 1){printX[3] = true;} else {printO[3] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }
    if ((x > 202 && x < 435) && (y > 145 && y < 310 )){
        if(verifica(2,2) == true){
        tabuleiro[2][2] = local;
        if(local == 1){printX[4] = true;} else {printO[4] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }
    if (x > 435 && (y > 145 && y < 310 )){
        if(verifica(2,3) == true){
        tabuleiro[2][3] = local;
        if(local == 1){printX[5] = true;} else {printO[5] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }

    //Linha 3
    if (x < 202 && y > 310){
        if(verifica(3,1) == true){
        tabuleiro[3][1] = local;
        if(local == 1){printX[6] = true;} else {printO[6] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }
    if ((x > 202 && x < 435) && y > 310){
        if(verifica(3,2) == true){
        tabuleiro[3][2] = local;
        if(local == 1){printX[7] = true;} else {printO[7] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }
    if (x > 435 && y > 310){
        if(verifica(3,3) == true){
        tabuleiro[3][3] = local;
        if(local == 1){printX[8] = true;} else {printO[8] = true;}
        tabuleiroprint();
        verificavitoria();
        trocajogador();
        cont = cont + 1;
        }
        return;
    }
}

void moveX(){
    if(cont == 0){
        cont = 2;
    }
    else if(cont == 2){
        cont = 4;
    }
    else if(cont == 4){
        cont = 6;
    }
    else if(cont == 6){
        cont = 8;
    }
    else{
        cont = 9;
    }
    //Linha 1
    if (x < 202 && y < 140){
        if(verifica(1,1) == true){
            tabuleiro[1][1] = 1;
            printX[0] = true;
            if(cont == 9){ta = true; return;}
        }
        return;
    }
    if ((x > 202 && x < 435) && y < 140){
        if(verifica(1,2) == true){
        tabuleiro[1][2] = 1;
        printX[1] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }
    if (x > 435 && y < 140){
        if(verifica(1,3) == true){
        tabuleiro[1][3] = 1;
        printX[2] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }

    //Linha 2
    if (x < 202 && (y > 145 && y < 310 )){
        if(verifica(2,1) == true){
        tabuleiro[2][1] = 1;
        printX[3] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }
    if ((x > 202 && x < 435) && (y > 145 && y < 310 )){
        if(verifica(2,2) == true){
        tabuleiro[2][2] = 1;
        printX[4] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }
    if (x > 435 && (y > 145 && y < 310 )){
        if(verifica(2,3) == true){
        tabuleiro[2][3] = 1;
        printX[5] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }

    //Linha 3
    if (x < 202 && y > 310){
        if(verifica(3,1) == true){
        tabuleiro[3][1] = 1;
        printX[6] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }
    if ((x > 202 && x < 435) && y > 310){
        if(verifica(3,2) == true){
        tabuleiro[3][2] = 1;
        printX[7] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }
    if (x > 435 && y > 310){
        if(verifica(3,3) == true){
        tabuleiro[3][3] = 1;
        printX[8] = true;
        if(cont == 9){ta = true; return;}
        }
        return;
    }
    return;
}

void moveO(){
    if(ta == true){return;}
    if(iaVitoria() == true) return;
    if(iaDerrota() == true) return;
    int op = rand() % 9;
    cout << op << endl;
    if(op == 0){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[1][1] == 0){
                tabuleiro[1][1] = 2;
                printO[op] = true;
            }
            else{
                moveO();
            }
        }else{
                moveO();
            }
        return;
    }
    if(op == 1){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[1][2] == 0){
                tabuleiro[1][2] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }else{
                moveO();
            }
        return;
    }
    if(op == 2){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[1][3] == 0){
                tabuleiro[1][3] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }else{
                moveO();
            }
        return;
    }
    if(op == 3){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[2][1] == 0){
                tabuleiro[2][1] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }else{
                moveO();
            }
        return;
    }
    if(op == 4){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[2][2] == 0){
                tabuleiro[2][2] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }else{
                moveO();
            }
        return;
    }
    if(op == 5){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[2][3] == 0){
                tabuleiro[2][3] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }else{
                moveO();
            }
        return;
    }
    if(op == 6){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[3][1] == 0){
                tabuleiro[3][1] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }else{
                moveO();
            }
        return;
    }
    if(op == 7){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[3][1] == 0){
                tabuleiro[3][2] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }
        else{
                moveO();
            }
        return;
    }
    if(op == 8){
        if(printX[op] != true && printO[op] != true){
            if(tabuleiro[3][3] == 0){
                tabuleiro[3][3] = 2;
                printO[op] = true;
            }
             else{
                moveO();
            }
        }
        else{
                moveO();
            }
        return;
    }
    moveO();
}

bool iaDerrota(){
    if(tabuleiro[1][1] == 1 && tabuleiro[1][2] == 1) {if(tabuleiro[1][3] == 0){tabuleiro[1][3] = 2; printO[2] = true; return true;}}
    if(tabuleiro[2][1] == 1 && tabuleiro[2][2] == 1) {if(tabuleiro[2][3] == 0){tabuleiro[2][3] = 2; printO[5] = true;  return true;}}
    if(tabuleiro[3][1] == 1 && tabuleiro[3][2] == 1) {if(tabuleiro[3][3] == 0){tabuleiro[3][3] = 2; printO[8] = true;  return true;}}

    if(tabuleiro[1][2] == 1 && tabuleiro[1][3] == 1) {if(tabuleiro[1][1] == 0){tabuleiro[1][1] = 2; printO[0] = true;  return true;}}
    if(tabuleiro[2][2] == 1 && tabuleiro[2][3] == 1) {if(tabuleiro[2][1] == 0){tabuleiro[2][1] = 2; printO[3] = true;  return true;}}
    if(tabuleiro[3][2] == 1 && tabuleiro[3][3] == 1) {if(tabuleiro[3][1] == 0){tabuleiro[3][1] = 2; printO[6] = true;  return true;}}

    if(tabuleiro[1][1] == 1 && tabuleiro[1][3] == 1) {if(tabuleiro[1][2] == 0){tabuleiro[1][2] = 2; printO[1] = true;  return true;}}
    if(tabuleiro[2][1] == 1 && tabuleiro[2][3] == 1) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; printO[4] = true;  return true;}}
    if(tabuleiro[3][1] == 1 && tabuleiro[3][3] == 1) {if(tabuleiro[3][2] == 0){tabuleiro[3][2] = 2; printO[7] = true;  return true;}}

    if(tabuleiro[1][1] == 1 && tabuleiro[2][1] == 1) {if(tabuleiro[3][1] == 0){tabuleiro[3][1] = 2; printO[6] = true;  return true;}}
    if(tabuleiro[1][2] == 1 && tabuleiro[2][2] == 1) {if(tabuleiro[3][2] == 0){tabuleiro[3][2] = 2; printO[7] = true;  return true;}}
    if(tabuleiro[1][3] == 1 && tabuleiro[2][3] == 1) {if(tabuleiro[3][3] == 0){tabuleiro[3][3] = 2; printO[8] = true;  return true;}}

    if(tabuleiro[3][1] == 1 && tabuleiro[2][1] == 1) {if(tabuleiro[1][1] == 0){tabuleiro[1][1] = 2; printO[0] = true;  return true;}}
    if(tabuleiro[3][2] == 1 && tabuleiro[2][2] == 1) {if(tabuleiro[1][2] == 0){tabuleiro[1][2] = 2; printO[1] = true;  return true;}}
    if(tabuleiro[3][3] == 1 && tabuleiro[2][3] == 1) {if(tabuleiro[1][3] == 0){tabuleiro[1][3] = 2; printO[2] = true;  return true;}}

    if(tabuleiro[1][1] == 1 && tabuleiro[3][1] == 1) {if(tabuleiro[2][1] == 0){tabuleiro[2][1] = 2; printO[3] = true;  return true;}}
    if(tabuleiro[1][2] == 1 && tabuleiro[3][2] == 1) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; printO[4] = true;  return true;}}
    if(tabuleiro[1][3] == 1 && tabuleiro[3][3] == 1) {if(tabuleiro[2][3] == 0){tabuleiro[2][3] = 2; printO[5] = true;  return true;}}

    if(tabuleiro[1][1] == 1 && tabuleiro[2][2] == 1) {if(tabuleiro[3][3] == 0){tabuleiro[3][3] = 2; printO[8] = true;  return true;}}
    if(tabuleiro[1][1] == 1 && tabuleiro[3][3] == 1) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; printO[4] = true;  return true;}}
    if(tabuleiro[3][3] == 1 && tabuleiro[2][2] == 1) {if(tabuleiro[1][1] == 0){tabuleiro[1][1] = 2; printO[0] = true;  return true;}}

    if(tabuleiro[1][3] == 1 && tabuleiro[2][2] == 1) {if(tabuleiro[3][1] == 0){tabuleiro[3][1] = 2; printO[6] = true;  return true;}}
    if(tabuleiro[1][3] == 1 && tabuleiro[3][1] == 1) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; printO[4] = true;  return true;}}
    if(tabuleiro[3][1] == 1 && tabuleiro[2][2] == 1) {if(tabuleiro[1][3] == 0){tabuleiro[1][3] = 2; printO[2] = true;  return true;}}
    
    return false;
}

bool iaVitoria(){
    if(tabuleiro[1][1] == 2 && tabuleiro[1][2] == 2) {if(tabuleiro[1][3] == 0){tabuleiro[1][3] = 2; return true;}}
    if(tabuleiro[2][1] == 2 && tabuleiro[2][2] == 2) {if(tabuleiro[2][3] == 0){tabuleiro[2][3] = 2; return true;}}
    if(tabuleiro[3][1] == 2 && tabuleiro[3][2] == 2) {if(tabuleiro[3][3] == 0){tabuleiro[3][3] = 2; return true;}}

    if(tabuleiro[1][2] == 2 && tabuleiro[1][3] == 2) {if(tabuleiro[1][1] == 0){tabuleiro[1][1] = 2; return true;}}
    if(tabuleiro[2][2] == 2 && tabuleiro[2][3] == 2) {if(tabuleiro[2][2] == 0){tabuleiro[2][1] = 2; return true;}}
    if(tabuleiro[3][2] == 2 && tabuleiro[3][3] == 2) {if(tabuleiro[3][3] == 0){tabuleiro[3][1] = 2; return true;}}

    if(tabuleiro[1][1] == 2 && tabuleiro[1][3] == 2) {if(tabuleiro[1][2] == 0){tabuleiro[1][2] = 2; return true;}}
    if(tabuleiro[2][1] == 2 && tabuleiro[2][3] == 2) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; return true;}}
    if(tabuleiro[3][1] == 2 && tabuleiro[3][3] == 2) {if(tabuleiro[3][2] == 0){tabuleiro[3][2] = 2; return true;}}

    if(tabuleiro[1][1] == 2 && tabuleiro[2][1] == 2) {if(tabuleiro[3][1] == 0){tabuleiro[3][1] = 2; return true;}}
    if(tabuleiro[1][2] == 2 && tabuleiro[2][2] == 2) {if(tabuleiro[3][2] == 0){tabuleiro[3][2] = 2; return true;}}
    if(tabuleiro[1][3] == 2 && tabuleiro[2][3] == 2) {if(tabuleiro[3][3] == 0){tabuleiro[3][3] = 2; return true;}}

    if(tabuleiro[3][1] == 2 && tabuleiro[2][1] == 2) {if(tabuleiro[1][1] == 0){tabuleiro[1][1] = 2; return true;}}
    if(tabuleiro[3][2] == 2 && tabuleiro[2][2] == 2) {if(tabuleiro[1][2] == 0){tabuleiro[1][2] = 2; return true;}}
    if(tabuleiro[3][3] == 2 && tabuleiro[2][3] == 2) {if(tabuleiro[1][3] == 0){tabuleiro[1][3] = 2; return true;}}

    if(tabuleiro[1][1] == 2 && tabuleiro[3][1] == 2) {if(tabuleiro[2][1] == 0){tabuleiro[2][1] = 2; return true;}}
    if(tabuleiro[1][2] == 2 && tabuleiro[3][2] == 2) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; return true;}}
    if(tabuleiro[1][3] == 2 && tabuleiro[3][3] == 2) {if(tabuleiro[2][3] == 0){tabuleiro[2][3] = 2; return true;}}

    if(tabuleiro[1][1] == 2 && tabuleiro[2][2] == 2) {if(tabuleiro[3][3] == 0){tabuleiro[3][3] = 2; return true;}}
    if(tabuleiro[1][1] == 2 && tabuleiro[3][3] == 2) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; return true;}}
    if(tabuleiro[3][3] == 2 && tabuleiro[2][2] == 2) {if(tabuleiro[1][1] == 0){tabuleiro[1][1] = 2; return true;}}

    if(tabuleiro[1][3] == 2 && tabuleiro[2][2] == 2) {if(tabuleiro[3][1] == 0){tabuleiro[3][1] = 2; return true;}}
    if(tabuleiro[1][3] == 2 && tabuleiro[3][1] == 2) {if(tabuleiro[2][2] == 0){tabuleiro[2][2] = 2; return true;}}
    if(tabuleiro[3][1] == 2 && tabuleiro[2][2] == 2) {if(tabuleiro[1][3] == 0){tabuleiro[1][3] = 2; return true;}}
    
    return false;
}