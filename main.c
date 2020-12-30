#include "libs/raylib.h"

#include "game.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

int main(void)
{
    GameInit();
    InitWindow(500,500,"CDG-Ripoff");
    SetTargetFPS(60);
    Texture2D home_screen = LoadTexture("sprites/home_screen.png");
    Texture2D play_screen = LoadTexture("sprites/cave_Background.png");
    Texture2D player_main = LoadTexture("sprites/dino_sprite.png");
    Texture2D player_home = LoadTexture("sprites/Home_dino.png");
    Texture2D crystal_sprite = LoadTexture("sprites/object.png");

    while (!WindowShouldClose()){
        BeginDrawing();
        switch (map.id)
        {      
            case 1:
                DrawTexture(home_screen,0,0,WHITE);
                DrawTexture(player_main,HomePlayer.x,HomePlayer.y,WHITE);
                TriggerJumpAt(190);
                TriggerJumpAt(410);
                HomePlayer.x += 2;

                if (Player.IsJumping == 1){
                    if (Player.jumpcount >= -10){
                        HomePlayer.y -= (Player.jumpcount * abs(Player.jumpcount)) * .2;
                        HomePlayer.x += 2;
                        Player.jumpcount -= 1;
                    }
                    else{
                        Player.jumpcount = 10;
                        HomePlayer.y = 350;
                        Player.IsJumping = 0;
                    }
                }
                if (HomePlayer.x >= 550){
                    HomePlayer.x-=500;
                }

                if (IsKeyDown(KEY_SPACE)){map.id = 2;} // Transition To The Main Game Screen
                break;
        case 2:
            ClearBackground(WHITE);
            DrawTexture(player_main,Player.x,Player.y,WHITE);
            DrawTexture(play_screen,0,0,LIGHTGRAY);
            DrawTexture(crystal_sprite,crystal.x,380,WHITE);

            if (IsKeyDown(KEY_SPACE)){
                Player.IsJumping = 1;
            }

            if (Player.x - crystal.x <= 50 && Player.x - crystal.x >= 0 && Player.y - 380 >= -50){
                Player.score = 0;
                crystal.x = 500;
                map.id = 1;
            }

            if (crystal.x == 0){
                crystal.x = 500;
                Player.score ++;
            } 

            if (Player.IsJumping == 1){
                if (Player.jumpcount >= -10){
                    Player.y -= (Player.jumpcount * abs(Player.jumpcount)) * .4;
                    Player.jumpcount -= 1;
                }
                else{
                    Player.jumpcount = 10;
                    Player.y = 380;
                    Player.IsJumping = 0;
                }
            }
            MoveCrystal();
            DrawText(TextFormat("Score: %02i", Player.score), 375, 200, 20, BLACK);
            break;
        }
        EndDrawing();
    }
    UnloadTexture(home_screen);
    UnloadTexture(play_screen);
    UnloadTexture(player_main);
    CloseWindow();
}