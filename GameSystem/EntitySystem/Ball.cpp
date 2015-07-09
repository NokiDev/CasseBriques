#include "Ball.hpp"
#include "WindowSystem/WindowManager.hpp"
#include "Application.hpp"
#include "Racket.hpp"

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
    m_center = sf::Vector2f(m_position.x + m_radius, m_position.y + m_radius);
    m_crclShape.setPosition(m_position);
    m_crclShape.setRadius(m_radius);
    m_entityType = BALL;
}

Ball::~Ball()
{

}

void Ball::update()
{
    int xCoeff = 1;
    int yCoeff = 1;
    if(m_velocity.x <0)
        xCoeff = -1;
    if(m_velocity.y <0)
        yCoeff = -1;

    m_velocity.x = m_speed*Application::DELTA_TIME*xCoeff;
    m_velocity.y = m_speed*Application::DELTA_TIME*yCoeff;
}

void Ball::updatePosition()
{
    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;
    m_center.x += m_velocity.x;
    m_center.y += m_velocity.y;
    m_crclShape.move(m_velocity);
}

void Ball::draw()
{
    WindowManager::WINDOW_MANAGER->draw(m_crclShape);
}

void Ball::checkCollisions(World & world)
{
    sf::FloatRect winRect(0,0,WindowManager::WINDOW_MANAGER->getWidth(),WindowManager::WINDOW_MANAGER->getHeight());
    sf::Vector2f nextPos(m_center.x + m_velocity.x, m_center.y + m_velocity.y);
    sf::FloatRect circleRect = Collision::getCircleBoundingBox(nextPos,m_radius);
    sf::FloatRect racketRect(world.getTheRacket()->getPosition().x, world.getTheRacket()->getPosition().y , world.getTheRacket()->getSize().x, world.getTheRacket()->getSize().y);
    if(Collision::AABBWindowBoundsCollision(winRect, circleRect))
    {
        if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.left, winRect.top), sf::Vector2f(winRect.width, winRect.top)))
        {
            m_velocity.y = -m_velocity.y;
        }
        else if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.left, winRect.top), sf::Vector2f(winRect.left, winRect.height)))
        {
            m_velocity.x = -m_velocity.x;
        }
        else if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.width, winRect.top), sf::Vector2f(winRect.width, winRect.height)))
        {
            m_velocity.x = -m_velocity.x;
        }
        else if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.left, winRect.height), sf::Vector2f(winRect.width, winRect.height)))
        {
            m_velocity.y = -m_velocity.y;
        }
    }
    else if(Collision::CircleAABBCollision(m_center, m_radius, racketRect))
    {
        m_velocity.y = -m_velocity.y;
    }
    updatePosition();
}
