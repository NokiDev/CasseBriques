#include "Ball.hpp"
#include "WindowSystem/WindowManager.hpp"
#include "Application.hpp"
#include "Racket.hpp"

Ball::Ball()
{
    m_speed = 250;
    m_move = false;
    m_launch = false;
    //m_sprite;
    //m_texture;
    m_radius = 8;
    m_color = sf::Color(255,255,255);
    m_velocity = sf::Vector2f(0.0f, 0.0f);
    m_position = sf::Vector2f(WindowManager::WINDOW_MANAGER->getWidth()/2 - m_size.x/2, WindowManager::WINDOW_MANAGER->getHeight() - 116);
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
    if(!m_launch)
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
    else
        m_velocity = sf::Vector2f(0.f,0.f);
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
    sf::RectangleShape boxShape;
    boxShape.setPosition(m_position);
    boxShape.setSize(sf::Vector2f(16,16));
    boxShape.setFillColor(sf::Color(255,0,0));
    WindowManager::WINDOW_MANAGER->draw(boxShape);
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
        if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.left, winRect.top), sf::Vector2f(winRect.left, winRect.height))
        ||Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.width, winRect.top), sf::Vector2f(winRect.width, winRect.height)))
        {
            m_velocity.x = -m_velocity.x;
        }
        else if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.left, winRect.top), sf::Vector2f(winRect.width, winRect.top)))
        {
             m_velocity.y = -m_velocity.y;
        }
        else if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(winRect.left, winRect.height), sf::Vector2f(winRect.width, winRect.height)))
        {
             m_velocity.y = -m_velocity.y;
        }
    }
    else if(Collision::CircleAABBCollision(m_center, m_radius, racketRect))
    {
        if(Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(racketRect.left, racketRect.top), sf::Vector2f(racketRect.left, racketRect.height))
        || Collision::CircleSegmentCollision(m_center, m_radius, sf::Vector2f(racketRect.width, racketRect.top), sf::Vector2f(racketRect.width, racketRect.height)))
        {
            m_velocity.x = - m_velocity.x;
        }
        else
        {
            m_velocity.y = -m_velocity.y;
        }
    }
    updatePosition();
}

void Ball::setCenter(sf::Vector2f center)
{
    m_position.x = m_center.x - center.x;
    m_position.y = m_center.y + center.y;
    m_center = center;
}

void Ball::setLaunch(bool flag)
{
    m_launch = flag;
}

void Ball::setRadius(float radius)
{
    m_radius = radius;
}

sf::Vector2f Ball::getCenter()
{
    return m_center;
}

bool Ball::getLaunch()
{
    return m_launch;
}

float Ball::getRadius()
{
    return m_radius;
}
