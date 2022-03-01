#include <iostream>
#include <Windows.h>

#define WHITE_BACKGROUND SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE) | FOREGROUND_RED & FOREGROUND_GREEN & FOREGROUND_BLUE) 
#define BLACK_BACKGROUND SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_RED & BACKGROUND_GREEN & BACKGROUND_BLUE) | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) 

short MainMenu();
void SingleNumber();
void DoubleNumber();
int main()
{
    switch (MainMenu())
    {
    case 0:
        // Single number input
        SingleNumber();
        break;
    case 1:
        // 2 Number input
        DoubleNumber();
        break;
    case 2:
        // Exit
        break;
    }
	return 0;
}

short MainMenu()
{
    bool doLoop = true;
    short curPos = 0;

    while (doLoop)
    {
        // Print menu options
        switch (curPos)
        {
        case 0:
            WHITE_BACKGROUND;
            std::cout << "[Input Single Number]\n";
            BLACK_BACKGROUND;
            std::cout << "[Calculate 2 Numbers]\n";
            std::cout << "[EXIT]\n";
            break;
        case 1:
            BLACK_BACKGROUND;
            std::cout << "[Input Single Number]\n";
            WHITE_BACKGROUND;
            std::cout << "[Calculate 2 Numbers]\n";
            BLACK_BACKGROUND;
            std::cout << "[EXIT]\n";
            break;
        case 2:
            BLACK_BACKGROUND;
            std::cout << "[Input Single Number]\n";
            std::cout << "[Calculate 2 Numbers]\n";
            WHITE_BACKGROUND;
            std::cout << "[EXIT]\n";
            BLACK_BACKGROUND;
            break;
        default:
            std::cout << "\n\nYou dun goofed somehow\n\n";
        }
        // Get user input
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            switch (curPos)
            {
            case 0:
                // Single number input
                doLoop = !doLoop;
                break;
            case 1:
                // 2 Number input
                doLoop = !doLoop;
                break;
            case 2:
                // Exit
                doLoop = !doLoop;
                break;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x1)
        {
            if (curPos == 0 || curPos == 1)
            {
                ++curPos;
            }
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos == 1 || curPos == 2)
            {
                --curPos;
            }
        }
        Sleep(100);
        system("cls");
    }
    return curPos;
}
void SingleNumber()
{

}
void DoubleNumber()
{

}