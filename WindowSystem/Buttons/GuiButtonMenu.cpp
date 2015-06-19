#include "GuiButtonMenu.hpp"


GuiButtonMenu::GuiButtonMenu(int x, int y, unsigned int width, unsigned int height, std::string displayString, ButtonState state)
{
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

}
