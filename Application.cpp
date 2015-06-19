#include "Application.hpp"
#include "WindowSystem/WindowManager.hpp"

float Application::DELTA_TIME;

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
    m_clock.restart();
    while(m_running)///Boucle principale
    {
        m_windowManager->checkEvents();///Boucle d'evennement

        if(!m_pause)
        {
            m_windowManager->clear();///nettoie la fenetre
            m_windowManager->updateWindow();///met a jour la fenetre et dessine l'�cran actuel
            m_windowManager->display();///affiche le contenue du buffer de dessin
        }
        Application::DELTA_TIME = m_clock.restart().asSeconds();
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
