#ifndef GUIBUTTONTEXTURED_HPP_INCLUDED
#define GUIBUTTONTEXTURED_HPP_INCLUDED

#include "GuiButton.hpp"

class GuiButtonTextured : public GuiButton
{
    public :
        virtual ~GuiButtonTextured();
        virtual void draw();

    protected :

        sf::Texture m_texture;
        sf::Sprite m_sprite;

};

#endif // GUIBUTTONTEXTURED_HPP_INCLUDED
