#include "Racket.hpp"
#include "WindowSystem/WindowManager.hpp"
#include "Application.hpp"

Racket::Racket()
{
    m_speed = 400;
    m_move = false;
    //m_sprite;
    //m_texture;


    m_rectShape.setSize(sf::Vector2f(75,15));
    m_color = sf::Color(255,255,255);
    m_size = sf::Vector2u(75, 15);
    m_velocity = sf::Vector2f(0.0f, 0.0f);
    m_position = sf::Vector2f(WindowManager::WINDOW_MANAGER->getWidth()/2 - m_size.x/2, WindowManager::WINDOW_MANAGER->getHeight() - 300);
    m_rectShape.setPosition(m_position);
    m_entityType = RACKET;
}

Racket::~Racket()
{

}

void Racket::update()
{
    m_velocity = sf::Vector2f(0.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_velocity.x =  - m_speed*Application::DELTA_TIME;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_velocity.x = m_speed*Application::DELTA_TIME;
    }
    m_rectShape.move(m_velocity);
}

void Racket::draw()
{
    WindowManager::WINDOW_MANAGER->draw(m_rectShape);
}
