#include "ball.hpp"
#include "constants.hpp"
#include<iostream>

Ball::Ball(std::string ImagePath, raylib::Vector2 Position){
  this->Position = Position;
  BallTexture = raylib::Texture(ImagePath);
  Velocity = raylib::Vector2(8, 8);
}

void Ball::Draw(){
  BallTexture.Draw(Position);
}
//TODO: Make the Ball bounce
void Ball::Update(){
  Position += Velocity;

  if(Position.GetX() > Constants::screenWidth + Constants::screenWidth / 2.0f || Position.GetX() < Constants::screenWidth / 2.0f){
    Velocity.SetX(Velocity.GetX() * -1);
  }

  if(Position.GetY() > Constants::screenHeight + Constants::screenHeight / 2.0f || Position.GetY() < Constants::screenHeight / 2.0f){
    Velocity.SetY(Velocity.GetY() * -1);
  }

}
