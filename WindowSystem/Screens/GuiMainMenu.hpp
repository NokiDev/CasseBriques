#ifndef GUIMAINMENU_HPP_INCLUDED
#define GUIMAINMENU_HPP_INCLUDED

#include "WindowSystem/Screens/GuiScreen.hpp"

class GuiButton;
class GuiMainMenu : public GuiScreen
{
    public :
        GuiMainMenu();
        ~GuiMainMenu();

        virtual void initGui();
        virtual void draw();
        virtual void update();
        virtual void actionPerformed(GuiButton& guiButton);

    private :

};

#endif // GUIMAINMENU_HPP_INCLUDED
