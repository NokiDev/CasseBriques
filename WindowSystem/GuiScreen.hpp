#ifndef GUISCREEN_HPP_INCLUDED
#define GUISCREEN_HPP_INCLUDED

class GuiScreen
{
    public :
        virtual ~GuiScreen();
        virtual void initGui();
        virtual void draw();
        virtual void update();
        virtual void handleInput();
        virtual void actionPerformed();

        virtual bool doesGUIPauseGame();

    protected :


};

#endif // GUISCREEN_HPP_INCLUDED
