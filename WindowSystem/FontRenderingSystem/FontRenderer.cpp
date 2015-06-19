#include "FontRenderer.hpp"
#include "WindowSystem/WindowManager.hpp"

FontRenderer FontRenderer::FONT_RENDERER;

FontRenderer::FontRenderer()
{
    if(!m_font.loadFromFile("Ressources/Fonts/PixelFont.ttf"))
    {
        exit(0);
    }
}

FontRenderer::~FontRenderer()
{

}

void FontRenderer::printString(std::string str, int x, int y, sf::Color color, int charSize)
{
    sf::Text text;
    text.setFont(m_font);
    text.setString(str);
    text.setColor(color);
    text.setCharacterSize(charSize);
    text.setPosition(x,y);
    WindowManager::WINDOW_MANAGER->draw(text);
}

void FontRenderer::printCenteredString(std::string str, int x, int y, int rectWidth,int rectHeight, sf::Color color, int charSize)
{
    sf::Text text;
    text.setFont(m_font);
    text.setString(str);
    text.setColor(color);
    text.setCharacterSize(charSize);
    text.setPosition(x + rectWidth/2 - text.getLocalBounds().width/2, y + rectHeight/2 );
    WindowManager::WINDOW_MANAGER->draw(text);
}
