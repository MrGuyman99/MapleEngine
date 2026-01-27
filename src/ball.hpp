#pragma once
#include<raylib-cpp.hpp>

class Ball{  
public:
  Ball(std::string Image_Path, raylib::Vector2 StartPos);
  void Draw();
  void Update();
  raylib::Vector2 Position;
  raylib::Vector2 Velocity;
  double radius;
private:
  raylib::Texture BallTexture; 
};
