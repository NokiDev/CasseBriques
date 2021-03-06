#include "Entity.hpp"


Entity::~Entity(){}

void Entity::update(){}

void Entity::updatePosition(){}

void Entity::draw(){}

void Entity::onCollision(Entity& entity){}

void Entity::checkCollisions(World & world){}

void Entity::setWidth(unsigned int width)
{
    m_size.x = width;
}
void Entity::setHeight(unsigned int height)
{
    m_size.y = height;
}
void Entity::setSize(sf::Vector2u size)
{
    m_size = size;
}
void Entity::setX(float x)
{
    m_position.x = x;
}
void Entity::setY(float y)
{
    m_position.y = y;
}
void Entity::setPosition(sf::Vector2f position)
{
    m_position = position;
}
void Entity::setSpeed(sf::Vector2f speed)
{
    m_speed = speed;
}

unsigned int Entity::getWidth()
{
    return m_size.x;
}
unsigned int Entity::getHeight()
{
    return m_size.y;
}
sf::Vector2u Entity::getSize()
{
    return m_size;
}
float Entity::getX()
{
    return m_position.x;
}
float Entity::getY()
{
    return m_position.y;
}
sf::Vector2f Entity::getPosition()
{
    return m_position;
}
sf::Vector2f Entity::getVelocity()
{
    return m_velocity;
}
sf::Vector2f Entity::getSpeed()
{
    return m_speed;
}
EntityType Entity::getType()
{
    return m_entityType;
}
