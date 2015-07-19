#include "GuiIngame.hpp"
#include "GameSystem/MapSystem/World.hpp"
#include "WindowSystem/WindowManager.hpp"
#include "WindowSystem/FontRenderingSystem/FontRenderer.hpp"
#include "GameSystem/EntitySystem/Ball.hpp"

GuiIngame::GuiIngame(World* world)
{
    theWorld = world;
    m_backgroundTexture.loadFromFile("Ressources/Gui/blue-galaxy.jpg");
    m_background.setTexture(m_backgroundTexture);
}

GuiIngame::~GuiIngame()
{

}

void GuiIngame::handleInput(sf::Event & event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        sf::Vector2f speed(0.f,0.f);
        switch(event.key.code)
        {
            case sf::Keyboard::Right:
                speed = sf::Vector2f(300.f, 300.f);
            break;
            case sf::Keyboard::Left:
                speed = sf::Vector2f(-300.f, 300.f);
            break;
            case sf::Keyboard::Return:
                speed = sf::Vector2f(0.f, 600.f);
            break;
            default:
                break;
        }
        if(!theWorld->getABall(0)->getLaunch() && (speed.x != 0.f || speed.y != 0.f))
            theWorld->launchBall(speed);

    }
}

void GuiIngame::initGui()
{

}

void GuiIngame::update()
{
    theWorld->update();
}

void GuiIngame::draw()
{
    GuiScreen::draw();
    sf::RectangleShape rectShape;
    rectShape.setFillColor(sf::Color(255,0,0));
    rectShape.setSize(sf::Vector2f(WindowManager::WINDOW_MANAGER->getWidth(), 5));
    rectShape.setPosition(sf::Vector2f(0.f, WindowManager::WINDOW_MANAGER->getHeight()-90));
    WindowManager::WINDOW_MANAGER->draw(rectShape);
    int y =  WindowManager::WINDOW_MANAGER->getHeight()-90;
    FontRenderer::FONT_RENDERER.printCenteredString("Lost Zone",0, y , WindowManager::WINDOW_MANAGER->getWidth() ,WindowManager::WINDOW_MANAGER->getHeight()- y , sf::Color(230, 10,20), 30);
    theWorld->draw();
}

bool GuiIngame::doesGuiPauseGame()
{
    return false;
}
