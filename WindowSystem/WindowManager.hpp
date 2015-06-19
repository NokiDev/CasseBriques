/**
@Description :
Module de fenêtrage, qui va gérer la fenetre les différents évenemments
ainsi que les "Scenes"(Menu Pause, menu principal etc...)
**/
#ifndef WINDOWMANAGER_HPP_INCLUDED
#define WINDOWMANAGER_HPP_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Application;
class GuiScreen;
class WindowManager
{
    public :
        static WindowManager * WINDOW_MANAGER;
        WindowManager(Application* application, int winWidth, int winHeight, std::string winName);
        ~WindowManager();

        void checkEvents();///Vérifie les évènements(fenetre, clavier, souris, etc...)
        void updateWindow();
        void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);///Dessine dans le buffer
        void display();///Affiche tous les objets stocker dans le buffer de dessin
        void clear();///Nettoie la fenêtre

        void displayScreen(GuiScreen* screen);
        void displaySubScreen();

        unsigned int getWidth();
        unsigned int getHeight();

    private:
        sf::Event m_event;
        sf::RenderWindow m_window;
        Application* m_application;
        GuiScreen* m_currentGuiScreen;


};

#endif // WINDOWMANAGER_HPP_INCLUDED
