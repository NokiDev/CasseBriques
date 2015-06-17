#include "WindowManager.hpp"
#include "../Application.hpp"

WindowManager* WindowManager::WINDOW_MANAGER;

WindowManager::WindowManager(Application* application, int winWidth, int winHeight, std::string winName)
{
    m_application = application;
    m_window.create(sf::VideoMode(winWidth, winHeight), winName);
    WindowManager::WINDOW_MANAGER = this;
}

WindowManager::~WindowManager()
{

}

void WindowManager::checkEvents()
{
    while(m_window.pollEvent(m_event))/// Boucle d'évènnements
    {
        if(m_event.type == sf::Event::Closed)
        {
            m_application->stop();
            return;
        }
        if(m_event.type == sf::Event::LostFocus)
        {
            m_application->pause();
        }
        if(m_event.type == sf::Event::GainedFocus)
        {
            m_application->resume();
        }
        if(!m_application->isPaused())
        {
            if(m_event.type == sf::Event::KeyPressed)
            {

            }
            if(m_event.type == sf::Event::KeyReleased)
            {

            }
        }
    }
}

void WindowManager::clear()
{
    m_window.clear();
}

void WindowManager::display()
{
    m_window.display();
}

void WindowManager::draw(const sf::Drawable &drawable, const sf::RenderStates &states)
{
    m_window.draw(drawable, states);
}
