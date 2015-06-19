#include "GuiScreen.hpp"
#include "WindowSystem/Buttons/GuiButton.hpp"
#include "WindowSystem/WindowManager.hpp"


GuiScreen::~GuiScreen(){}

void GuiScreen::initGui()
{
    if (buttonList.size()>0)
    {
        ite = buttonList.begin();
        selectedButton = *ite;
        if(selectedButton->getState() == B_DISABLED)
        {
            if(ite == buttonList.end())
                selectedButton = nullptr;
            else
                ite++;
        }
        else
        {
            selectedButton->setState(B_FOCUS);
        }

    }
    else
    {
        selectedButton = nullptr;
    }
    if(doesGuiPauseGame())
    {
        /*sf::Color colorBase = sf::Color(0 ,0, 50, 127);
        m_img.create(WINDOW_WIDTH, WINDOW_HEIGHT, colorBase);
        m_texture.loadFromImage(m_img);
        m_sprite.setTexture(m_texture);*/
    }
}
/****/
void GuiScreen::update(){}
/****/
void GuiScreen::onGuiClosed(){}
/****/
void GuiScreen::draw()
{
    std::list<GuiButton*>::iterator it;
    WindowManager::WINDOW_MANAGER->draw(m_background);
    for (it=buttonList.begin(); it!= buttonList.end(); it++)
    {
        GuiButton *button =  *it;
        std::cout<<"Test Draw Button id = "<<button->getId()<<std::endl;
        button->draw();
    }
}
/****/
void GuiScreen::actionPerformed(GuiButton& guiButton){}
/****/
void GuiScreen::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
        handleKeyboardInput(event);
    if (event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Return:
                if(selectedButton != nullptr)
                {
                    actionPerformed(*selectedButton);
                }
            break;
            case sf::Keyboard::Escape:
            WindowManager::WINDOW_MANAGER->displayScreen(nullptr);
            break;
        }
    }
}
/****/
void GuiScreen::handleKeyboardInput(sf::Event& event)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Up:
            KeyBoardUp();
        break;
        case sf::Keyboard::Down:
            KeyBoardDown();
        break;
        case sf::Keyboard::Left:
            KeyBoardLeft();
        break;
        case sf::Keyboard::Right:
            KeyBoardRight();
        break;
    }
    if(selectedButton != nullptr && selectedButton->getState() != B_FOCUS)
        selectedButton->setState(B_FOCUS);
}
/****/
void GuiScreen::KeyBoardDown()
{
    if(selectedButton != nullptr)
    {
        if(selectedButton->getState() == B_FOCUS)
            selectedButton->setState(B_DEFAULT);
        GuiButton* nextButton = nullptr;
        int minX = selectedButton->getPosition().x -100;
        int maxX = selectedButton->getPosition().x +100;
        int minY = selectedButton->getPosition().y;
        int maxY = WindowManager::WINDOW_MANAGER->getHeight();
        for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
        {
            if(selectedButton != *it)
            {
                GuiButton * tempButton= *it;
                if(tempButton->getPosition().y> minY && tempButton->getPosition().y < maxY  && tempButton->getPosition().x <= maxX && tempButton->getPosition().x >= minX)
                {
                    maxX = tempButton->getPosition().x;
                    maxY = tempButton->getPosition().y;
                    nextButton = tempButton;
                }
            }
        }
        if(nextButton == nullptr)
        {
            for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
            {
                if(selectedButton != *it)
                {
                    GuiButton * tempButton= *it;
                    if(tempButton->getPosition().y < minY && tempButton->getPosition().y < maxY && tempButton->getPosition().x <= maxX && tempButton->getPosition().x >= minX)
                    {
                        maxX = tempButton->getPosition().x;
                        maxY = tempButton->getPosition().y;
                        nextButton = tempButton;
                    }
                }
            }
        }
        if(nextButton != nullptr)
            selectedButton = nextButton;
    }
}
/****/
void GuiScreen::KeyBoardUp()
{
    if(selectedButton != nullptr)
    {
        if(selectedButton->getState() == B_FOCUS)
            selectedButton->setState(B_DEFAULT);
        GuiButton* nextButton = nullptr;
        int minX = selectedButton->getPosition().x -100;
        int maxX = selectedButton->getPosition().x +100;
        int minY = selectedButton->getPosition().y;
        int maxY = 0;
        for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
        {
            if(selectedButton != *it)
            {
                GuiButton * tempButton= *it;
                if(tempButton->getPosition().y < minY && tempButton->getPosition().y > maxY  && tempButton->getPosition().x <= maxX && tempButton->getPosition().x >= minX)
                {
                    maxX = tempButton->getPosition().x;
                    maxY = tempButton->getPosition().y;
                    nextButton = tempButton;
                }
            }
        }
        if(nextButton == nullptr)
        {
            for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
            {
                if(selectedButton != *it)
                {
                    GuiButton * tempButton= *it;
                    if(tempButton->getPosition().y > minY && tempButton->getPosition().y > maxY && tempButton->getPosition().x <= maxX && tempButton->getPosition().x >= minX)
                    {
                        maxX = tempButton->getPosition().x;
                        maxY = tempButton->getPosition().y;
                        nextButton = tempButton;
                    }
                }
            }
        }
        if(nextButton != nullptr)
            selectedButton = nextButton;
    }
}

void GuiScreen::KeyBoardLeft()
{
    if(selectedButton != nullptr)
    {
        if(selectedButton->getState() == B_FOCUS)
            selectedButton->setState(B_DEFAULT);
        GuiButton* nextButton = nullptr;
        int minX = selectedButton->getPosition().x;
        int maxX = 0;
        int minY = selectedButton->getPosition().y -50;
        int maxY = selectedButton->getPosition().y + 50;
        for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
        {
            if(selectedButton != *it)
            {
                GuiButton * tempButton= *it;
                if(tempButton->getPosition().x< minX && tempButton->getPosition().x > maxX  && tempButton->getPosition().y <= maxY && tempButton->getPosition().y >= minY)
                {
                    maxX = tempButton->getPosition().x;
                    maxY = tempButton->getPosition().y;
                    nextButton = tempButton;
                }
            }
        }
        if(nextButton == nullptr)
        {
            for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
            {
                if(selectedButton != *it)
                {
                    GuiButton * tempButton= *it;
                    if(tempButton->getPosition().x > minX && tempButton->getPosition().x > maxX && tempButton->getPosition().y <= maxY && tempButton->getPosition().y >= minY)
                    {
                        maxX = tempButton->getPosition().x;
                        maxY = tempButton->getPosition().y;
                        nextButton = tempButton;
                    }
                }
            }
        }
        if(nextButton != nullptr)
            selectedButton = nextButton;
    }
}

void GuiScreen::KeyBoardRight()
{
    if(selectedButton != nullptr)
    {
        if(selectedButton->getState() == B_FOCUS)
            selectedButton->setState(B_DEFAULT);
        GuiButton* nextButton = nullptr;
        int minX = selectedButton->getPosition().x;
        int maxX = WindowManager::WINDOW_MANAGER->getWidth();
        int minY = selectedButton->getPosition().y -50;
        int maxY = selectedButton->getPosition().y + 50;
        for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
        {
            if(selectedButton != *it)
            {
                GuiButton * tempButton= *it;
                //std::cout<<"TempButton "<<tempButton->getString()<<" : <"<<tempButton->getPosX()<<","<<tempButton->getPosY()<<">"<<std::endl;
                if(tempButton->getPosition().x > minX && tempButton->getPosition().x < maxX  && tempButton->getPosition().y <= maxY && tempButton->getPosition().y >= minY)
                {
                    //std::cout<<"Test"<<std::endl;
                    maxX = tempButton->getPosition().x;
                    maxY = tempButton->getPosition().y;
                    nextButton = tempButton;
                }
            }
        }
        if(nextButton == nullptr)
        {
            for(std::list<GuiButton*>::iterator it = buttonList.begin();it != buttonList.end(); it++)
            {
                if(selectedButton != *it)
                {
                    GuiButton * tempButton= *it;
                    if(tempButton->getPosition().x < minX && tempButton->getPosition().x < maxX && tempButton->getPosition().y <= maxY && tempButton->getPosition().y >= minY)
                    {
                        maxX = tempButton->getPosition().x;
                        maxY = tempButton->getPosition().y;
                        nextButton = tempButton;
                    }
                }
            }
        }
        if(nextButton != nullptr)
            selectedButton = nextButton;
    }
}

/****/
bool GuiScreen::doesGuiPauseGame()
{
    return true;
}
