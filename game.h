#include "player.h"
#include "map.h"
#include "crystal.h"



static void GameInit(){
    map.id = 1;
    Player.x = 100;
    Player.y = 380;
    Player.jumpcount = 10;
    Player.IsJumping = false;
    HomePlayer.x = 100;
    HomePlayer.y = 350; 
    crystal.x  = 500;
    Player.score = 0;
}

static void ResetGameState(){
    Player.score = 0;
    crystal.x = 500;
    map.id = 1;
}