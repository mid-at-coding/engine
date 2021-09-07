#ifndef attacks_h
#define attacks_h
#include <cstdlib>
#include <cmath>
using namespace std;
namespace cattoEngine{
    class attack{
        doublepoint start;
        point findMid(point x, point y) {
            point midpoint;
            midpoint.x = (x.x + y.x) / 2;
            midpoint.y = (y.y + x.y) / 2;
            return midpoint;
        }
        doublepoint nextPoint(double dist) {
            double slopeX, slopeY;
            doublepoint next;
            slopeX = abs(start.x - facing.x);
            slopeY = abs(start.y - facing.y);
          //cout << endl << slopeX << " " << slopeY;
            while (max(slopeX, slopeY) > dist) {
                slopeX /= 2;
                slopeY /= 2;
            }
            double dt = GetFrameTime();
            next.x = pos.x + slopeX * dt;
            next.y = pos.y + slopeY * dt;
            return next;
        }
      public :
        int size;
        doublepoint pos;
        doublepoint bottomright;
        point facing;
        double speed;
        Texture2D attackTexture;
        bool friendly;
        bool bouncing;
        bool oob; // out of bounds
        void SetupAttack(point position,int size, point direction, bool isfriendly, Texture2D attackTexture , bool bounce = false , double movespeed = 0.5){
            if (position.x == 0) {
                position.x++;
            }
            if (position.y == 0) {
                position.y++;
            }
            if (position.x == globals::ARRAYSIZE) {
                position.x--;
            }
            if (position.y == globals::ARRAYSIZE) {
                position.y--;
            }
            (*this).pos.x = (double)position.x;
            (*this).pos.y = (double)position.y;
            bottomright = { pos.x + size, pos.y + size };
            facing = direction;
            (*this).size = size;
            friendly = isfriendly;
            speed = movespeed;
            (*this).attackTexture = attackTexture;
            start = pos;
            bouncing = bounce;
        }
        attack(point position, int size, point direction, bool isfriendly, Texture2D attackTexture, bool bounce = false, double movespeed = 0.5) {
            if (position.x == 0) {
                position.x++;
            }
            if (position.y == 0) {
                position.y++;
            }
            if (position.x == globals::ARRAYSIZE) {
                position.x--;
            }
            if (position.y == globals::ARRAYSIZE) {
                position.y--;
            }
            (*this).pos.x = (double)position.x;
            (*this).pos.y = (double)position.y;
            bottomright = { pos.x + size, pos.y + size };
            facing = direction;
            (*this).size = size;
            friendly = isfriendly;
            speed = movespeed;
            (*this).attackTexture = attackTexture;
            start = pos;
            bouncing = bounce;
        }
        void update() {
            doublepoint old = pos;
            pos.x = nextPoint (speed).x;
            pos.y = nextPoint (speed).y;
            cout << pos.x << ' ' << pos.y << endl;

            if (pos.x >= globals::ARRAYSIZE || pos.y >= globals::ARRAYSIZE || pos.x <= 0 || pos.y <= 0) {
                if (bouncing) {
                    // not implemented yet
                }
                else{
                    oob = true;
                    pos = { globals::ARRAYSIZE + 100 , globals::ARRAYSIZE + 100 };
                    facing.x = pos.x;
                    facing.y = pos.y;
                }
            }
        }
    };
}

#endif
