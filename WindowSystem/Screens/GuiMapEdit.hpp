#ifndef GUIMAPEDIT_HPP_INCLUDED
#define GUIMAPEDIT_HPP_INCLUDED
#include "GuiScreen.hpp"

class GuiMapEdit : public GuiScreen
{
    public :
        GuiMapEdit();
        ~GuiMapEdit();

        virtual void initGui();

        virtual void draw();
        virtual void update();

        virtual void handleInput(sf::Event & event);


    private :
        void handleMouseEvent(sf::Event & event);



};

#endif // GUIMAPEDIT_HPP_INCLUDED
