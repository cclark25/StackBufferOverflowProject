#include <iostream>
#include "stdint.h"

void AdminAccess(){
    
    char trash[64];
    std::cout << "Enter an admin command to run on the system: ";
    std::cin >> trash;
    std::cout << "DONE\n";
    
}

int main(int argc, char const *argv[])
{
    char adminName[10] = "admin";
    char buf[10];
    
    bool access = 1;

    std::cout << "Greetings! What is your name?\n> ";

    std::cin >> buf;
    std::cout << adminName << "\n";
    int position = 0;
    for(char a : buf)
    {
        if(a != adminName[position])
        {
            access = 0;
            break;
        }
        position++;
    }

    

    if(access)
    {
        std::cout << "Welcome back, " << buf << "!\n";
        AdminAccess();
    }
    else
        std::cout << "It's nice to meet you, " << buf << "! Unfortunately, you don't have any priveledges in this system, so there is nothing to do from here on out.\n";

    return 0;
}
