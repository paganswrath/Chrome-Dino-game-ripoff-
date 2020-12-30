typedef struct player{
    int x;
    int y;
    int jumpcount;
    int IsJumping;
    int score;
}player;

static player Player;
static player HomePlayer;

int MovePlayer(int PlayerX){
    PlayerX += 2;
} 

int TriggerJumpAt(int XValue){
    if (HomePlayer.x == XValue){
        Player.IsJumping = 1;
    }
} 