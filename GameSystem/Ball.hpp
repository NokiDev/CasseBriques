#ifndef BALL_HPP_INCLUDED
#define BALL_HPP_INCLUDED

class Ball
{

    public :
        Ball();
        ~Ball();

        void update();
        void draw();


    private :
        float m_radius;
};

#endif // BALL_HPP_INCLUDED
