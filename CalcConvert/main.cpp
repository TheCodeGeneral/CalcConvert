#include <iostream>
#include <Windows.h>
#include "ValueConvert.h"
#include "ValueArithmetic.h"

#define WHITE_BACKGROUND SetConsoleTextAttribute(hCon, (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE) | FOREGROUND_RED & FOREGROUND_GREEN & FOREGROUND_BLUE)
#define BLACK_BACKGROUND SetConsoleTextAttribute(hCon, (BACKGROUND_RED & BACKGROUND_GREEN & BACKGROUND_BLUE) | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

void MainMenu();
bool SingleNumber();
bool DoubleNumber();
void OperatorMenu();

void get_hex();
void get_binary();
void get_float();
void get_SEM();


void MainMenuOptions(short curPos);
void SecondMenuOptions(short curPos);
void OperatorMenuOptions(short curPos);
void ClearInputs();

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

    MainMenu();

    return 0;
}

void MainMenu()
{
    bool doLoop = true;
    short curPos = 0;
    MainMenuOptions(curPos);

    while (doLoop)
    {
        // Get user input
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            std::string discard{};
            std::getline(std::cin, discard);
            switch (curPos)
            {
            case 0:
                // Single number input
                if (SingleNumber() == true)
                    MainMenuOptions(curPos);
                else
                    doLoop = !doLoop;

                break;
            case 1:
                // 2 Number input
                if (DoubleNumber() == true)
                    MainMenuOptions(curPos);
                else
                    doLoop = !doLoop;

                break;
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
                MainMenuOptions(++curPos);
            }
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos == 1 || curPos == 2)
            {
                MainMenuOptions(--curPos);
            }
        }
        if ((GetAsyncKeyState(0x31) | GetAsyncKeyState(VK_NUMPAD1)) & 0x1)
        {
            // Single number input
            MainMenuOptions(curPos = 0);
            
        }
        else if ((GetAsyncKeyState(0x32) | GetAsyncKeyState(VK_NUMPAD2)) & 0x1)
        {
            // 2 Number input
            MainMenuOptions(curPos = 1);
        }
        else if ((GetAsyncKeyState(0x33) | GetAsyncKeyState(VK_NUMPAD3)) & 0x1)
        {
            // Exit
            MainMenuOptions(curPos = 2);
        }

        Sleep(10);
    }
}

// returns true when returning to main menu
bool SingleNumber()
{
    bool doLoop = true;
    short curPos = 0;
    SecondMenuOptions(curPos);

    while (doLoop)
    {
        // Select highlighted menu option
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            std::string discard{};
            std::getline(std::cin, discard);
            switch (curPos)
            {
            case 0:
                // Flaoting Point
                get_float();
                doLoop = !doLoop;
                break;
            case 1:
                // Hex
                get_hex();
                doLoop = !doLoop;
                break;
            case 2:
                // Binary
                get_binary();
                doLoop = !doLoop;
                break;
            case 3:
                // SEM
                doLoop = !doLoop;
                break;
            case 4:
                //Return
                return true;
                break;
            case 5:
                // Exit
                doLoop = !doLoop;
                break;
            }
        }
        // Move highlighted menu option down/up
        else if (GetAsyncKeyState(VK_DOWN) & 0x1)
        {
            if (curPos >= 0 && curPos < 5)
            {
                SecondMenuOptions(++curPos);
            }
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos > 0 && curPos <= 5)
            {
                SecondMenuOptions(--curPos);
            }
        }
        
        // Highlight menu options
        if ((GetAsyncKeyState(0x31) | GetAsyncKeyState(VK_NUMPAD1)) & 0x1)
        {
            SecondMenuOptions(curPos = 0);
            // floating point
        }
        else if ((GetAsyncKeyState(0x32) | GetAsyncKeyState(VK_NUMPAD2)) & 0x1)
        {
            SecondMenuOptions(curPos = 1);
            // Hex
        }
        else if ((GetAsyncKeyState(0x33) | GetAsyncKeyState(VK_NUMPAD3)) & 0x1)
        {
            SecondMenuOptions(curPos = 2);
            // Binary
        }
        else if ((GetAsyncKeyState(0x34) | GetAsyncKeyState(VK_NUMPAD4)) & 0x1)
        {
            SecondMenuOptions(curPos = 3);
            // SEM
        }
        else if ((GetAsyncKeyState(0x35) | GetAsyncKeyState(VK_NUMPAD5)) & 0x1)
        {
            SecondMenuOptions(curPos = 4);
            // Return
            //return true;
        }
        else if ((GetAsyncKeyState(0x36) | GetAsyncKeyState(VK_NUMPAD6)) & 0x1)
        {
            SecondMenuOptions(curPos = 5);
            //return false;
            // Exit
        }

        Sleep(10);
    }
    return true;
}

// returns true when returning to main menu
bool DoubleNumber()
{
    bool doLoop = true;
    short curPos = 0;
    SecondMenuOptions(curPos);
    OperatorMenu();

    while (doLoop)
    {
        // Select highlighted menu option
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            std::string discard{};
            std::getline(std::cin, discard);
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
                get_binary();
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
                return false;
                doLoop = !doLoop;
                break;
            }
        }
        // Move highlighted menu option down/up
        else if (GetAsyncKeyState(VK_DOWN) & 0x1)
        {
            if (curPos >= 0 && curPos < 5)
            {
                SecondMenuOptions(++curPos);
            }
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos > 0 && curPos <= 5)
            {
                SecondMenuOptions(--curPos);
            }
        }

        // Highlight menu options
        if ((GetAsyncKeyState(0x31) | GetAsyncKeyState(VK_NUMPAD1)) & 0x1)
        {
            SecondMenuOptions(curPos = 0);
            // floating point
        }
        else if ((GetAsyncKeyState(0x32) | GetAsyncKeyState(VK_NUMPAD2)) & 0x1)
        {
            SecondMenuOptions(curPos = 1);
            // Hex
        }
        else if ((GetAsyncKeyState(0x33) | GetAsyncKeyState(VK_NUMPAD3)) & 0x1)
        {
            SecondMenuOptions(curPos = 2);
            // Binary
        }
        else if ((GetAsyncKeyState(0x34) | GetAsyncKeyState(VK_NUMPAD4)) & 0x1)
        {
            SecondMenuOptions(curPos = 3);
            // SEM
        }
        else if ((GetAsyncKeyState(0x35) | GetAsyncKeyState(VK_NUMPAD5)) & 0x1)
        {
            SecondMenuOptions(curPos = 4);
            // Return
            //return true;
        }
        else if ((GetAsyncKeyState(0x36) | GetAsyncKeyState(VK_NUMPAD6)) & 0x1)
        {
            SecondMenuOptions(curPos = 5);
            //return false;
            // Exit
        }
        Sleep(10);
    }
    return true;
}

void OperatorMenu()
{
    bool doLoop = true;
    short curPos = 0;
    OperatorMenuOptions(curPos);

    while (doLoop)
    {
        // Select highlighted menu option
        if (GetAsyncKeyState(VK_RETURN) & 0x1)
        {
            std::string discard{};
            std::getline(std::cin, discard);
            switch (curPos)
            {
            case 0:
                // Addition
                break;
            case 1:
                // Subtraction
                break;
            case 2:
                // Multiplication
                break;
            case 3:
                // Division
                break;
            case 4:
                // AND
                break;
            case 5:
                // OR
                break;
            case 6:
                // NOR
                break;
            case 7:
                // XOR
                break;
            case 8:
                // SHL
                break;
            case 9:
                // SHR
                break;
            }
        }
        // Move highlighted option down/up
        else if (GetAsyncKeyState(VK_DOWN) & 0x1)
        {
            if (curPos >= 0 && curPos < 9)
            {
                OperatorMenuOptions(++curPos);
            }
        }
        else if (GetAsyncKeyState(VK_UP) & 0x1)
        {
            if (curPos > 0 && curPos <= 9)
            {
                OperatorMenuOptions(--curPos);
            }
        }
        // Highlight menu options
 
        // Addition
        if ((GetAsyncKeyState(0x31) | GetAsyncKeyState(VK_NUMPAD1)) & 0x1)
        {
            OperatorMenuOptions(curPos = 0);
        }
        // Subtraction
        else if ((GetAsyncKeyState(0x32) | GetAsyncKeyState(VK_NUMPAD2)) & 0x1)
        {
            OperatorMenuOptions(curPos = 1);
        }
        // Multiplication
        else if ((GetAsyncKeyState(0x33) | GetAsyncKeyState(VK_NUMPAD3)) & 0x1)
        {
            OperatorMenuOptions(curPos = 2);
        }
        // Division
        else if ((GetAsyncKeyState(0x34) | GetAsyncKeyState(VK_NUMPAD4)) & 0x1)
        {
            OperatorMenuOptions(curPos = 3);
        }
        // AND
        else if ((GetAsyncKeyState(0x35) | GetAsyncKeyState(VK_NUMPAD5)) & 0x1)
        {
            OperatorMenuOptions(curPos = 4);
        }
        // OR
        else if ((GetAsyncKeyState(0x36) | GetAsyncKeyState(VK_NUMPAD6)) & 0x1)
        {
            OperatorMenuOptions(curPos = 5);
        }
        // NOR
        else if ((GetAsyncKeyState(0x37) | GetAsyncKeyState(VK_NUMPAD7)) & 0x1)
        {
            OperatorMenuOptions(curPos = 6);
        }
        // XOR
        else if ((GetAsyncKeyState(0x38) | GetAsyncKeyState(VK_NUMPAD8)) & 0x1)
        {
            OperatorMenuOptions(curPos = 7);
        }
        // SHL
        else if ((GetAsyncKeyState(0x39) | GetAsyncKeyState(VK_NUMPAD9)) & 0x1)
        {
            OperatorMenuOptions(curPos = 8);
        }
        // SHR
        else if ((GetAsyncKeyState(0x30) | GetAsyncKeyState(VK_NUMPAD0)) & 0x1)
        {
            OperatorMenuOptions(curPos = 9);
        }

        Sleep(10);
    }
}


void MainMenuOptions(short curPos)
{
    system("cls");
    std::cout << "\t\tCalc Convert\n\nSelect Number of Inputs\n\n";
    switch (curPos)
    {
    case 0:
        std::cout << "1.   ";
        WHITE_BACKGROUND;
        std::cout << "[Input Single Number]\n";
        BLACK_BACKGROUND;
        std::cout << "2.   [Calculate 2 Numbers]\n";
        std::cout << "3.   [EXIT]\n";
        break;
    case 1:
        BLACK_BACKGROUND;
        std::cout << "1.   [Input Single Number]\n2.   ";
        WHITE_BACKGROUND;
        std::cout << "[Calculate 2 Numbers]\n";
        BLACK_BACKGROUND;
        std::cout << "3.   [EXIT]\n";
        break;
    case 2:
        BLACK_BACKGROUND;
        std::cout << "1.   [Input Single Number]\n";
        std::cout << "2.   [Calculate 2 Numbers]\n3.   ";
        WHITE_BACKGROUND;
        std::cout << "[EXIT]\n";
        BLACK_BACKGROUND;
        break;
    default:
        std::cout << "\n\nYou dun goofed somehow\n\n";
    }
}

void SecondMenuOptions(short curPos)
{
    system("cls");
    std::cout << "\t\tCalc Convert\n\nSelect Input Type\n\n";
    // Print menu options
    switch (curPos)
    {
    case 0:
        std::cout << "1.   ";
        WHITE_BACKGROUND;
        std::cout << "[Floating point]\n";
        BLACK_BACKGROUND;
        std::cout << "2.   [Hex]\n";
        std::cout << "3.   [Binary]\n";
        std::cout << "4.   [SEM]\n";
        std::cout << "5.   [Return]\n";
        std::cout << "6.   [EXIT]\n";
        break;
    case 1:
        std::cout << "1.   [Floating point]\n2.   ";
        WHITE_BACKGROUND;
        std::cout << "[Hex]\n";
        BLACK_BACKGROUND;
        std::cout << "3.   [Binary]\n";
        std::cout << "4.   [SEM]\n";
        std::cout << "5.   [Return]\n";
        std::cout << "6.   [EXIT]\n";
        break;
    case 2:
        std::cout << "1.   [Floating point]\n";
        std::cout << "2.   [Hex]\n3.   ";
        WHITE_BACKGROUND;
        std::cout << "[Binary]\n";
        BLACK_BACKGROUND;
        std::cout << "4.   [SEM]\n";
        std::cout << "5.   [Return]\n";
        std::cout << "6.   [EXIT]\n";
        break;
    case 3:
        std::cout << "1.   [Floating point]\n";
        std::cout << "2.   [Hex]\n";
        std::cout << "3.   [Binary]\n4.   ";
        WHITE_BACKGROUND;
        std::cout << "[SEM]\n";
        BLACK_BACKGROUND;
        std::cout << "5.   [Return]\n";
        std::cout << "6.   [EXIT]\n";
        break;
    case 4:
        std::cout << "1.   [Floating point]\n";
        std::cout << "2.   [Hex]\n";
        std::cout << "3.   [Binary]\n";
        std::cout << "4.   [SEM]\n5.   ";
        WHITE_BACKGROUND;
        std::cout << "[Return]\n";
        BLACK_BACKGROUND;
        std::cout << "6.   [EXIT]\n";
        break;
    case 5:
        std::cout << "1.   [Floating point]\n";
        std::cout << "2.   [Hex]\n";
        std::cout << "3.   [Binary]\n";
        std::cout << "4.   [SEM]\n";
        std::cout << "5.   [Return]\n6.   ";
        WHITE_BACKGROUND;
        std::cout << "[EXIT]\n";
        BLACK_BACKGROUND;
        break;
    default:
        std::cout << "\n\nYou dun goofed somehow\n\n";
    }
}

void OperatorMenuOptions(short curPos)
{
    system("cls");
    std::cout << "\t\tCalc Convert\n\nChoose Operation\n\n";
    // Print menu options
    switch (curPos)
    {
    case 0:
        std::cout << "1.   ";
        WHITE_BACKGROUND;
        std::cout << "[Addition]\n";
        BLACK_BACKGROUND;
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 1:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   ";
        WHITE_BACKGROUND;
        std::cout << "[Subtraction]\n";
        BLACK_BACKGROUND;
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 2:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   ";
        WHITE_BACKGROUND;
        std::cout << "[Multiplication]\n";
        BLACK_BACKGROUND;
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 3:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   ";
        WHITE_BACKGROUND;
        std::cout << "[Division]\n";
        BLACK_BACKGROUND;
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 4:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   ";
        WHITE_BACKGROUND;
        std::cout << "[AND]\n";
        BLACK_BACKGROUND;
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 5:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   ";
        WHITE_BACKGROUND;
        std::cout << "[OR]\n";
        BLACK_BACKGROUND;
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 6:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   ";
        WHITE_BACKGROUND;
        std::cout << "[NOR]\n";
        BLACK_BACKGROUND;
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 7:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   ";
        WHITE_BACKGROUND;
        std::cout << "[XOR]\n";
        BLACK_BACKGROUND;
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   [SHR]\n";
        break;
    case 8:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   ";
        WHITE_BACKGROUND;
        std::cout << "[SHL]\n";
        BLACK_BACKGROUND;
        std::cout << "0.   [SHR]\n";
        break;
    case 9:
        std::cout << "1.   [Addition]\n";
        std::cout << "2.   [Subtraction]\n";
        std::cout << "3.   [Multiplication]\n";
        std::cout << "4.   [Division]\n";
        std::cout << "5.   [AND]\n";
        std::cout << "6.   [OR]\n";
        std::cout << "7.   [NOR]\n";
        std::cout << "8.   [XOR]\n";
        std::cout << "9.   [SHL]\n";
        std::cout << "0.   ";
        WHITE_BACKGROUND;
        std::cout << "[SHR]\n";
        BLACK_BACKGROUND;
        break;
    default:
        std::cout << "\n\nYou dun goofed somehow\n\n";
    }
}
void get_hex()
{
    system("cls");
    std::cout << "Please enter a valid Hexadecimal number\n0x";
    std::string input;
    
    std::cin >> input;

    input = "0x" + input;
    bool valid_size = (input.size() == 10) ? true : false;
    bool valid_chars = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (!(isdigit(input.at(i))) && !(std::toupper(input.at(i), std::locale()) == 'A' || std::toupper(input.at(i), std::locale()) == 'B' || std::toupper(input.at(i), std::locale()) == 'C' || std::toupper(input.at(i), std::locale()) == 'D' || std::toupper(input.at(i), std::locale()) == 'E' || std::toupper(input.at(i), std::locale()) == 'F' || std::toupper(input.at(i), std::locale()) == 'X'))
        {
            valid_chars = false;
            break;
        }
    }
    if (valid_size && valid_chars)
    {
        std::cout << "Hex:\t" << input << std::endl;
        std::cout << "Binary:\t" << VC::hex_to_binary(input) << std::endl;
        std::cout << "SEM:\t";
        VC::hex_to_SEM(input);
        std::cout << "\nFloat:\t" << VC::hex_to_float(input) << std::endl;
    }
    else 
    {  
        std::cout << "That is not a valid hexadecimal. Try again." << std::endl;
    }
    system("pause");
    ClearInputs();
}

void get_binary()
{
    system("cls");
    std::cout << "Please enter a valid 32 bit binary number\n=>";
    std::string input;

    std::cin >> input;
    bool valid_size = (input.size() == 32) ? true : false;
    bool valid_chars = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (!(input.at(i) == '0' || input.at(i) == '1'))
        {
            valid_chars = false;
            break;
        }
    }

    if (valid_size && valid_chars)
    {
        std::cout << "Binary:\t" << input << std::endl;
        std::cout << "Hex:\t" << VC::binary_to_hex(std::bitset<32>(input)) << std::endl;
        std::cout << "SEM:\t";
        VC::binary_to_SEM(std::bitset<32>(input));
        std::cout << "Float:\t" << VC::BinaryToFloat(std::bitset<32>(input)) << std::endl;
    }   
    else
    {
        std::cout << "That is not a valid 32-bit binary. Try again." << std::endl;
    }

    system("pause");
    ClearInputs();
}

void get_float()
{
    system("cls");
    std::cout << "Please enter a valid floating point number\n=>";
    std::string input;

    std::cin >> input;
    bool valid_chars = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (!(isdigit(input.at(i)) || input.at(i) == '-' || input.at(i) == '.' || input.at(i) == '+'))
        {
            valid_chars = false;
            break;
        }
    }

    if (valid_chars)
    {
        std::string binary_in = VC::FloatToBinary(std::stof(input));
        std::cout << "Float:\t" << input << std::endl;
        std::cout << "Binary:\t" << binary_in << std::endl;
        std::cout << "SEM:\t";
        VC::binary_to_SEM(std::bitset<32>(binary_in));
        std::cout << "Hex:\t" << VC::binary_to_hex(std::bitset<32>(binary_in)) << std::endl;
    }
    else
    {
        std::cout << "That is not a valid single precision floating point number. Try again." << std::endl;
    }

    system("pause");
    ClearInputs();
}

void get_SEM() 
{



}

// GetAsyncKeyState(KEY) sets LSB if KEY has been pressed since last call.
// This function prevents the next call from being invalid
void ClearInputs()
{
    GetAsyncKeyState(0x31);
    GetAsyncKeyState(VK_NUMPAD1);

    GetAsyncKeyState(0x32);
    GetAsyncKeyState(VK_NUMPAD2);

    GetAsyncKeyState(0x33);
    GetAsyncKeyState(VK_NUMPAD3);

    GetAsyncKeyState(0x34);
    GetAsyncKeyState(VK_NUMPAD4);

    GetAsyncKeyState(0x35);
    GetAsyncKeyState(VK_NUMPAD5);

    GetAsyncKeyState(0x36);
    GetAsyncKeyState(VK_NUMPAD6);

    GetAsyncKeyState(0x37);
    GetAsyncKeyState(VK_NUMPAD7);

    GetAsyncKeyState(0x38);
    GetAsyncKeyState(VK_NUMPAD8);

    GetAsyncKeyState(0x39);
    GetAsyncKeyState(VK_NUMPAD9);

    GetAsyncKeyState(0x30);
    GetAsyncKeyState(VK_NUMPAD0);
}

