#ifndef FONTRENDERER_HPP_INCLUDED
#define FONTRENDERER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class FontRenderer
{
    public:
        static void initFont();

        static void printString(std::string str, int x, int y, sf::Color color, int charSize);
        static void printCenteredString(std::string str, int x, int y, int rectWidth, int rectHeight,  sf::Color color, int charSize);

    private:
        static sf::Font m_font;

};

#endif // FONTRENDERER_HPP_INCLUDED
