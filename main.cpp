#include "bat.h"
#include "ball.h"
#include "obstacles.h"
#include "ultraBall.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"

#define n 21
using namespace sf;

int main()
{
    
    
    int windowWidth = 1024; // ширина поля
    int windowHeight = 768; // высота поля
    RenderWindow window(VideoMode(windowWidth, windowHeight), "PONGISHE"); // создаем окошко
    sf::Font font; // создаем шрифт
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("", font, 50); // вставка текста, счета
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(50);
    int score = 0; // счет
    int lives = 3; // жизни
    Bat bat (windowWidth / 2, windowHeight - 20); // создаем биту
    UltraBall ball(windowWidth / 2, 700); // создаем мяч
    //ball.ballShape.setFillColor(sf::Color::Yellow);
    Obstacle obs[n];
    for (int i = 0; i < n; ++i)
    {
        obs[i].setPlace(32 + 128 * i, 120);
    }
    for (int i = 8; i < n; ++i)
    {
        obs[i].setPlace(32 + 64 + 128 * (i - 8), 200);
    }
    for (int i = 15; i < n; ++i)
    {
        obs[i].setPlace(32 + 64 + 64 + 128 * (i - 15), 280);
    }
    
    
    
    int ishere[n];
    for (int i = 0; i < n; ++i)
    {
        ishere[i] = 1;
    }
    
    int c = 0; // счетчик числа сбитых препятствий
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Если кто-то закрыл, выходим
                window.close();
        }
        if ((lives == 0) || (c == 21))
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            // влево
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            // вправо
            bat.moveRight();
            
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            //выходим по кнопке escape
            window.close();
        }
        
        
        if (ball.getPosition().top > windowHeight)
        {
            // резетимся
            ball.hitBottom();
            
            // забираем жизнь
            lives --;
            
            // проверяем, не сдохли ли мы
            /*if (lives < 1) {
                // обнуляем счет
                score = 0;
                // восстанавливаем жизни
                lives = 3;
            }*/
            
        }
        
        // Handle ball hitting top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
            
            // Add a point to the players score
            score++;
            
        }
        
        // Handle ball hitting sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + 50 > windowWidth)
        {
            ball.reboundSides();
        }
        
        /*if (ball.getPosition().intersects(obstacle.getPosition()) && (ball.getPosition().top  )
        {
            ball.reboundObstacle_rl();
        }*/
        
        /*if (ball.getPosition().intersects(obs[0].getPosition()) && (c == 1))
        {
            ball.reboundObstacle_dt();
            c = 0;
        }*/
        for (int i = 0; i < n; ++i)
        {
            /*if  (
                (ball.getPosition().intersects(obs[i].getPosition()) && (ishere[i] == 1)) &&
                (((ball.getPosition().left < obs[i].getPosition().left + 60) && (ball.getPosition().left > obs[i].getPosition().left)) ||
                ((ball.getPosition().left + 60 > obs[i].getPosition().left) && (ball.getPosition().left < obs[i].getPosition().left)))
                )
            {
                ball.reboundObstacle_rl();
                ishere[i] = 0;
                score++;
            }*/
            if(
               (ball.getPosition().intersects(obs[i].getPosition()) && (ishere[i] == 1)) &&
               (((ball.getPosition().left < obs[i].getPosition().left - 49) && (ball.getPosition().left > obs[i].getPosition().left - 51)) ||
               ((ball.getPosition().left < obs[i].getPosition().left + 65) && (ball.getPosition().left > obs[i].getPosition().left + 63)))
               
               )
            {
                ball.reboundObstacle_rl();
                ishere[i] = 0;
                score++;
                c += 1;
            }
            if (ball.getPosition().intersects(obs[i].getPosition()) && (ishere[i] == 1))
            {
                ball.reboundObstacle_dt();
                ishere[i] = 0;
                score++;
                c += 1;
            }
            

        }
        
        // Has the ball hit the bat?
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            // Hit detected so reverse the ball and score a point
            ball.reboundBatOrTop();
        }
    
        
        std::stringstream ss;
        ss << "Score:" << score << "    Lives:" << lives;
        text.setString(ss.str());
        
        
        ball.update(score);
        bat.update();
        window.clear(Color(26, 150, 300,255));
        window.draw(bat.getShape());
        window.draw(text);
        window.draw(ball.getShape());
        
        for (int i = 0; i < n; ++i) // рисуем препятствия
        if (ishere[i] == 1) // ishere показывает, удалили мы obstacle или нет
        {
            window.draw(obs[i].getShape());
        }
    
        window.display();
    }
}
