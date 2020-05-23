
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h> 
int main(void)
{
    int homescreen = 1;
    const int screenWidth = 500;
    const int screenHeight = 500;
    int player_x = 100;
    int player_y = 380;
    int home_dino_x = 50;
    int home_dino_y = 350;
    int isjump = 0;
    int jumpcount =10;
    int player_jumpcount = 10;
    int player_isjump = 0;
    int crystal = 0;
    int speedtimer = 5;
    int crystalcount = 0;
    int crystal_x = 500;
    int collison = player_x - crystal_x;
    InitWindow(screenWidth,screenHeight,"DinoGame");
    SetTargetFPS(60);
    Texture2D home_screen = LoadTexture("sprites/home_screen.png");
    Texture2D play_screen = LoadTexture("sprites/cave_Background.png");
    Texture2D player_main = LoadTexture("sprites/dino_sprite.png");
    Texture2D player_home = LoadTexture("sprites/Home_dino.png");
    Texture2D crystal_sprite = LoadTexture("sprites/object.png");
    while (!WindowShouldClose()){
        BeginDrawing();
           if (homescreen == 1) {
               
               DrawTexture(home_screen,0,0,WHITE);
               DrawTexture(player_main,home_dino_x,home_dino_y,WHITE);
               home_dino_x += 2;
               if (home_dino_x == 190){
                   /*Preform Jump| */
                   isjump = 1;
               }
               if (home_dino_x == 410){
                   isjump = 1;
               }
               if (isjump == 1){
                   if (jumpcount >= -10){
                       home_dino_y -= (jumpcount * abs(jumpcount)) * .2;
                       home_dino_x += 2;
                       jumpcount -= 1;
                   }
                   else{
                       jumpcount = 10;
                       home_dino_y = 350;
                       isjump = 0;
                   }
               }
               if (home_dino_x >= 550){
                   home_dino_x-=500;
               }
               if (IsKeyDown(KEY_SPACE)){homescreen = 0;}
           }
           if (homescreen == 0){
               crystalcount += 1;
               ClearBackground(LIGHTGRAY);
               DrawTexture(player_main,player_x,player_y,WHITE);
               DrawTexture(play_screen,0,0,LIGHTGRAY);
               if (IsKeyDown(KEY_SPACE)){player_isjump = 1;}
               if (player_x - crystal_x <= 50 && player_x - crystal_x >= 0 && player_y - 380 >= -50){
                   homescreen = 1;
                   crystal_x = 500;
                   crystalcount = 0;
               }
               if (crystalcount == 100){ 
                   crystal = 1;
               }
               if (crystal == 1){
                   DrawTexture(crystal_sprite,crystal_x,380,WHITE);
                   crystal_x -=10;
                   if (crystal_x == 0){
                       crystal_x = 500;
                       speedtimer += 1;
                       crystalcount = 0;
                       crystal = 0;
                   }
               }
               if (player_isjump == 1){
                   if (player_jumpcount >= -10){
                       player_y -= (player_jumpcount * abs(player_jumpcount)) * .6;
                       player_jumpcount -= 1;
                   }
                   else{
                       player_jumpcount = 10;
                       player_y = 380;
                       player_isjump = 0;
                   }
               }
           }
        EndDrawing();
    }
    UnloadTexture(home_screen);
    UnloadTexture(play_screen);
    UnloadTexture(player_main);
    CloseWindow();
}