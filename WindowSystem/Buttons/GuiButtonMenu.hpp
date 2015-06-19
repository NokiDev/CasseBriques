#ifndef GUIBUTTONMENU_HPP_INCLUDED
#define GUIBUTTONMENU_HPP_INCLUDED

#include "GuiButton.hpp"

class GuiButtonMenu : public GuiButton
{
    public :
        GuiButtonMenu(int x, int y, unsigned int width, unsigned int height, std::string displayString = "", ButtonState state = B_DEFAULT);
        ~GuiButtonMenu();

        virtual void draw();

    private :


};

#endif // GUIBUTTONMENU_HPP_INCLUDED
