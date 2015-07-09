#ifndef BALL_HPP_INCLUDED
#define BALL_HPP_INCLUDED
#include "Entity.hpp"

class Ball : public Entity
{

    public :
        Ball();
        ~Ball();

        virtual void update();
        virtual void updatePosition();
        virtual void checkCollisions(World& world);
        virtual void draw();


    private :
        sf::CircleShape m_crclShape;
        sf::Vector2f m_center;
        float m_radius;
};

#endif // BALL_HPP_INCLUDED
