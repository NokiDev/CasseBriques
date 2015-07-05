#include "GuiIngame.hpp"
#include "GameSystem/MapSystem/World.hpp"

GuiIngame::GuiIngame(World* world)
{
    theWorld = world;
}

GuiIngame::~GuiIngame()
{

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
    theWorld->draw();
}

bool GuiIngame::doesGuiPauseGame()
{
    return false;
}
