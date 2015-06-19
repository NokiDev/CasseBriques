#ifndef GUISCREEN_HPP_INCLUDED
#define GUISCREEN_HPP_INCLUDED

#include <list>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
///Class virtuell liste de fonction par défaut d'un GUI
class GuiButton;
class GuiScreen
{
    public :
        virtual ~GuiScreen();
        virtual void initGui();///Initialise les bouttons
        virtual void draw();///Dessine le GUI
        virtual void update();///Met a jour le GUI
        virtual void handleInput(sf::Event & event);///Traite les evenement clavier pour les interfaces qui mettent en pause le jeu
        virtual void actionPerformed(GuiButton& guiButton);///Action effectué sur le bouton passé en param
        virtual void onGuiClosed();///Action lorsque le GUI est fermé
        virtual bool doesGuiPauseGame();///Est ce que le jeu est mis en pause

    protected :
        void KeyBoardUp();
        void KeyBoardDown();
        void KeyBoardLeft();
        void KeyBoardRight();
        void handleKeyboardInput(sf::Event & event);

        int m_width;
        int m_height;
        sf::Texture m_backgroundTexture;
        sf::Sprite m_background;
        sf::Image m_img;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        std::list <GuiButton*> buttonList;
        std::list<GuiButton*>::iterator ite;
        GuiButton* selectedButton;
};

#endif // GUISCREEN_HPP_INCLUDED
