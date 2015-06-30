#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Entity
{
    public :
        virtual ~Entity();

        virtual void update();
        virtual void draw();

        void setWidth(unsigned int width);
        void setHeight(unsigned int height);
        void setSize(sf::Vector2u size);
        void setX(float x);
        void setY(float y);
        void setPosition(sf::Vector2f position);
        void setSpeed(float speed);

        unsigned int getWidth();
        unsigned int getHeight();
        sf::Vector2u getSize();
        float getX();
        float getY();
        sf::Vector2f getPosition();
        float getSpeed();

    protected :

        float m_speed;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        sf::Color m_color;
        sf::Vector2f m_position;
        sf::Vector2u m_size;
        sf::Vector2f m_velocity;
};

#endif // ENTITY_HPP_INCLUDED
