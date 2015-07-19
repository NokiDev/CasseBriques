#include "Brick.hpp"
#include "WindowSystem/WindowManager.hpp"

Brick::Brick(int posX, int posY, unsigned int health, sf::Color color)
{
    m_speed = sf::Vector2f(0.f,0.f);
    m_move = false;
    //m_sprite;
    //m_texture;
    m_health = health;
    m_color = color;
    m_size = sf::Vector2u(BRICK_WIDTH, BRICK_HEIGHT);
    m_velocity = sf::Vector2f(0.0f, 0.0f);
    m_position = sf::Vector2f(posX*BRICK_WIDTH, posY*BRICK_HEIGHT);
    m_entityType = BRICK;
}

Brick::~Brick()
{

}

void Brick::update(World & world)
{
    if(m_health == 0)
    {
        world.destroyBrick(this);
    }
}
void Brick::draw()
{
    sf::RectangleShape rectShape;
    rectShape.setPosition(m_position.x+3,m_position.y +3);
    rectShape.setSize(sf::Vector2f(BRICK_WIDTH -3, BRICK_HEIGHT- 3));
    rectShape.setFillColor(m_color);
    rectShape.setOutlineColor(sf::Color(0,0,0));
    rectShape.setOutlineThickness(3.f);
    WindowManager::WINDOW_MANAGER->draw(rectShape);
}

void Brick::takeDamage(int damage)
{
    int tempHealth = m_health- damage;
    if(tempHealth <0)
        tempHealth = 0;
    m_health = tempHealth;
}

void Brick::setHealth(unsigned int health)
{
    m_health = health;
}

unsigned int Brick::getHealth()
{
    return m_health;
}
