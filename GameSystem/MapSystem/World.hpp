#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <string>
#include <vector>

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
        void loadFromFile(std::string levelFile);
        void update();
        void draw();

        Racket* getTheRacket();
        Ball* getABall(int id);
        Brick* getABrick(int id);

    private :

        Racket* theRacket;
        std::vector<Brick*> m_bricks;
        std::vector<Ball*> m_balls;


};

#endif // WORLD_HPP_INCLUDED
