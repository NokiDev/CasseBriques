#include "GuiButtonMenu.hpp"
#include "WindowSystem/FontRenderingSystem/FontRenderer.hpp"

GuiButtonMenu::GuiButtonMenu(unsigned int id, int x, int y, unsigned int width, unsigned int height, std::string displayString, ButtonState state)
{
    m_id = id;
    m_buttonState = state;
    m_width = width;
    m_height = height;
    m_position = sf::Vector2i(x,y);
    m_displayString = displayString;

}

GuiButtonMenu::~GuiButtonMenu()
{

}

void GuiButtonMenu::draw()
{
    sf::Color color(0,0,0);
    if(m_buttonState == B_FOCUS)
        color = sf::Color(255,255,255);
    else if(m_buttonState == B_DISABLED)
        color = sf::Color(127,127,127);

    std::cout<<"Position <"<< m_position.x<<","<<m_position.y<<">"<<std::endl;

    FontRenderer::printCenteredString(m_displayString, m_position.x, m_position.y, m_width, m_height, color, 28);
}
