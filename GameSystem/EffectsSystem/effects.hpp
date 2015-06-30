#ifndef EFFECTS_HPP_INCLUDED
#define EFFECTS_HPP_INCLUDED

class Effects
{
    public :
        virtual ~Effects();
        virtual void launch();
        virtual void stop();
        virtual bool isDone();

    protected :
        float timer;
};

#endif // EFFECTS_HPP_INCLUDED
