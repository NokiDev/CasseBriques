#include "Ball.hpp"
#include "WindowSystem/WindowManager.hpp"


Ball::Ball()
{
    m_speed = 250;
    m_move = false;
    //m_sprite;
    //m_texture;
    m_radius = 8;
    m_color = sf::Color(255,255,255);
    m_velocity = sf::Vector2f(0.0f, 0.0f);
    m_position = sf::Vector2f(WindowManager::WINDOW_MANAGER->getWidth()/2 - m_size.x/2, WindowManager::WINDOW_MANAGER->getHeight() - 300);
    m_crclShape.setPosition(m_position);
    m_crclShape.setRadius(m_radius);
    m_entityType = BALL;
}

Ball::~Ball()
{

}

void Ball::draw()
{
    WindowManager::WINDOW_MANAGER->draw(m_crclShape);
}

void Ball::update()
{

}
