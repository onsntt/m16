#include <iostream>

int main()
{
    float speedDelta = 0.f;
    float speed = 0.f;
    char speedStr[5] = {0};

    do
    {
        std::cout << "Enter your speed delta: ";
        std::cin >> speedDelta;
        speed += speedDelta;
        if (speed > 150.f)
        {
            speed = 150.f;
        }
        else
        {
            if (speed < 0.f)
            {
                speed = 0.f;
            }
        }
        std::sprintf(speedStr, "%.1f", speed);
        std::cout << "Speed now: " << speedStr << "\n";

    } while (speed > 0.01f);
    std::cout << "TPRUUUU!! Pipez, priehali!! Slivai vodu, buhaem!";
    // nightmare_fart_method task_creating_and_disribing detected
    // it's just a 'sprintf' illustration, no more, but what a foolish task?
    //sorry.
}