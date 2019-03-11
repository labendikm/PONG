#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>

using namespace sf;

class Ball
{
protected:
    Vector2f position;
    RectangleShape ballShape; // форма - прямоугольник
    
    /*float xVelocity = .2f;
    float yVelocity = .2f;*/
    float xVelocity = 0.1 + 0.1f * (rand()%100)/(100 * 1.0);
    float yVelocity = (float)sqrt(2*.2f*.2f - xVelocity*xVelocity);
    
    
public:
    Ball(float startX, float startY);
    
    FloatRect getPosition();
    
    RectangleShape getShape();
    
    float getXVelocity();
    
    void reboundSides();
    
    void reboundBatOrTop();
    
    void reboundObstacle_dt(); // удар о препятствие сверху и снизу
    
    void reboundObstacle_rl(); // удар о препятствие сбоку
    
    void hitBottom();
    
    void copyBall(Ball b);
    
    void update(int score);

    
};
