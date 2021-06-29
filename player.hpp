#ifndef player_h
#define player_h

 class player{
    public :
    int size = 5;
    doublepoint pos = {globals::ARRAYSIZE / 2 , globals::ARRAYSIZE / 2};
    doublepoint bottomright = {globals::ARRAYSIZE / 2 + size, globals::ARRAYSIZE / 2 + size};
    double speed = 0.5;
    double diagspeed = 0.25;
    int direction = 0;
    //0 - facing up
    //1 - facing right
    //2 - facing down
    //3 - facing left
    int points = 0;
    int hp = 1;
    //the idea here is that its a fraction instead of actual hitpoints
      bool MoveTo(bool barrier[globals::ARRAYSIZE][globals::ARRAYSIZE],double x,double y){
        double xbottom = x + size;
        double ybottom = y + size;
        if(x >= globals::ARRAYSIZE || y >= globals::ARRAYSIZE) return false;
        if(y <= 0 || x <= 0) return false;
        if(barrier[int(x)][int(y)]) return false;
        if(xbottom >= globals::ARRAYSIZE || ybottom >= globals::ARRAYSIZE) return false;
        if(ybottom <= 0 || xbottom <= 0) return false;
        if(barrier[int(xbottom)][int(ybottom)]) return false;
        //if its not invalid space
        else {
          return true;
        };
      }
  };


#endif
