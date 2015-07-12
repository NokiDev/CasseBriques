#include "Collision.hpp"
#include <iostream>

/**INFOS : Dans un sf::FloatRect la valeur left est le x et top le y, les coordonée correspondent au coin supérieur gauche on a donc (left,top) = (x,y)**/

bool Collision::PointAABBCollision(sf::Vector2f pointPosition, sf::FloatRect AABB)///Collision type Point - AABB
{
    if(pointPosition.x >= AABB.left
       && pointPosition.x < AABB.left + AABB.width
       && pointPosition.y >= AABB.top
       && pointPosition.y < AABB.top + AABB.height)
        return true;
    else
        return false;

}

bool Collision::AABBAABBCollision(sf::FloatRect AABB, sf::FloatRect AABB2)///Collision type AABB - AABB
{
    if((AABB2.left >= AABB.left + AABB.width)      // trop à droite
	|| (AABB2.left + AABB2.width <= AABB.left) // trop à gauche
	|| (AABB2.top >= AABB.top + AABB.height) // trop en bas
	|| (AABB2.top + AABB2.height <= AABB.top))  // trop en haut
          return false;
   else
          return true;
}

bool Collision::PointCircleCollision(sf::Vector2f pointPosition, sf::Vector2f circleCenter, int radius)///Collision type Point - Cercle
{
    int d2 = (pointPosition.x - circleCenter.x)*(pointPosition.x - circleCenter.x) + (pointPosition.y - circleCenter.y) * (pointPosition.y - circleCenter.y);
    if(d2 > radius*radius)
        return false;
    else
        return true;
}

bool Collision::CircleCircleCollision(sf::Vector2f circleCenter, int radius, sf::Vector2f circleCenter2, int radius2)///Collision type Cercle - Cercle
{
    int d2 = (circleCenter.x - circleCenter2.x)*(circleCenter.x - circleCenter2.x) + (circleCenter.y - circleCenter2.y) * (circleCenter.y - circleCenter2.y);
    if(d2 > (radius + radius2)*(radius + radius2))
        return false;
    else
        return true;
}

bool Collision::CircleDroiteCollision(sf::Vector2f aPoint, sf::Vector2f bPoint, sf::Vector2f circleCenter, int radius)
{
    sf::Vector2f u;
    u.x = bPoint.x - aPoint.x;
    u.y = bPoint.y - aPoint.y;
    sf::Vector2f AC;
    AC.x = circleCenter.x - aPoint.x;
    AC.y = circleCenter.y - aPoint.y;
    float numerateur = u.x*AC.y - u.y * AC.x;
    if(numerateur < 0)
        numerateur = -numerateur;
    float denominateur = sqrt(u.x*u.x + u.y* u.y);
    float CI = numerateur/denominateur;
    if(CI<radius)
        return true;
    else
        return false;
}

bool Collision::CircleSegmentCollision(sf::Vector2f circleCenter, int radius, sf::Vector2f pointA, sf::Vector2f pointB)///Collision type Cercle - Segement
{
    std::cout<<"\nTest 1";
    if(!CircleDroiteCollision(pointA, pointB, circleCenter, radius))
        return false;
    std::cout<<" - Completed\nTest 2";
    sf::Vector2f AB(pointB.x - pointA.x, pointB.y - pointA.y);
    sf::Vector2f AC(circleCenter.x - pointA.x, circleCenter.y - pointA.y);
    sf::Vector2f BC(circleCenter.x - pointB.x, circleCenter.y - pointB.y);
    float pascal1 = AB.x * AC.x + AB.y * AC.y;
    float pascal2 = (-AB.x)*BC.x + (-AB.y)*BC.y;
    std::cout<<" - Completed\nTest 3";
    if(pascal1 >= 0 && pascal2 >=0)
        return true;
    std::cout<<" - Completed\nTest 4";
    if(PointCircleCollision(pointA, circleCenter, radius))
        return true;
    std::cout<<" - Completed\nTest 5";
    if(PointCircleCollision(pointB, circleCenter, radius))
        return true;
    std::cout<<" - Completed";
    return false;
}

bool Collision::CircleAABBCollision(sf::Vector2f circleCenter, int radius, sf::FloatRect AABB)///Collision type Cercle - AABB
{
    sf::FloatRect boxCercle = Collision::getCircleBoundingBox(circleCenter, radius);  // retourner la bounding box de l'image porteuse, ou calculer la bounding box.

    if (AABBAABBCollision(AABB,boxCercle)==0)
        return false; // premier test

    if (Collision::PointCircleCollision(sf::Vector2f(AABB.left, AABB.top),circleCenter, radius)
    || Collision::PointCircleCollision(sf::Vector2f(AABB.left,AABB.top+AABB.height),circleCenter, radius)
    || Collision::PointCircleCollision(sf::Vector2f(AABB.left+AABB.width,AABB.top),circleCenter, radius)
    || Collision::PointCircleCollision(sf::Vector2f(AABB.left+AABB.width,AABB.top+AABB.height),circleCenter, radius))
        return true;   // deuxieme test

    if (Collision::PointAABBCollision(circleCenter,AABB))
        return true;   // troisieme test

    if (Collision::ProjectionOnSegment(circleCenter,sf::Vector2f(AABB.left,AABB.top),sf::Vector2f(AABB.left,AABB.top+AABB.height))
    || Collision::ProjectionOnSegment(circleCenter,sf::Vector2f(AABB.left,AABB.top),sf::Vector2f(AABB.left+AABB.width,AABB.top)))
        return true;   // cas E
    return false;  // cas B*/
}

bool Collision::AABBWindowBoundsCollision(sf::FloatRect winRect, sf::FloatRect AABB)
{
    if((AABB.left < winRect.left)      // trop à droite
	|| (AABB.left + AABB.width > winRect.left + winRect.width) // trop à gauche
	|| (AABB.top < winRect.top) // trop en bas
	|| (AABB.top + AABB.height > winRect.top + winRect.height))
        return true;
    else
        return false;
}


sf::Vector2f Collision::ProjectionI(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C)
{
    sf::Vector2f u(B.x - A.x, B.y - A.y);
    sf::Vector2f AC(C.x - A.x, C.y - A.y);
    float ti = (u.x*AC.x + u.y*AC.y)/(u.x*u.x + u.y*u.y);
    sf::Vector2f I(A.x + ti*u.x, A.y + ti*u.y);
    return I;
}

sf::Vector2f Collision::GetNormale(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C)
{
    sf::Vector2f u(B.x - A.x, B.y - A.y);
    std::cout<<"u <"<<u.x<<","<<u.y<<">"<<std::endl;
    sf::Vector2f     AC(C.x - A.x, C.y - A.y);
    std::cout<<"AC <"<<AC.x<<","<<AC.y<<">"<<std::endl;
    float parenthesis = u.x*AC.y - u.y*AC.x;
    std::cout<<"Parenthese "<<parenthesis<<std::endl;
    sf::Vector2f N(u.y*(parenthesis), u.x*(parenthesis));
    std::cout<<"Normal <"<<N.x<<","<<N.y<<">"<<std::endl;
    float norme = std::sqrt(N.x*N.x + N.y*N.y);
    std::cout<<"Norme "<<norme<<std::endl;
    N.x /= norme;
    N.y /= norme;


    return N;
}

sf::Vector2f Collision::CalculVectorV2(sf::Vector2f v, sf::Vector2f N)
{

    float pscal = (v.x*N.x + v.y*N.y);
    std::cout<<"Normal <"<<N.x<<","<<N.y<<">"<<std::endl;
    std::cout<<"Vector V2 Value <"<<v.x - 2*pscal * N.x<<","<<v.y -2*pscal*N.y<<">"<<std::endl;
    sf::Vector2f v2(v.x - 2*pscal * N.x, v.y -2*pscal*N.y);
    return v2;
}

bool Collision::ProjectionOnSegment(sf::Vector2f circleCenter, sf::Vector2f point1, sf::Vector2f point2 )
{
    int ACx = circleCenter.x - point1.x;
    int ACy = circleCenter.y - point1.y;
    int ABx = point2.x - point1.x;
    int ABy = point2.y - point1.y;
    int BCx = circleCenter.x - point2.x;
    int BCy = circleCenter.y - point2.y;

    int s1 = (ACx * ABx) + (ACy * ABy);
    int s2 = (BCx * ABx) + (BCy * ABy);
    if(s1*s2 >0)
        return false;
    return true;
}

sf::FloatRect Collision::getCircleBoundingBox(sf::Vector2f circleCenter, int radius)
{
    sf::FloatRect circleBB(circleCenter.x - radius, circleCenter.y - radius, radius*2, radius*2);

    return circleBB;
}
