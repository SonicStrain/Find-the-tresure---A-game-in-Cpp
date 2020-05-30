#include <iostream>
#include "windows.h"
#include <cstdio>
using namespace std;

void gotoXY(int x,int y){
    COORD crd;
    crd.X = x;
    crd.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
}

int area[50][30];


void drawRect(int a,int b){
       int x = 1 , y = 1;

       for(int i=x;i<=(x+a);i++){
           area[i][y] = 1;
           area[i][y+b] = 1;
       }
       for(int i=y;i<=(y+b);i++){
           area[x][i] = 1;
           area[x+a][i] = 1;
       }

}

void drawGrid(int grid,int a,int b){
       int x = 1 , y = 1, gridValX = 0 , gridValY = 0;

       for(int i = 0;i < grid-1;i++){
           gridValY += 5;
           gridValX += 11;
           for(int i = x;i<=x+a;i++){
               area[i][y+gridValY] = 1;
           }
           for(int i = y;i<=y+b;i++){
               area[x+gridValX][i] = 1;
           }
       }
}

void drawTre(int treX,int treY){
       int x = 6 + 11*(treX-1),y = 3 + 5*(treY-1);

       area[x][y] = 1;
       area[x-1][y] = 1;
       area[x+1][y] = 1;
       area[x][y+1] = 1;
       area[x-1][y+1] = 1;
       area[x+1][y+1] = 1;
       area[x-2][y-1] = 1;
       area[x-2][y+2] = 1;
       area[x+2][y-1] = 1;
       area[x+2][y+2] = 1;
}

class Bot{

  private:
      int x,y;
  public:
      void init_bot(int botX,int botY){
           x = 6 + 11*(botX-1);
           y = 3 + 5*(botY-1);

      }
      void drawBot(){
       area[x-1][y-1] = 1;
       area[x+1][y-1] = 1;
       area[x][y-1] = 1;
       area[x][y+2] = 1;
       area[x-1][y+2] = 1;
       area[x+1][y+2] = 1;
       area[x-2][y] = 1;
       area[x-2][y+1] = 1;
       area[x+2][y] = 1;
       area[x+2][y+1] = 1;
     }

     void eraseBot(){

       area[x-1][y-1] = 0;
       area[x+1][y-1] = 0;
       area[x][y-1] = 0;
       area[x][y+2] = 0;
       area[x-1][y+2] = 0;
       area[x+1][y+2] = 0;
       area[x-2][y] = 0;
       area[x-2][y+1] = 0;
       area[x+2][y] = 0;
       area[x+2][y+1] = 0;

    }

};

void clearScreen(){
    for(int i=0;i<50;i++){
        for(int j=0;j<30;j++){
            area[i][j] = 0;
        }
    }
}

void drawGame(){
    bool running = true;

    while(running){
        for(int i=0;i<50;i++){
            for(int j=0;j<30;j++){
                if(area[i][j] == 1){
                    gotoXY(i,j);
                    cout << "*";
                }else{
                    gotoXY(i,j);
                    cout << " ";
                }
                if(i == 49 && j == 29) running = false;
            }
        }
    }
}

void gameInfo(){

    printf("************ABOUT THE GAME************\n");
    printf("In this game you have to help the\nbot 'O' to find the Treasure!\n");
    printf("______________________________________\n");
    printf("_____________INSTRUCTIONS_____________\n");
    printf(">> The map is a 4x4 matrix and every\nsub-division of the matrix is denoted\nas (a,b).\nRanging (1,1) to (4,4).\n");
    printf("\n>> The position of the Treasure is\ninputed manually and the position of\nthe player bot is generated randomly.\n");
    printf("\n>> USE ARROW KEYS TO MOVE THE BOT.\n");
    printf("\n>> USE THE LEFT SHIFT KEY TO TRIGGER\nTHE AI! AND LET IT SOLVE YOU!\n");
    printf("______________________________________\n");
    system("pause");
}
//FINAL FUNCTION
void startGame(Bot B,int botX,int botY,int treX,int treY){

    drawGame();
    while(!GetAsyncKeyState(VK_ESCAPE)){
        if(botX == treX && botY == treY){
            clearScreen();
            drawGame();
            gotoXY(24,4);
            printf("CONGRATULATIONS!YOU FOUND IT!");
            gotoXY(24,14);
            printf("<<            BY           >>");
            gotoXY(24,24);
            printf("_______ SAGEN SOREN! ______\n");
            Sleep(2000);
            break;
        }
        if(GetAsyncKeyState(VK_DOWN)){
            B.eraseBot();
            botY++;
            if(botY == 5){
                botY = 4;
            }
            B.init_bot(botX,botY);
            B.drawBot();
            drawGame();
            Sleep(1000);
        }

        if(GetAsyncKeyState(VK_UP)){
            B.eraseBot();
            botY--;
            if(botY == 0){
                botY = 1;
            }
            B.init_bot(botX,botY);
            B.drawBot();
            drawGame();
            Sleep(1000);
        }

        if(GetAsyncKeyState(VK_RIGHT)){
            B.eraseBot();
            botX++;
            if(botX == 5){
                botX = 4;
            }
            B.init_bot(botX,botY);
            B.drawBot();
            drawGame();
            Sleep(1000);
        }

        if(GetAsyncKeyState(VK_LEFT)){
            B.eraseBot();
            botX--;
            if(botY == 0){
                botY = 1;
            }
            B.init_bot(botX,botY);
            B.drawBot();
            drawGame();
            Sleep(1000);
        }
        if(GetAsyncKeyState(VK_LSHIFT)){
            while(treX != botX){
                if(botX < treX){
                    B.eraseBot();
                    botX++;
                    B.init_bot(botX,botY);
                    B.drawBot();
                    drawGame();
                    Sleep(1000);
                }
                if(botX > treX){
                    B.eraseBot();
                    botX--;
                    B.init_bot(botX,botY);
                    B.drawBot();
                    drawGame();
                    Sleep(1000);
                }
            }

             while(treY != botY){
                if(botY < treY){
                    B.eraseBot();
                    botY++;
                    B.init_bot(botX,botY);
                    B.drawBot();
                    drawGame();
                    Sleep(1000);
                }
                if(botY > treY){
                    B.eraseBot();
                    botY--;
                    B.init_bot(botX,botY);
                    B.drawBot();
                    drawGame();
                    Sleep(1000);
                }
            }
        }
    }
}



int main()
{
    gameInfo();
    // the size of the box
    int a = 44 , b = 20;

    drawRect(a,b);

    // no of grids
    int grid  = 4;
    drawGrid(grid,a,b);

    //draw the TRESURE
    int treX = 1, treY = 1;
    //X for treasure
    printf("Enter X coordinate of Treasure[1,4] : ");
    scanf("%d",&treX);
    while(treX > 4 || treX < 1){
        printf("This input is invalid!Enter correct value!\n");
        printf("Enter X coordinate of Treasure[1,4] : ");
        scanf("%d",&treX);
    }
    //Y for treasure
    printf("Enter Y coordinate of Treasure[1,4] : ");
    scanf("%d",&treY);
    while(treY > 4 || treY < 1){
        printf("This input is invalid!Enter correct value!\n");
        printf("Enter Y coordinate of Treasure[1,4] : ");
        scanf("%d",&treY);
    }
    drawTre(treX,treY);

    //draw the BOT
    Bot botman;
    int botX = treX, botY = treY;
    while(botX == treX){
        botX = 1 + (rand() % 4);
    }
    while(botY == treY){
        botY = 1 + (rand() % 4);
    }
    botman.init_bot(botX,botY);
    botman.drawBot();

    startGame(botman,botX,botY,treX,treY);

    system("pause");

    return 0;
}
