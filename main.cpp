#include <iostream>
#include "Application.hpp"
using namespace std;

int main()
{
    Application application(75*10, 30*20, "Casse briques");
    application.run();
    return 0;
}
