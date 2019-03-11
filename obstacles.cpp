#include "obstacles.h"

Obstacle::Obstacle()
{
    position.x = 0;
    position.y = 0;
    
    obstacleShape.setSize(sf::Vector2f(64, 20));
    obstacleShape.setPosition(position);
}

Obstacle::Obstacle(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
    
    obstacleShape.setSize(sf::Vector2f(120, 10));
    obstacleShape.setPosition(position);
}

FloatRect Obstacle::getPosition()
{
    return obstacleShape.getGlobalBounds();
}

RectangleShape Obstacle::getShape()
{
    return obstacleShape;
}

void Obstacle::setPlace(float x, float y)
{
    position.x = x;
    position.y = y;
    obstacleShape.setPosition(position);
}

