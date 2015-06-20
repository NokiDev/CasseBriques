#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

class World
{
    public :
        World();
        ~World();

        void loadFromFile(std::string levelFile);
        void update();
        void draw();

    private :


};

#endif // WORLD_HPP_INCLUDED
