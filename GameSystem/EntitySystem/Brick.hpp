#ifndef BRICK_HPP_INCLUDED
#define BRICK_HPP_INCLUDED
#include "Entity.hpp"

const int BRICK_WIDTH = 75;
const int BRICK_HEIGHT = 40;

class Brick : public Entity
{
    public :
        Brick(int posX, int posY, unsigned int health);
        ~Brick();

        virtual void update();
        virtual void draw();

        void takeDamage(int damage);

        void setHealth(unsigned int health);
        unsigned int getHealth();

    private :

        unsigned int m_health;
};

#endif // BRICK_HPP_INCLUDED
