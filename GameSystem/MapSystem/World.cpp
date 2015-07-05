#include "World.hpp"

#include "GameSystem/EntitySystem/Racket.hpp"
#include "GameSystem/EntitySystem/Ball.hpp"
#include "GameSystem/EntitySystem/Brick.hpp"

World::World()
{
    theRacket = new Racket();
    Ball* ball = new Ball();
    m_balls.push_back(ball);
}

World::~World()
{

}

void World::changeLevel()
{

}

void World::loadFromFile(std::string levelFile)
{

}

void World::update()
{
    theRacket->update();
    for(unsigned int i = 0; i< m_balls.size(); i++)
    {
        m_balls[i]->update();
    }
    for(unsigned int i = 0; i< m_bricks.size(); i++)
    {
        m_bricks[i]->update();
    }
}

void World::draw()
{
    theRacket->draw();
    for(unsigned int i = 0; i< m_balls.size(); i++)
    {
        m_balls[i]->draw();
    }
    for(unsigned int i = 0; i< m_bricks.size(); i++)
    {
        m_bricks[i]->draw();
    }
}
