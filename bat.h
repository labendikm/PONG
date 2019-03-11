#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat  // наша бита
{
private:
    Vector2f position; // позиция биты
    
    // объект формы прямоугольника
    RectangleShape batShape;
    
    float batSpeed = .3f;
    
public:
    Bat(float startX, float startY);
    
    FloatRect getPosition();
    
    RectangleShape getShape();
    
    void moveLeft();
    
    void moveRight();
    
    void update(); // столкновение, которое будет раз в кадр 
    
};
