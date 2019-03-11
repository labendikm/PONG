#include "ball.h"

Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
    
    ballShape.setSize(sf::Vector2f(50, 50));
    ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
    
}

void Ball::reboundObstacle_dt() 
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
}

void Ball::reboundObstacle_rl()
{
    position.x -= (xVelocity * 30);
    xVelocity = -xVelocity;
}

void Ball::hitBottom()
{
    position.y = 660;
    position.x = 500;
    xVelocity = -xVelocity;
    yVelocity = -yVelocity;
}

void Ball::copyBall(Ball b)
{
    position.y = b.position.x;
    position.x = b.position.y;
}

void Ball::update(int score)
{
    // обновляем позицию мяча
    position.y += yVelocity;
    position.x += xVelocity;
    
    // Двигаем мяч и биту
    ballShape.setPosition(position);
}
