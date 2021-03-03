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
    std::srand(1);
    Mars mars;
    Rover rover;
    rover.land(mars);

    char input = '0';

    // Keep looping for update, also put a means to capture input per cycle. 
    // Use alt+F4 to quit.
    while(true)
    {
        mars.display();
        std::cout << "Input =>";
        std::cin >> input;  //Normally, input wait would block - but if inputstream is mess up, things will start infinite again.
        rover.processInput(input); // And ideally, handle separately.
        Sleep(200);
    }
    system("pause");
}
