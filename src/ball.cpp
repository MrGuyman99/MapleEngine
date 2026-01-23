#include "ball.hpp"

Ball::Ball(std::string ImagePath, raylib::Vector2 Position){
  this->Position = Position;
  BallTexture = raylib::Texture(ImagePath);
}

void Ball::Draw(){
  BallTexture.Draw(Position);
}
//TODO: Make the Ball bounce
void Ball::Update(){

}
