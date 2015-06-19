#include "GuiMainMenu.hpp"

#include "WindowSystem/Buttons/GuiButtonMenu.hpp"
#include "WindowSystem/WindowManager.hpp"
#include "Application.hpp"

GuiMainMenu::GuiMainMenu()
{
    m_width = WindowManager::WINDOW_MANAGER->getWidth();
    m_height = WindowManager::WINDOW_MANAGER->getHeight();
    initGui();
}

GuiMainMenu::~GuiMainMenu()
{

}

void GuiMainMenu::initGui()
{
    buttonList.push_back(new GuiButtonMenu(0,m_width/2 - 50, m_height/2 - 100, 100, 50, "Jouer"));
    buttonList.push_back(new GuiButtonMenu(1,m_width/2 - 50, m_height/2 - 100 + 60, 100, 50, "Options", B_DISABLED));
    buttonList.push_back(new GuiButtonMenu(2,m_width/2 - 50, m_height/2 - 100 + 120, 100, 50, "Quitter"));
    GuiScreen::initGui();
}

void GuiMainMenu::update()
{

}

void GuiMainMenu::draw()
{
    GuiScreen::draw();
}

void GuiMainMenu::actionPerformed(GuiButton& guiButton)
{
    switch (guiButton.getId())
    {
        case 0 :
            Application::APP->start();
            break;
        case 2 :
            Application::APP->stop();
            break;
    }
}

