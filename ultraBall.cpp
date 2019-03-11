#include "ultraBall.h"
 
UltraBall::UltraBall(float startX, float startY): Ball(startX, startY)
{
    ballShape.setFillColor(sf::Color::White);
}
/*void UltraBall::copyBall(Ball b)
{
    position.y = b.position.x;
    position.x = b.position.y;
}*/

void UltraBall::copyBall(UltraBall b)
{
    position.y = b.position.x;
    position.x = b.position.y;
}

void UltraBall::update(int score)
{
     // обновляем позицию мяча
       position.y += (1+(score/10))*yVelocity;
       position.x += (1+(score/10))*xVelocity;
       if (score/10 == 1)
           ballShape.setFillColor(sf::Color::Green);
       if (score/10 > 1)
           ballShape.setFillColor(sf::Color::Red);
    // Двигаем мяч и биту
       ballShape.setPosition(position);
}
