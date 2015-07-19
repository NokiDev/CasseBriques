  #ifndef GUIINGAME_HPP_INCLUDED
#define GUIINGAME_HPP_INCLUDED

#include "GuiScreen.hpp"

class World;
class GuiIngame : public GuiScreen
{
    public :
        GuiIngame(World * world);
        ~GuiIngame();

        virtual void initGui();
        virtual void update();
        virtual void draw();
        virtual void handleInput(sf::Event& event);
        virtual bool doesGuiPauseGame();


    private :

        World* theWorld;

};

#endif // GUIINGAME_HPP_INCLUDED
