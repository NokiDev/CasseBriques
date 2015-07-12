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

        void setCenter(sf::Vector2f);
        void setLaunch(bool flag);
        void setRadius(float radius);

        sf::Vector2f getCenter();
        bool getLaunch();
        float getRadius();

    private :
        bool m_launch;
        sf::CircleShape m_crclShape;
        sf::Vector2f m_center;
        float m_radius;
};

#endif // BALL_HPP_INCLUDED
