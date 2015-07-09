#ifndef COLLISION_HPP_INCLUDED
#define COLLISION_HPP_INCLUDED

#include <SFML/Graphics.hpp>


class Collision
{
    public :
        static bool PointAABBCollision(sf::Vector2f pointPosition, sf::FloatRect AABB);///Collision type Point - AABB
        static bool AABBAABBCollision(sf::FloatRect AABB, sf::FloatRect AABB2);///Collision type AABB - AABB

        static bool PointCircleCollision(sf::Vector2f pointPosition, sf::Vector2f circleCenter, int radius);///Collision type Point - Cercle
        static bool CircleCircleCollision(sf::Vector2f circleCenter, int radius, sf::Vector2f circleCenter2, int radius2);///Collision type Cercle - Cercle

        static bool CircleSegmentCollision(sf::Vector2f circleCenter, int radius, sf::Vector2f point1, sf::Vector2f point2);///Collision type Cercle - Segement
        static bool CircleDroiteCollision(sf::Vector2f aPoint, sf::Vector2f bPoint, sf::Vector2f circleCenter, int radius);
        static bool CircleAABBCollision(sf::Vector2f circleCenter, int radius, sf::FloatRect AABB);///Collision type Cercle - AABB

        static bool AABBWindowBoundsCollision(sf::FloatRect winRect, sf::FloatRect AABB);

        static sf::Vector2f ProjectionI(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C);
        static sf::Vector2f GetNormale(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C);
        static sf::Vector2f CalculVectorV2(sf::Vector2f v, sf::Vector2f N);
        static bool ProjectionOnSegment(sf::Vector2f circleCenter, sf::Vector2f point1, sf::Vector2f point2);
        static sf::FloatRect getCircleBoundingBox(sf::Vector2f circleCenter, int radius);
};

#endif // COLLISION_HPP_INCLUDED
