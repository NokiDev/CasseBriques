#include "Application.hpp"

Application::Application(int windowWidth, int windowHeight, std::string windowName)
{
    m_running = true;
    m_pause = false;
    m_window.create(sf::VideoMode(windowWidth, windowHeight),windowName);
}

Application::~Application()
{

}

void Application::run()
{
    while(m_running)///Boucle principale
    {
        while(m_window.pollEvent(m_event))/// Boucle d'évènnements
        {
            if(m_event.type == sf::Event::Closed)
            {
                stop();
                return;
            }
            if(m_event.type == sf::Event::LostFocus)
            {
                m_pause = true;
            }
            if(m_event.type == sf::Event::GainedFocus)
            {
                m_pause = false;
            }
            if(!m_pause)
            {
                if(m_event.type == sf::Event::KeyPressed)
                {

                }
                if(m_event.type == sf::Event::KeyReleased)
                {

                }
            }
        }
        m_window.clear();
        if(!m_pause)
        {

        }
        m_window.display();
    }
}

void Application::start()
{

}

void Application::stop()
{
    m_running = false;
}
