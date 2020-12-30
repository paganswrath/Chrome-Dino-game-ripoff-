typedef struct Crystal
{
    /* data */
    int x;
}Crystal;

static Crystal crystal;


static void MoveCrystal(){
    crystal.x -= 10;
}