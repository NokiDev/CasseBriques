#ifndef RACKET_HPP_INCLUDED
#define RACKET_HPP_INCLUDED

#include "Entity.hpp"

class Racket : public Entity
{
    public :
        Racket();
        ~Racket();

        virtual void update();
        virtual void draw();

    private :
        sf::RectangleShape m_rectShape;
};

#endif // RACKET_HPP_INCLUDED
