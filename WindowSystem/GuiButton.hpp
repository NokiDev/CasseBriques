#ifndef GUIBUTTON_HPP_INCLUDED
#define GUIBUTTON_HPP_INCLUDED

class GuiButton
{
    public :
        virtual ~GuiButton();
        virtual void draw();

        unsigned int getId()const;
        unsigned int getWidth()const;
        unsigned int getHeight()const;

        sf::Vector2f& getPosition()const;

        std::string getDisplayString()const;

        void setWidth(unsigned int width);
        void setHeight(unsigned int height);
        void setDisplayString(std::string str);

    protected :

        unsigned int m_id;
        unsigned int m_width;
        unsigned int m_height;
        sf::Vector2f m_position;
        std::string m_displayString;

};

#endif // GUIBUTTON_HPP_INCLUDED
