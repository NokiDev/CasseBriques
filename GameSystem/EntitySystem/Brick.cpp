#include "Brick.hpp"

Brick::Brick(int posX, int posY, unsigned int health)
{
    m_speed = 0.0f;
    m_move = false;
    //m_sprite;
    //m_texture;
    m_color = sf::Color(255,0,0);
    m_size = sf::Vector2u(BRICK_WIDTH, BRICK_HEIGHT);
    m_velocity = sf::Vector2f(0.0f, 0.0f);
    m_position = sf::Vector2f(posX*BRICK_WIDTH, posY*BRICK_HEIGHT);
    m_entityType = BRICK;
}

Brick::~Brick()
{

}

void Brick::update()
{

}
void Brick::draw()
{

}

void Brick::takeDamage(int damage)
{

}

void Brick::setHealth(unsigned int health)
{

}

unsigned int Brick::getHealth()
{

}
