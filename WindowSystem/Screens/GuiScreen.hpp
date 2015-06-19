#ifndef GUISCREEN_HPP_INCLUDED
#define GUISCREEN_HPP_INCLUDED

#include "WindowSystem/Buttons/GuiButton.hpp"
#include <list>

class GuiScreen
{
    public :
        virtual ~GuiScreen();
        virtual void initGui();
        virtual void draw();
        virtual void update();
        virtual void handleInput(sf::Event & event);
        virtual void actionPerformed(GuiButton& guiButton);
        virtual void onGuiClosed();
        virtual bool doesGuiPauseGame();

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
