#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Obstacle
{
protected:
    Vector2f position;
    
    RectangleShape obstacleShape;
    
public:
    Obstacle();
    
    Obstacle(float startX, float startY);
    
    FloatRect getPosition();
    
    void setPlace(float x, float y);
    
    RectangleShape getShape();
    
};

