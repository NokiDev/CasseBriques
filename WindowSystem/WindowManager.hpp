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
        void updateWindow();///Met à jour la fenetre et tous ses éléments
        void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);///Dessine dans le buffer
        void display();///Affiche tous les objets stocker dans le buffer de dessin
        void clear();///Nettoie la fenêtre

        void displayScreen(GuiScreen* screen);///Affiche le Gui passé en paramètre
        void displaySubScreen();///Affiche le sous écran de la fenêtre actuelle.

        unsigned int getWidth();
        unsigned int getHeight();

    private:
        sf::Event m_event;///Event
        sf::RenderWindow m_window;///Fenetre
        Application* m_application;///Application
        GuiScreen* m_currentGuiScreen;///Gui affiché


};

#endif // WINDOWMANAGER_HPP_INCLUDED
