typedef struct Crystal
{
    /* data */
    int x;
}Crystal;

static Crystal crystal;


static void MoveCrystal(){
    crystal.x -= 10;
}

int IfCrystalCollision(){
    if (Player.x - crystal.x <= 50 && Player.x - crystal.x >= 0 && Player.y - 380 >= -50){
        return true;
    }
}
static void ResetCrytalState(){
    crystal.x = 500; 
    Player.score ++;
}