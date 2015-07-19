#include "World.hpp"
#include <iostream>

#include "GameSystem/EntitySystem/Racket.hpp"
#include "GameSystem/EntitySystem/Ball.hpp"
#include "GameSystem/EntitySystem/Brick.hpp"

#include "tinyXml/tinyXml.h"

#include "WindowSystem/WindowManager.hpp"

World::World()
{
    m_level =0;
    m_speedModifier = 1.f;
    theRacket = new Racket();
    Ball* ball = new Ball();
    m_balls.push_back(ball);
    m_levelMaxBricks = 0;
}

World::~World()
{

}

void World::changeLevel()
{

}

void World::launchBall(sf::Vector2f speed)
{
    m_balls[0]->setSpeed(sf::Vector2f(speed.x*m_speedModifier, speed.y * m_speedModifier));
    m_balls[0]->setLaunch(true);
}

bool World::loadFromFile(std::string file_name)
{
    std::string filePath = "Ressources/map/"+file_name;
    TiXmlDocument levelFile(filePath.c_str());

    if (!levelFile.LoadFile())///load the xml file
    {
        return false;
    }
    TiXmlElement *map;
    map = levelFile.FirstChildElement("map");

    TiXmlElement *brickElement;
    brickElement = map->FirstChildElement("brick");

    while(brickElement)
    {
        int posX = 0;
        int posY = 0;
        int health = 0;
        int r=0;int v =0;int b = 0;
        brickElement->QueryIntAttribute("posX", &posX);
        brickElement->QueryIntAttribute("posY", &posY);
        brickElement->QueryIntAttribute("health", &health);
        brickElement->QueryIntAttribute("r", &r);
        brickElement->QueryIntAttribute("v", &v);
        brickElement->QueryIntAttribute("b", &b);

        m_bricks.push_back(new Brick(posX, posY, health, sf::Color(r,v,b)));
        m_levelMaxBricks++;

        brickElement = brickElement->NextSiblingElement("brick");
    }
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
        m_bricks[i]->update(*this);
    }
    theRacket->checkCollisions(*this);
    for(unsigned int i = 0; i< m_balls.size(); i++)
    {
        m_balls[i]->checkCollisions(*this);
    }
    for(unsigned int i = 0; i< m_bricks.size(); i++)
    {
        m_bricks[i]->checkCollisions(*this);
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

Racket* World::getTheRacket()
{
    return theRacket;
}

Ball* World::getABall(int id)
{
    return m_balls[id];
}

Brick* World::getABrick(int id)
{
    return m_bricks[id];
}

unsigned int World::getMaxBricks()
{
    return m_levelMaxBricks;
}

void World::destroyBrick(Brick* brick)
{
    for(std::vector<Brick*>::iterator it = m_bricks.begin(); it< m_bricks.end(); it++)
    {
        if(*it == brick)
        {
            m_bricks.erase(it);
            m_levelMaxBricks--;
            break;
        }
    }
}
