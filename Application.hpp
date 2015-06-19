/**
@Owner : Timothé Noki, Aria

@Projet : Casse Briques

@Description :
Classe de base pour l'application, gère la boucle d'évènnements
et la boucle principale
Permet de relier les différents modules (Son, fenêtre, jeu)


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
        ///Variable static on peut y acceder sans utiliser l'objet càd Application::DELTA_TIME et non application.DELTA_TIME
        static float DELTA_TIME; ///Temps en seconde d'un tour de boucle utilisé pour rafraichir le contenu
        static Application* APP; ///
        Application(int windowWidth = 720, int windowHeight = 480, std::string windowName = "Mon jeu");
        ~Application();

        void start();///Met en place le jeu du casse brique
        void stop();///Arrete l'application
        void run();///Boucle principale

        void pause();///Met en ^pause le jeu
        void resume();///Depause le jeu

        bool isPaused()const;///Getter pour le bool pause

    private :

        void mainLoop();
        sf::Clock m_clock;///Horloge pour calculer le deltaTime
        WindowManager * m_windowManager;///Le gestionnaire de fenetre
        bool m_pause;///Indique si l'application est en pause
        bool m_running;///Indique si l'application est en pause
};

#endif // APPLICATION_HPP_INCLUDED
