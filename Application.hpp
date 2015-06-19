/**
@Owner : Timoth� Noki, Aria

@Projet : Casse Briques

@Description :
Classe de base pour l'application, g�re la boucle d'�v�nnements
et la boucle principale
Permet de relier les diff�rents modules (Son, fen�tre, jeu)


**/
#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class WindowManager;
class Application
{
    public :
        static float DELTA_TIME;
        static Application* APP;
        Application(int windowWidth = 720, int windowHeight = 480, std::string windowName = "Mon jeu");
        ~Application();

        void start();
        void stop();
        void run();

        void pause();
        void resume();

        bool isPaused()const;

    private :

        void mainLoop();
        sf::Clock m_clock;
        WindowManager * m_windowManager;
        bool m_pause;
        bool m_running;
};

#endif // APPLICATION_HPP_INCLUDED
