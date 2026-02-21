#include "ball.hpp"
#include "constants.hpp"
#include "imgui.h"

Ball::Ball(std::string ImagePath, raylib::Vector2 Position, double radius){
  this->Position = Position;
  this->radius = radius;
  BallTexture = raylib::Texture(ImagePath);
  Velocity = raylib::Vector2(5, 5);
}

void Ball::Draw(){
  Position.DrawCircle(radius, PURPLE);
}
//TODO: Make the Ball bounce
void Ball::Update(){
  Position += Velocity;

  if(Position.GetX() + radius > Constants::screenWidth || Position.GetX() - radius < 0){
    Velocity.SetX(Velocity.GetX() * -1);
  }
  // Left
  if(Position.GetY() + radius > Constants::screenHeight || Position.GetY() - radius < 0){
    Velocity.SetY(Velocity.GetY() * -1);
  }

}

void Ball::Ui(){
  ImGui::Begin("Ball Window");
    ImGui::DragFloat("Radius", &radius, 1.0f, 8.0f, 100.0f);
  ImGui::End();
}
