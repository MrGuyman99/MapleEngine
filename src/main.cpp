#include<raylib-cpp.hpp>

int main() {
  int screenWidth = 800;
  int screenHeight = 450;
  raylib::Window window(screenWidth, screenHeight, "raylib-cpp - basic window");
  SetTargetFPS(60);

  while(window.ShouldClose() == false){
    BeginDrawing();
      window.ClearBackground(RAYWHITE);
      DrawFPS(3, 3);
    EndDrawing();
  }
}
