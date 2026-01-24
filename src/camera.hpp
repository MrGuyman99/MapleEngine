#include<raylib-cpp.hpp>

class CustomCamera{
public:
    CustomCamera(raylib::Camera2D &camera);
    raylib::Camera2D Update();
private:
    raylib::Camera2D camera;
};