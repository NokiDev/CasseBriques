#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "GameSystem/MapSystem/CollisionsSystem/Collision.hpp"
#include "GameSystem/MapSystem/World.hpp"

enum EntityType{UKNOWN, RACKET, BALL, BRICK, DROP};

class Entity
{
    public :
        virtual ~Entity();

        virtual void update();
        virtual void updatePosition();
        virtual void draw();
        virtual void onCollision(Entity& entity);

        virtual void checkCollisions(World& world);


        void setWidth(unsigned int width);
        void setHeight(unsigned int height);
        void setSize(sf::Vector2u size);
        void setX(float x);
        void setY(float y);
        void setPosition(sf::Vector2f position);
        void setSpeed(sf::Vector2f speed);

        unsigned int getWidth();
        unsigned int getHeight();
        sf::Vector2u getSize();
        float getX();
        float getY();
        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();
        sf::Vector2f getSpeed();
        bool getIsMoving();
        EntityType getType();

    protected :

        sf::Vector2f m_speed;
        bool m_move;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        sf::Color m_color;
        sf::Vector2f m_position;
        sf::Vector2u m_size;
        sf::Vector2f m_velocity;
        EntityType m_entityType;
};

#endif // ENTITY_HPP_INCLUDED
