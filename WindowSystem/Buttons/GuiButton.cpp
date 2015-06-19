#include "GuiButton.hpp"

GuiButton::~GuiButton(){}///Virtual

void GuiButton::draw(){}

unsigned int GuiButton::getId()const
{
    return m_id;
}

std::string GuiButton::getDisplayString()const
{
    return m_displayString;
}

unsigned int GuiButton::getHeight()const
{
    return m_height;
}

unsigned int GuiButton::getWidth()const
{
    return m_width;
}

sf::Vector2i GuiButton::getPosition()const
{
    return m_position;
}

ButtonState GuiButton::getState()const
{
    return m_buttonState;
}

void GuiButton::setDisplayString(std::string str)
{
    m_displayString = str;
}

void GuiButton::setWidth(unsigned int width)
{
    if(width == 0)
        return;
    m_width = width;
}

void GuiButton::setHeight(unsigned int height)
{
    if(height == 0)
        return;
    m_height = height;
}

void GuiButton::setPosition(sf::Vector2i position)
{
    m_position = position;
}

void GuiButton::setState(ButtonState state)
{
    m_buttonState = state;
}
