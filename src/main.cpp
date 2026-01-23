#include<raylib-cpp.hpp>
#include "ball.hpp"

int main(){
  int screenWidth = 800;
  int screenHeight = 450;
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);  
  raylib::Window window(screenWidth, screenHeight, "Maple Engine - This is some cool shit");
  SetTargetFPS(60);
  Ball TestBall = Ball("graphics/Ball.png", raylib::Vector2(screenWidth / 2.0f, screenHeight / 2.0f));
  
  while(window.ShouldClose() == false){
    BeginDrawing();
      window.ClearBackground(DARKGRAY);
      DrawFPS(3, 3);
      TestBall.Draw();
    EndDrawing();
  }
}
