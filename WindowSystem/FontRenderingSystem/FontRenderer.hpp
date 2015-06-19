#ifndef FONTRENDERER_HPP_INCLUDED
#define FONTRENDERER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class FontRenderer
{
    public:
        static FontRenderer FONT_RENDERER;
        FontRenderer();
        ~FontRenderer();

        void printString(std::string str, int x, int y, sf::Color color, int charSize);
        void printCenteredString(std::string str, int x, int y, int rectWidth, int rectHeight,  sf::Color color, int charSize);

    private:
        sf::Font m_font;

};

#endif // FONTRENDERER_HPP_INCLUDED
