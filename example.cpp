#include "include/includes.hpp"

class Game : public Window
{
public:
    void UserStart() override
    {
        return;
    }
    void UserUpdate() override
    {
        Clear(Colors::Red);
    }
};

int main()
{
    Game instance;
    instance.Start(800, 600, "Example App");
    return 0;
}