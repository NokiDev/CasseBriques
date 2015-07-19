#include "Ball.hpp"
#include "WindowSystem/WindowManager.hpp"
#include "Application.hpp"
#include "Racket.hpp"
#include "Brick.hpp"

Ball::Ball()
{
    m_speed = sf::Vector2f(0.0f,0.0f);
    m_move = false;
    m_launch = false;
    //m_sprite;
    //m_texture;
    m_size = sf::Vector2u(16,16);
    m_radius = 8;
    m_color = sf::Color(255,255,255);
    m_velocity = sf::Vector2f(0.0f, 0.0f);
    m_position = sf::Vector2f(WindowManager::WINDOW_MANAGER->getWidth()/2 - m_size.x/2, WindowManager::WINDOW_MANAGER->getHeight() - 116);
    m_center = sf::Vector2f(m_position.x + m_radius, m_position.y + m_radius);
    m_crclShape.setPosition(m_position);
    m_crclShape.setRadius(m_radius);
    m_crclShape.setOutlineColor(sf::Color(0,0,0));
    m_crclShape.setOutlineThickness(2.f);
    m_entityType = BALL;
}

Ball::~Ball()
{

}

void Ball::update()
{
    if(m_launch)
    {
        m_velocity.x = m_speed.x * Application::DELTA_TIME;
        m_velocity.y = m_speed.y * Application::DELTA_TIME;
    }
    else
        m_velocity = sf::Vector2f(0.f,0.f);
}


void Ball::updatePosition()
{
    m_speed.x = m_velocity.x/Application::DELTA_TIME;
    m_speed.y = m_velocity.y/Application::DELTA_TIME;
    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;
    m_center.x += m_velocity.x;
    m_center.y += m_velocity.y;
    m_crclShape.setPosition(m_position);
}

void Ball::draw()
{
    WindowManager::WINDOW_MANAGER->draw(m_crclShape);
}

void Ball::checkCollisions(World & world)
{
    sf::FloatRect winRect(0,0,WindowManager::WINDOW_MANAGER->getWidth(),WindowManager::WINDOW_MANAGER->getHeight() - 90);
    sf::Vector2f nextPos(m_center.x + m_velocity.x, m_center.y + m_velocity.y);
    sf::FloatRect circleRect = Collision::getCircleBoundingBox(nextPos,m_radius);
    sf::FloatRect racketRect(world.getTheRacket()->getPosition().x, world.getTheRacket()->getPosition().y , world.getTheRacket()->getSize().x, world.getTheRacket()->getSize().y);
    if(Collision::AABBWindowBoundsCollision(winRect, circleRect))
    {
        if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(winRect.left, winRect.top), sf::Vector2f(winRect.left, winRect.height))
        ||Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(winRect.width, winRect.top), sf::Vector2f(winRect.width, winRect.height)))
        {
            m_speed.x = -m_speed.x;
            m_velocity.x = -m_velocity.x;
        }
        else if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(winRect.left, winRect.top), sf::Vector2f(winRect.width, winRect.top)))
        {
            m_speed.y = -m_speed.y;
            m_velocity.y = -m_velocity.y;
        }
        if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(winRect.left, winRect.height), sf::Vector2f(winRect.width, winRect.height)))
        {
            m_speed.y = -m_speed.y;
            m_velocity.y = -m_velocity.y;
        }
        m_speed.x++;
    }
    else if(Collision::CircleAABBCollision(nextPos, m_radius, racketRect))
    {
        sf::Vector2f dist = Collision::calculateDistance(circleRect, racketRect);
        if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(racketRect.left, racketRect.top), sf::Vector2f(racketRect.left, racketRect.top + racketRect.height)))
        {
            m_speed.x = -m_speed.x;
            m_velocity.x = -m_velocity.x;
        }
        if (Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(racketRect.left + racketRect.width, racketRect.top), sf::Vector2f(racketRect.left + racketRect.width, racketRect.top + racketRect.height)))
        {
            m_speed.x = -m_speed.x;
            m_velocity.x = -m_velocity.x;
        }
        if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(racketRect.left, racketRect.top), sf::Vector2f(racketRect.left + racketRect.width, racketRect.top)))
        {
            if(world.getTheRacket()->getVelocity().x != 0)
            {
                float rap,n1, n2;
                n1 = std::sqrt(m_velocity.x*m_velocity.x + m_velocity.y* m_velocity.y);
                if((world.getTheRacket()->getVelocity().x >0 && m_velocity.x < 0)
                ||(world.getTheRacket()->getVelocity().x < 0 && m_velocity.x >0))
                {
                    m_velocity.x += world.getTheRacket()->getVelocity().x* 0.2;
                }
                else
                {
                    m_velocity.x += world.getTheRacket()->getVelocity().x*0.2;
                }
                n2 = std::sqrt(m_velocity.x*m_velocity.x + m_velocity.y* m_velocity.y);
                rap = n1/n2;
                m_velocity.x*=rap;
                m_velocity.y*=rap;
                m_speed.x *=rap;
                m_speed.y *=rap;
            }
            m_speed.y = -m_speed.y;
            m_velocity.y = -m_velocity.y;
        }
        if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(racketRect.left, racketRect.top + racketRect.height), sf::Vector2f(racketRect.left + racketRect.width, racketRect.top + racketRect.height)))
        {
            m_speed.y = -m_speed.y;
            m_velocity.y = -m_velocity.y;
        }
        m_speed.x ++;
    }
    else
    {
        for(unsigned int i =0; i< world.getMaxBricks(); i++)
        {
            Brick* brick = world.getABrick(i);
            sf::FloatRect brickRect(brick->getPosition().x, brick->getPosition().y, brick->getSize().x, brick->getSize().y);
            if(Collision::CircleAABBCollision(nextPos, m_radius, brickRect))
            {
                if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(brickRect.left, brickRect.top), sf::Vector2f(brickRect.left, brickRect.top + brickRect.height)))
                {
                    m_speed.x = -m_speed.x;
                    m_velocity.x = -m_velocity.x;
                }
                if (Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(brickRect.left + brickRect.width, brickRect.top), sf::Vector2f(brickRect.left + brickRect.width, brickRect.top + brickRect.height)))
                {
                    m_speed.x = -m_speed.x;
                    m_velocity.x = -m_velocity.x;
                }
                if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(brickRect.left, brickRect.top), sf::Vector2f(brickRect.left + brickRect.width, brickRect.top)))
                {
                    m_speed.y = -m_speed.y;
                    m_velocity.y = -m_velocity.y;
                }
                if(Collision::CircleSegmentCollision(nextPos, m_radius, sf::Vector2f(brickRect.left, brickRect.top + brickRect.height), sf::Vector2f(brickRect.left + brickRect.width, brickRect.top + brickRect.height)))
                {
                    m_speed.y = -m_speed.y;
                    m_velocity.y = -m_velocity.y;
                }

                brick->takeDamage(1);
                m_speed.x ++;
            }
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
