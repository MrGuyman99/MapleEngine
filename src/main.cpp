#include<raylib-cpp.hpp>
#include "ball.hpp"
#include "camera.hpp"
#include "constants.hpp"
#include "rlImGui.h"

int main(){
  
  //Windowing Stuff
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);  
  raylib::Window window(Constants::screenWidth, Constants::screenHeight, "Maple Engine - This is some cool shit");
  SetTargetFPS(100);
  rlImGuiSetup(true);

  Ball TestBall = Ball("graphics/Ball.png", raylib::Vector2(Constants::screenWidth / 2.0f, Constants::screenHeight / 2.0f), 8);
  raylib::Camera2D camera = raylib::Camera2D({ 0 });
  raylib::Vector2 Background = raylib::Vector2(0, 0);
  //This needs to be initialized or else nothing draws ¯\_(ツ)_/¯
  camera.zoom = 1.0f;

  //Main Game Loop
  while(window.ShouldClose() == false){
    window.BeginDrawing();
      window.ClearBackground(DARKGRAY);
      CustomCamera::Update(camera);
      TestBall.Update();
      //All things that need to be drawn relative to scale
      camera.BeginMode();
        Background.DrawRectangle(raylib::Vector2(Constants::screenWidth, Constants::screenHeight), BLUE);
        TestBall.Draw();
      camera.EndMode();
      //ImGui Stuff
      rlImGuiBegin();
        TestBall.Ui();
      rlImGuiEnd();
      DrawFPS(3, 3);
    window.EndDrawing();
  }
}
