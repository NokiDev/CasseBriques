#ifndef BRICK_HPP_INCLUDED
#define BRICK_HPP_INCLUDED

class Brick
{
    public :
        Brick();
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
