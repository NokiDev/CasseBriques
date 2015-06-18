#ifndef GUIBUTTON_HPP_INCLUDED
#define GUIBUTTON_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include "WindowSystem/WindowSystemEnums.h"

class GuiButton
{
    public :
        virtual ~GuiButton();
        virtual void draw();
///GETTERS
        unsigned int getId()const;
        unsigned int getWidth()const;
        unsigned int getHeight()const;
        sf::Vector2i getPosition()const;
        std::string getDisplayString()const;
        ButtonState getState()const;
///SETTERS
        void setWidth(unsigned int width);
        void setHeight(unsigned int height);
        void setDisplayString(std::string str);
        void setPosition(sf::Vector2i position);
        void setState(ButtonState state);

    protected :

        sf::Sprite m_sprite;
        sf::Texture m_texture;

        unsigned int m_id;///Identifiant du bouton dans le GUI
        unsigned int m_width;///Largeur du bouton
        unsigned int m_height;///Hauteur du bouton
        sf::Vector2i m_position;///Position x et y du bouton
        std::string m_displayString;///Chaine de caractères affiché

        //bool drawButton;///Booléen pour savoir si le bouton doit être dessiné

        ButtonState m_buttonState;///Etat du bouton (Désactivé, focus, error)

};

#endif // GUIBUTTON_HPP_INCLUDED
