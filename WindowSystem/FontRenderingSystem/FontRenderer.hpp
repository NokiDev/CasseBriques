#ifndef FONTRENDERER_HPP_INCLUDED
#define FONTRENDERER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class FontRenderer
{
    public:
        static FontRenderer FONT_RENDERER;///Instance du font Renderer
        FontRenderer();
        ~FontRenderer();

        void printString(std::string str, int x, int y, sf::Color color, int charSize);///Imprime une string sur la fenetre
        void printCenteredString(std::string str, int x, int y, int rectWidth, int rectHeight,  sf::Color color, int charSize);

    private:
        sf::Font m_font;///Police d'écriture

};

#endif // FONTRENDERER_HPP_INCLUDED
