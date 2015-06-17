#include "Application.hpp"
#include "WindowSystem/WindowManager.hpp"

Application::Application(int windowWidth, int windowHeight, std::string windowName)
{
    m_running = true;
    m_pause = false;
    m_windowManager = new WindowManager(this, windowWidth, windowHeight, windowName);
}

Application::~Application()
{

}

void Application::run()
{
    while(m_running)///Boucle principale
    {
        m_windowManager->checkEvents();
        m_windowManager->clear();
        if(!m_pause)
        {

        }
        m_windowManager->display();
    }
}

void Application::start()
{

}

void Application::stop()
{
    m_running = false;
}

void Application::pause()
{
    m_pause = true;
}

void Application::resume()
{
    m_pause = false;
}

bool Application::isPaused()const
{
    return m_pause;
}
