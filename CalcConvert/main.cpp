#include <iostream>
#include <Windows.h>
#include "ValueConvert.h"

#define WHITE_BACKGROUND SetConsoleTextAttribute(hCon, (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE) | FOREGROUND_RED & FOREGROUND_GREEN & FOREGROUND_BLUE)
#define BLACK_BACKGROUND SetConsoleTextAttribute(hCon, (BACKGROUND_RED & BACKGROUND_GREEN & BACKGROUND_BLUE) | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

short MainMenu();
void SingleNumber();
void DoubleNumber();
void get_hex();

HANDLE hCon;
int main()
{
    // Get handle to console
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the console cursor visibility
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = sizeof(cursorInfo);
    GetConsoleCursorInfo(hCon, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hCon, &cursorInfo);

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
    bool key_was_pressed = true;

    while (doLoop)
    {
        if(key_was_pressed == true)
        {
            system("cls");
            std::cout << "\t\tCalc Convert\n\nSelect Number of Inputs\n\n";
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
            key_was_pressed = false;
        }
        key_was_pressed = false;
        // Get user input
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            switch (curPos)
            {
            case 0:
                // Single number input
            case 1:
                // 2 Number input
            case 2:
                // Exit
                system("cls");
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
            key_was_pressed = true;
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos == 1 || curPos == 2)
            {
                --curPos;
            }
            key_was_pressed = true;
        }
        Sleep(10);
    }
    return curPos;
}
void SingleNumber()
{
    bool doLoop = true;
    short curPos = 0;
    bool key_was_pressed = true;

    while (doLoop)
    {
        if (key_was_pressed)
        {
            system("cls");
            std::cout << "\t\tCalc Convert\n\nSelect Input Type\n\n";
            // Print menu options
            switch (curPos)
            {
            case 0:
                WHITE_BACKGROUND;
                std::cout << "[Floating point]\n";
                BLACK_BACKGROUND;
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 1:
                std::cout << "[Floating point]\n";
                WHITE_BACKGROUND;
                std::cout << "[Hex]\n";
                BLACK_BACKGROUND;
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 2:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                WHITE_BACKGROUND;
                std::cout << "[Binary]\n";
                BLACK_BACKGROUND;
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 3:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                WHITE_BACKGROUND;
                std::cout << "[SEM]\n";
                BLACK_BACKGROUND;
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 4:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                WHITE_BACKGROUND;
                std::cout << "[Return]\n";
                BLACK_BACKGROUND;
                std::cout << "[EXIT]\n";
                break;

            case 5:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                WHITE_BACKGROUND;
                std::cout << "[EXIT]\n";
                BLACK_BACKGROUND;
                break;
            default:
                std::cout << "\n\nYou dun goofed somehow\n\n";
            }
            key_was_pressed = false;
        }

        // Get user input
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            switch (curPos)
            {
            case 0:
                // Flaoting Point
                doLoop = !doLoop;
                break;
            case 1:
                // Hex
                system("cls");
                get_hex();
                Sleep(1000);
                doLoop = !doLoop;
                break;
            case 2:
                // Binary
                doLoop = !doLoop;
                break;
            case 3:
                // SEM
                doLoop = !doLoop;
                break;
            case 4:
                //Return
                MainMenu();
                doLoop = !doLoop;
                break;
            case 5:
                // Exit
                doLoop = !doLoop;
                break;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x1)
        {
            if (curPos >= 0 && curPos < 5)
            {
                ++curPos;
            }
            key_was_pressed = true;
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos > 0 && curPos <= 5)
            {
                --curPos;
            }
            key_was_pressed = true;
        }
        Sleep(10);
    }
}
void DoubleNumber()
{
    bool doLoop = true;
    short curPos = 0;
    bool key_was_pressed = true;

    while (doLoop)
    {
        if (key_was_pressed)
        {
            system("cls");
            std::cout << "\t\tCalc Convert\n\nSelect Input Type\n\n";
            // Print menu options
            switch (curPos)
            {
            case 0:
                WHITE_BACKGROUND;
                std::cout << "[Floating point]\n";
                BLACK_BACKGROUND;
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 1:
                std::cout << "[Floating point]\n";
                WHITE_BACKGROUND;
                std::cout << "[Hex]\n";
                BLACK_BACKGROUND;
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 2:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                WHITE_BACKGROUND;
                std::cout << "[Binary]\n";
                BLACK_BACKGROUND;
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 3:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                WHITE_BACKGROUND;
                std::cout << "[SEM]\n";
                BLACK_BACKGROUND;
                std::cout << "[Return]\n";
                std::cout << "[EXIT]\n";
                break;
            case 4:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                WHITE_BACKGROUND;
                std::cout << "[Return]\n";
                BLACK_BACKGROUND;
                std::cout << "[EXIT]\n";
                break;
            case 5:
                std::cout << "[Floating point]\n";
                std::cout << "[Hex]\n";
                std::cout << "[Binary]\n";
                std::cout << "[SEM]\n";
                std::cout << "[Return]\n";
                WHITE_BACKGROUND;
                std::cout << "[EXIT]\n";
                BLACK_BACKGROUND;
                break;
            default:
                std::cout << "\n\nYou dun goofed somehow\n\n";
            }
            key_was_pressed = false;
        }

        // Get user input
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            switch (curPos)
            {
            case 0:
                // Flaoting Point
                doLoop = !doLoop;
                break;
            case 1:
                // Hex
                doLoop = !doLoop;
                break;
            case 2:
                // Binary
                doLoop = !doLoop;
                break;
            case 3:
                // SEM
                doLoop = !doLoop;
                break;
            case 4:
                //return
                MainMenu();
                doLoop = !doLoop;
                break;
            case 5:
                // Exit
                doLoop = !doLoop;
                break;
            }
            key_was_pressed = true;
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x1)
        {
            if (curPos >= 0 && curPos < 5)
            {
                ++curPos;
            }
            key_was_pressed = true;
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos > 0 && curPos <= 5)
            {
                --curPos;
            }
            key_was_pressed = true;
        }
        Sleep(10);
    }
}

void get_hex()
{
    std::cout << "Please enter a valid Hexadecimal number" << std::endl;
    std::string input;
    std::cin >> input;
    std::cout << "Hex:\t" << input << std::endl;
    std::cout << "Binary:\t" << VC::hex_to_binary(input) << std::endl;
    std::cout << "SEM:\t";
    VC::hex_to_SEM(input);
    std::cout << "\nFloat:\t" << VC::hex_to_float(input) << std::endl;

}