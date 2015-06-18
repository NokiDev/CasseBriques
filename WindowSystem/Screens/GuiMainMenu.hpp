#ifndef GUIMAINMENU_HPP_INCLUDED
#define GUIMAINMENU_HPP_INCLUDED

class GuiMainMenu
{
    public :
        GuiMainMenu();
        ~GuiMainMenu();

        virtual void initGui();
        virtual void update();
        virtual void draw();

        virtual void actionPerformed();

    private :

};

#endif // GUIMAINMENU_HPP_INCLUDED
