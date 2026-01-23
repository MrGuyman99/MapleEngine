#include<raylib-cpp.hpp>
#include "ball.hpp"

int main(){
  int screenWidth = 800;
  int screenHeight = 450;
  raylib::Window window(screenWidth, screenHeight, "raylib-cpp - basic window");
  Ball TestBall = Ball("graphics/Ball.png", raylib::Vector2(screenWidth / 2.0f, screenHeight / 2.0f));
  SetTargetFPS(60);
  
  while(window.ShouldClose() == false){
    BeginDrawing();
      window.ClearBackground(DARKGRAY);
      DrawFPS(3, 3);
      TestBall.Draw();
    EndDrawing();
  }
}
