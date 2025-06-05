#include "headers/includes.h"

class Game : public Window
{
public:
    void UserStart() override
    {
        return;
    }
    void UserUpdate() override
    {

    }
};

int main()
{
    Game instance;
    instance.Start(800, 600, "Window");
    return 0;
}