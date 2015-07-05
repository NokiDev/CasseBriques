#ifndef DROP_HPP_INCLUDED
#define DROP_HPP_INCLUDED
#include "Entity.hpp"

class Drop : public Entity
{
    public :
        Drop();
        ~Drop();

        virtual void update();
        virtual void draw();

    private :
};

#endif // DROP_HPP_INCLUDED
