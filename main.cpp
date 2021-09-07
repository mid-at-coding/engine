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
    //SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()) * 2);
    SetTargetFPS(120);
    test.Init();
    Texture2D playertext = LoadTexture("Image.png");
    Texture2D background = LoadTexture("Image1.png");
    vector<cattoEngine::attack*> current;
    cattoEngine::attack e(
        { 0 , 0 },
        5 ,
        { 100 , 100 },
        true,
        playertext,
        false ,
        20
    );
    current.push_back(&e);
    while (!WindowShouldClose()){
        test.character.speed = 40;
        test.character.diagspeed = 20;
        test.character.size = 0;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        test.UpdateLogic();
        (*current[0]).update();
        test.RenderArr(playertext , background , current);
        EndDrawing();
      }

}
