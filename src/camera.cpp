#include "camera.hpp"
#include "constants.hpp"

void CustomCamera::Update(raylib::Camera2D &camera){
  //Panning code + Zooming Code, finagled from raylib proper to raylib-cpp
  //Found here -> https://www.raylib.com/examples/core/loader.html?name=core_2d_camera_mouse_zoom
  if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)){
    raylib::Vector2 Delta = raylib::Mouse::GetDelta();
    //delta.Scale is broken in some way, so we have to use the vanilla raylib function
    Delta = Vector2Scale(Delta, -1.0f / camera.zoom);
    camera.target = Delta.Add(camera.target);
  }

  float wheel = raylib::Mouse::GetWheelMove();
  if(wheel != 0){
    //Get the world point that is under the mouse
    raylib::Vector2 MouseWorldPos = camera.GetScreenToWorld(raylib::Mouse::GetPosition());
    
    //Set the offset to where the mouse is
    camera.offset = raylib::Mouse::GetPosition();
    
    //Set the target to match, so that the camera maps the world space point
    //Under the cursor to the screen space point under the cursor at any zoom
    camera.target = MouseWorldPos;
    
    //Zoom increment
    //Uses the log scaling to provide a consistent zoom speed
    float scale = 0.2f * wheel;
    camera.zoom = Clamp(expf(logf(camera.zoom) + scale), 0.125f, 64.0f);
    
    //To prevent the camera from zooming too far outside of the default
    if(camera.zoom < 1){
      camera.zoom = 1;
    }
  }
}