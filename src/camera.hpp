#pragma once
#include<raylib-cpp.hpp>

//This actually doesn't have to be a class!
//All we really do is just alter the exsisting camera's data in main.cpp
//That's why we don't have a return and are just using a pointer
namespace CustomCamera{
    void Update(raylib::Camera2D &camera);
};