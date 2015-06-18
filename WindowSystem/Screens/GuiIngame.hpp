#ifndef GUIINGAME_HPP_INCLUDED
#define GUIINGAME_HPP_INCLUDED

#include "GuiScreen.hpp"

class GuiIngame
{
    public :
        GuiIngame();
        ~GuiIngame();

        virtual void initGui();
        virtual void update();
        virtual void draw();
    private :

};

#endif // GUIINGAME_HPP_INCLUDED
