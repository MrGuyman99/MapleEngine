#include<raylib-cpp.hpp>
#include "ball.hpp"
#include "camera.hpp"

int main(){
  
  //Windowing Stuff
  int screenWidth = 800;
  int screenHeight = 450;
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);  
  raylib::Window window(screenWidth, screenHeight, "Maple Engine - This is some cool shit");
  SetTargetFPS(60);
  
  Ball TestBall = Ball("graphics/Ball.png", raylib::Vector2(screenWidth / 2.0f, screenHeight / 2.0f));
  raylib::Camera2D camera = raylib::Camera2D({ 0 });
  //This needs to be initialized or else nothing draws ¯\_(ツ)_/¯
  camera.zoom = 1.0f;

  //Main Game Loop
  while(window.ShouldClose() == false){
    window.BeginDrawing();
      window.ClearBackground(DARKGRAY);
      DrawFPS(3, 3);
      CustomCamera::Update(camera);
      camera.BeginMode();
        TestBall.Draw();
      camera.EndMode();
    window.EndDrawing();
  }
}