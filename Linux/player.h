typedef struct player{
    int x;
    int y;
    int jumpcount;
    bool IsJumping;
    int score;
}player;


static player Player;
static player HomePlayer;

int MovePlayer(int PlayerX){
    PlayerX += 2;
} 

int TriggerJumpAt(int XValue){
    if (HomePlayer.x == XValue){
        Player.IsJumping = true;
    }
} 

static void MoveHomePlayer(){
    HomePlayer.x += 2;
}
static void ResetHomePlayerState(){
    HomePlayer.x = 500;
}