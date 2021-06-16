#include "raylib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "engine.hpp"
using namespace std;
int main(){
    cattoEngine::game_array test;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(globals::screenWidth, globals::screenHeight, "game");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    test.Init();
    test.GetData("test.txt");
    while (!WindowShouldClose()){
    //    test.character.speed = 20;
    //    test.character.diagspeed = 10;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        test.UpdateLogic();
        test.RenderArr();
        EndDrawing();
      }
}
