/**
@Description :
Module de fen�trage, qui va g�rer la fenetre les diff�rents �venemments
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

        void checkEvents();///V�rifie les �v�nements(fenetre, clavier, souris, etc...)
        void updateWindow();///Met � jour la fenetre et tous ses �l�ments
        void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);///Dessine dans le buffer
        void display();///Affiche tous les objets stocker dans le buffer de dessin
        void clear();///Nettoie la fen�tre

        void displayScreen(GuiScreen* screen);///Affiche le Gui pass� en param�tre
        void displaySubScreen();///Affiche le sous �cran de la fen�tre actuelle.

        unsigned int getWidth();
        unsigned int getHeight();

    private:
        sf::Event m_event;///Event
        sf::RenderWindow m_window;///Fenetre
        Application* m_application;///Application
        GuiScreen* m_currentGuiScreen;///Gui affich�


};

#endif // WINDOWMANAGER_HPP_INCLUDED
