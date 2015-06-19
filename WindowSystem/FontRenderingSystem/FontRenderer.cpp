#include "FontRenderer.hpp"
#include "WindowSystem/WindowManager.hpp"

sf::Font FontRenderer::m_font;

void FontRenderer::initFont()
{
    if(!FontRenderer::m_font.loadFromFile("Ressources/Fonts/PixelFont.ttf"))
    {
        exit(0);
    }
}

void FontRenderer::printString(std::string str, int x, int y, sf::Color color, int charSize)
{
    sf::Text text;
    text.setFont(FontRenderer::m_font);
    text.setString(str);
    text.setColor(color);
    text.setCharacterSize(charSize);
    text.setPosition(x,y);

    WindowManager::WINDOW_MANAGER->draw(text);
}

void FontRenderer::printCenteredString(std::string str, int x, int y, int rectWidth,int rectHeight, sf::Color color, int charSize)
{
    sf::Text text;
    text.setFont(FontRenderer::m_font);
    text.setString(str);
    text.setColor(color);
    text.setCharacterSize(charSize);
    text.setPosition(x + rectWidth/2 - text.getLocalBounds().width/2, y + rectHeight/2 );
    WindowManager::WINDOW_MANAGER->draw(text);
}
