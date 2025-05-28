#include "mars.h"
#include "rover.h"
#include <ctime> //for time() in srand( time(NULL) );
#include <cstdlib>
#include <iostream>

/* Taken from https://www.softwaretestinghelp.com/cpp-sleep/ */
#if defined _WIN32
#include <windows.h>
#else
#include <uinstd.h>
#endif //#if defined _WIN32

int main()
{
    std::srand(time(NULL));
    Mars mars;
    Rover rover;
    rover.land(mars);

    char input = '0';

    // Keep looping for update, also put a means to capture input per cycle. 
    // Use alt+F4 to quit.
    while (true)
    {
        mars.display();
        std::cout << "Input =>";
        std::cin >> input;
        rover.processInput(input);
        Sleep(200);
    }
    system("pause");
}
