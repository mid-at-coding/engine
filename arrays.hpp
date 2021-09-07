#ifndef arrays_h
#define arrays_h
struct returner{
  bool yes = false;
  int arrx = -1;
  int arry = -1;
};
struct point{
  int x = -1;
  int y = -1;
};
struct doublepoint{
  double x = -1;
  double y = -1;
};
enum entitytype {
  AIR,
  PLAYER,
  ENEMY,
  STATICENEMY,
  ATTACK,
};
struct pointbool{
  point pos;
  bool isInArr;
};
double round(double var)
{
    // from 
    // https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    double value = (int)(var * 100 + .5);
    return (float)value / 100;
}
namespace globals{
    enum dir {
      up,
      right,
      down,
      left,
      up_right,
      up_left,
      down_right,
      down_left,
    };
    const int ARRAYSIZE = 100;
    Color ENEMYCOLOR = RED;
    Color PLAYERCOLOR = BLACK;
    Color BACKGROUND = WHITE;
    int screenWidth = 1080;
    int screenHeight = 1080;
}
bool MoveTo(bool barrier[globals::ARRAYSIZE][globals::ARRAYSIZE],double x,double y,int size = 0){
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
#endif
