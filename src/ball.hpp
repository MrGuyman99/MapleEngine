#pragma once
#include<raylib-cpp.hpp>

class Ball{  
public:
  Ball(std::string Image_Path, raylib::Vector2 StartPos, double radius);
  void Draw();
  void Update();
  void Ui();
  raylib::Vector2 Position;
  raylib::Vector2 Velocity;
  float radius;
private:
  raylib::Texture BallTexture; 
};
