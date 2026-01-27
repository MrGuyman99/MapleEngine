#include "ball.hpp"
#include "constants.hpp"

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

  if(Position.GetX() > Constants::screenWidth || Position.GetX() < 0){
    Velocity.SetX(Velocity.GetX() * -1);
  }

  if(Position.GetY() > Constants::screenHeight || Position.GetY() < 0){
    Velocity.SetY(Velocity.GetY() * -1);
  }

}
