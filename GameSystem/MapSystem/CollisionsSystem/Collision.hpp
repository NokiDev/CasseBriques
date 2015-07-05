#ifndef COLLISION_HPP_INCLUDED
#define COLLISION_HPP_INCLUDED

class Collision
{
    public :
        static bool Collision(sf::Vector2f pointPosition, sf::Rect AABB);///Collision type Point - AABB
        static bool Collision(sf::Rect AABB, sf::Rect AABB2);///Collision type AABB - AABB

        static bool Collision(sf::Vector2f pointPosition, sf::Vector2f circleCenter, int radius);///Collision type Point - Cercle
        static bool Collision(sf::Vector2f circleCenter, int radius, sf::Vector2f circleCenter2, int radius2);///Collision type Cercle - Cercle

        static bool Collision(sf::Vector2f circleCenter, int radius, sf::Vector2f point1, sf::Vector2f point2)///Collision type Cercle - Segement
        static bool Collision(sf::Vector2f circleCenter, int radius, sf::Rect AABB);///Collision type Cercle - AABB



};

#endif // COLLISION_HPP_INCLUDED
