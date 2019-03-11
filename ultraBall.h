#pragma once
#include <SFML/Graphics.hpp>
#include "ball.h"
 using namespace sf;
 
 class UltraBall: public Ball
 {
 public:
     UltraBall(float startX, float startY);
     void copyBall(Ball b);
     void copyBall(UltraBall b);
     void update(int score);
 };


