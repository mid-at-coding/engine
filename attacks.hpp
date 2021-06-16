#ifndef attacks_h
#define attacks_h
using namespace std;
namespace cattoEngine{
    class attack{
      public :
        int size;
        doublepoint pos;
        doublepoint bottomright;
        int facing;
        double speed;
        double diagspeed;
        Color attackcolour = BLUE;
        bool friendly;
        Color GetColour(){
          return attackcolour;
        }
        void SetupAttack(point position,int size, int direction, bool isfriendly, double movespeed = 0.5, double diagmovespeed = 0.25){
          pos = {position.x, position.y};
          bottomright = {pos.x + size, pos.y + size};
          facing = direction;
          friendly = isfriendly;
          speed = movespeed;
          diagspeed = diagmovespeed;
      }
    };
}

#endif
