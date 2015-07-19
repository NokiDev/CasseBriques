#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Racket;
class Ball;
class Brick;
class World
{
    public :
        World();
        ~World();

        void initWorld();
        void changeLevel();
        bool loadFromFile(std::string levelFile);
        void update();
        void draw();

        void launchBall(sf::Vector2f speed);

        unsigned int getMaxBricks();

        void destroyBrick(Brick* brick);

        Racket* getTheRacket();
        Ball* getABall(int id);
        Brick* getABrick(int id);

    private :

        Racket* theRacket;

        unsigned int m_level;
        float m_speedModifier;

        unsigned int m_levelMaxBricks;
        std::vector<Brick*> m_bricks;
        std::vector<Ball*> m_balls;


};

#endif // WORLD_HPP_INCLUDED
