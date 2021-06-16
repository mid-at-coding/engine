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
  double ybottom;
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
