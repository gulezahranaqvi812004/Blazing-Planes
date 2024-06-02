#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void print_maze();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

// header
void interfaceOfGame();
void header();
void functionality();
int interface_of_game();
void key_details();
void instructions();
// Player functionality
void printPlayer();
void erase();
void movePlayer();
void moveRight();
void moveLeft();
void moveUp();
void moveDown();

// Bullet functionality
void makeBulletInactive(int index);
void eraseBullet(int x, int y);
void printBullet(int x, int y);
void moveBullet();
void generateBullet();

// Enemy functions
void printEnemy1(int x, int y);
void eraseEnemy1(int x, int y);
void printEnemy2(int x, int y);
void printEnemy3(int x, int y);
void motion1();

// Global data for player

int playerX = 29;
int playerY = 8;

// Global data for bullet
int bulletX[100];
int bulletY[100];
int bulletCount = 0;
bool isBulletActive[100];
// Enemy 1

string direction1 = "left";
int enemy1X = 45;
int enemy1Y = 4;
void moveEnemy1();

// 2nd enemy

void eraseEnemy2(int x, int y);
string direction2 = "right";
int enemy2X = 45;
int enemy2Y = 10;
void moveEnemy2();

// Enemy 3
int enemy3X = 47;
int enemy3Y = 30;
void moveEnemy3();

// detection
void bulletCollisionWithEnemy();
void addScore();
void printScore();
int score = 0;
main()
{
    system("cls");
    header();

    int choice = -1;
    while (choice < 4)
    {
        choice = interface_of_game();
        if (choice == 1)
        {
            key_details();
        }
        if (choice == 2)
        {
            instructions();
        }
        else if (choice == 3)
        {
            system("cls");
            print_maze();
            movePlayer();
        }
    }
    system("cls");
    //    print_maze();

    // printEnemy2(enemy2X, enemy2Y);
    // printEnemy3(enemy3X, enemy3Y);
    printPlayer();
    // Sleep(500);
    // erase(playerX, playerY);
    // print(playerX + 12, playerY + 12);
    // movePlayer();
}
void print_maze()
{
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%                                                                                                              % " << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl;
}
void movePlayer()
{
    bool gameRunning = true;
    printPlayer();
    printEnemy1(enemy1X, enemy1Y);
    printEnemy2(enemy2X, enemy2Y);
    while (gameRunning == true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }

        bulletCollisionWithEnemy();
        printScore();
        moveBullet();
        moveEnemy1();
        moveEnemy2();
        moveEnemy3();
        
        Sleep(200);
    }
}
void moveEnemy1()
{

    if (direction1 == "left")
    {
        char nextLoaction1 = getCharAtxy(enemy1X - 1, enemy1Y);
        char nextLoaction2 = getCharAtxy(enemy1X - 1, enemy1Y + 1);
        char nextLoaction3 = getCharAtxy(enemy1X - 1, enemy1Y + 2);
        if (nextLoaction1 == ' '|| nextLoaction1 == '.' && nextLoaction2 == ' '||nextLoaction2 == '.'  && nextLoaction3 == ' '||nextLoaction2 == '.' )
        {
            eraseEnemy1(enemy1X, enemy1Y);
            enemy1X--;
            printEnemy1(enemy1X, enemy1Y);
        }
        else
        {
            direction1 = "right";
        }
    }
    if (direction1 == "right")
    {

        char nextLoaction1 = getCharAtxy(enemy1X + 7, enemy1Y);
        char nextLoaction2 = getCharAtxy(enemy1X + 7, enemy1Y + 1);
        char nextLoaction3 = getCharAtxy(enemy1X + 7, enemy1Y + 2);
        if (nextLoaction1 == ' '|| nextLoaction1 == '.' && nextLoaction2 == ' '||nextLoaction2 == '.'  && nextLoaction3 == ' '||nextLoaction2 == '.' )
        {
            eraseEnemy1(enemy1X, enemy1Y);
            enemy1X++;
            printEnemy1(enemy1X, enemy1Y);
        }
        else
        {
            direction1 = "left";
        }
    }
}
void moveEnemy2()
{

    if (direction2 == "left")
    {
        char nextLoaction1 = getCharAtxy(enemy2X - 1, enemy2Y);
        char nextLoaction2 = getCharAtxy(enemy2X - 1, enemy2Y + 1);
        char nextLoaction3 = getCharAtxy(enemy2X - 1, enemy2Y + 2);
        if (nextLoaction1 == ' ' && nextLoaction2 == ' ' && nextLoaction3 == ' ')
        {
            eraseEnemy2(enemy2X, enemy2Y);
            enemy2X--;
            printEnemy2(enemy2X, enemy2Y);
        }
        else
        {
            direction2 = "right";
        }
    }
    if (direction2 == "right")
    {

        char nextLoaction1 = getCharAtxy(enemy2X + 7, enemy2Y);
        char nextLoaction2 = getCharAtxy(enemy2X + 7, enemy2Y + 1);
        char nextLoaction3 = getCharAtxy(enemy2X + 7, enemy2Y + 2);
        if (nextLoaction1 == ' ' && nextLoaction2 == ' ' && nextLoaction3 == ' ')
        {
            eraseEnemy2(enemy2X, enemy2Y);
            enemy2X++;
            printEnemy2(enemy2X, enemy2Y);
        }
        else
        {
            direction2 = "left";
        }
    }
}
void moveEnemy3()
{
    printEnemy3(enemy3X, enemy3Y);

    string direction3 = "right";
    if (direction3 == "right")
    {
        char nextLoaction3 = getCharAtxy(enemy3X - 1, enemy3Y);

        if (nextLoaction3 == ' ')
        {
            gotoxy(enemy3X, enemy3Y);
            cout << "       ";
            gotoxy(enemy3X, enemy3Y + 1);
            cout << "       ";
            gotoxy(enemy3X, enemy3Y + 2);
            cout << "       ";
            enemy3X--;
            printEnemy3(enemy3X, enemy3Y);
        }
        else
        {
            direction3 = "left";
        }
    }
    if (direction3 == "left")
    {

        char nextLoaction = getCharAtxy(enemy3X + 6, enemy3Y);
        if (nextLoaction == ' ')

        {
            gotoxy(enemy3X, enemy3Y);
            cout << "       ";
            gotoxy(enemy3X, enemy3Y + 1);
            cout << "       ";
            gotoxy(enemy3X, enemy3Y + 2);
            cout << "           ";
            enemy3X = enemy3X + 60;
            printEnemy1(enemy3X, enemy3Y);
        }
        else
        {
            direction3 = "right";
        }
    }
}
void generateBullet()
{
    bulletX[bulletCount] = playerX + 12;
    bulletY[bulletCount] = playerY + 1;
    isBulletActive[bulletCount] = true;
    gotoxy(playerX + 12, playerY + 1);
    cout << ".";
    bulletCount++;
}
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletInactive(int index)
{
    isBulletActive[index] = false;
}
void printPlayer()
{
    int x = playerX;
    int y = playerY;
    char playerUpper[12] = {'.', '.', '.', '|', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char playerMiddle[12] = {' ', ' ', ' ', ' ', '|', ' ', '|', '>', '>', '>', '>', '>'};
    char playerLower[12] = {'.', '.', '.', '|', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    gotoxy(x, y);
    // cout << "P";
    for (int index = 0; index < 12; index++)
    {
        cout << playerUpper[index];
    }
    gotoxy(x, y + 1);
    for (int index = 0; index < 12; index++)
    {
        cout << playerMiddle[index];
    }
    gotoxy(x, y + 2);
    for (int index = 0; index < 12; index++)
    {
        cout << playerLower[index];
    }
}
void erase()
{
    int x = playerX;
    int y = playerY;
    gotoxy(x, y);
    for (int x = 0; x < 12; x++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int x = 0; x < 12; x++)
    {
        cout << " ";
    }
    gotoxy(x, y + 2);
    for (int x = 0; x < 12; x++)
    {
        cout << " ";
    }
}
void moveRight()
{
    char nextLocation = getCharAtxy(playerX + 12, playerY);
    if (nextLocation == ' ')
    {
        erase();
        playerX = playerX + 1;
        printPlayer();
    }
}
void moveLeft()
{
    char nextLocation = getCharAtxy(playerX - 1, playerY);
    if (nextLocation == ' ')
    {
        erase();
        playerX = playerX - 1;
        printPlayer();
    }
}
void moveUp()
{
    char nextLocation = getCharAtxy(playerX, playerY - 1);
    if (nextLocation == ' ')
    {
        erase();
        playerY = playerY - 1;
        printPlayer();
    }
}
void moveDown()
{
    char nextLocation = getCharAtxy(playerX, playerY + 3);
    if (nextLocation == ' ')
    {
        erase();
        playerY = playerY + 1;
        printPlayer();
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void bulletCollisionWithEnemy()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 1 || bulletY[x] == enemy1Y + 2 || bulletY[x] == enemy1Y + 3))
            {
                score++;
                
            }
            if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 1 || bulletY[x] == enemy2Y + 2 || bulletY[x] == enemy2Y + 3))
            {
                score++;
            }
        }
    }
}
void addScore()
{
    score++;
}
void printScore()
{
    gotoxy(150, 10);
    cout << "Score : " << score;
}
void printEnemy1(int x, int y)
{

    char a = 178;
    char b = 221;
    char enemy1upper[7] = {' ', ' ', b, b, b, ' ', ' '};
    char enemy1middle[7] = {':', a, a, a, a, a, a};

    gotoxy(x, y);
    for (int index = 0; index < 7; index++)
    {
        cout << enemy1upper[index];
    }
    gotoxy(x, y + 1);
    for (int index = 0; index < 7; index++)
    {
        cout << enemy1middle[index];
    }
    gotoxy(x, y + 2);
    for (int index = 0; index < 7; index++)
    {
        cout << enemy1upper[index];
    }
}
void eraseEnemy1(int x, int y)
{
    gotoxy(x, y);
    for (int x = 0; x < 7; x++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int x = 0; x < 7; x++)
    {
        cout << " ";
    }
    gotoxy(x, y + 2);
    for (int x = 0; x < 7; x++)
    {
        cout << " ";
    }
}
void printEnemy2(int x, int y)
{
    char enemy2upper[7] = {' ', ' ', '[', ']', ' ', ' ', ' '};
    char enemy2middle[7] = {'[', ']', '[', 'x', ']', '[', ']'};
    char enemy2lower[7] = {' ', ' ', '[', ']', ' ', ' ', ' '};
    gotoxy(x, y);
    for (int index = 0; index < 7; index++)
    {
        cout << enemy2upper[index];
    }
    gotoxy(x, y + 1);
    for (int index = 0; index < 7; index++)
    {
        cout << enemy2middle[index];
    }
    gotoxy(x, y + 2);
    for (int index = 0; index < 7; index++)
    {
        cout << enemy2lower[index];
    }
}
void eraseEnemy2(int x, int y)
{
    gotoxy(x, y);
    for (int index = 0; index < 7; index++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int index = 0; index < 7; index++)
    {
        cout << " ";
    }
    gotoxy(x, y + 2);
    for (int index = 0; index < 7; index++)
    {
        cout << " ";
    }
}
void printEnemy3(int x, int y)
{

    char a = 178;
    char b = 174;
    char enemy3upper[8] = {' ', b, b};
    char enemy3middle[8] = {':', a, a, a, a, a};
    char enemy3lower[8] = {
        ' ',
        b,
        b,
    };

    gotoxy(x, y);
    for (int i = 0; i < 8; i++)
    {
        cout << enemy3upper[i];
    }
    gotoxy(x, y + 1);
    for (int i = 0; i < 8; i++)
    {
        cout << enemy3middle[i];
    }
    gotoxy(x, y + 2);
    for (int i = 0; i < 8; i++)
    {
        cout << enemy3lower[i];
    }
}
// void interfaceOfGame()
// {
//     functionality();
// }
void header()
{
    cout << "  ____              _                _____   _  " << endl;
    cout << "  |  _ \\||         (_)              |  __ \\ | | " << endl;
    cout << "  | |_) | | __ _ _____ _ __   __ _  | |__)  | | " << endl;
    cout << "  |  _ <| |/ _` |_  | | '_ \\ / _` | |  ___/ | |/ _` |  '_\\ / _ \\" << endl;
    cout << "  | |_) | | (_| |/ /| | | | | (_| | | |     | | (_| | | | | __/" << endl;
    cout << "  |____/ |_|\\__,_/__|_|_| |_|\\__, | |_|     |_|\\__,_|_| |_|\\___|" << endl;
    cout << "                              __/ |                     " << endl;
    cout << "                              |___/   " << endl;
}
// void functionality()
// {
//     int choice = -1;
//     while (choice < 4)
//     {
//         choice = interface_of_game();
//         if (choice == 1)
//         {
//             key_details();
//         }
//         if (choice == 2)
//         {
//             instructions();
//         }
//         else if (choice == 3)
//         {
//             break;
//         }
//     }
// }
int interface_of_game()
{
    int choice = 3;
    cout << "__________LOGIN MENU______________" << endl;
    cout << "Press 1 to see the details of keys" << endl;
    cout << "Press 2 to see instruction" << endl;
    cout << "Press 3 to continue to game" << endl;
    cout << "Press 4 to exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << choice;
    return choice;
}
void key_details()

{
    cout << "__________________KEY DETAILS_____________" << endl;
    cout << "Press arrow key up to move up" << endl;
    cout << "Press arrow key down to move down" << endl;
    cout << "Press arrow key right to move right" << endl;
    cout << "Press arrow key left to left up" << endl;
    cout << "Press space bar up to fire" << endl;
    cout << "Press any key to continue to the game: ";
    getch();
    cout << endl;
    // interface_of_game();
}
void instructions()
{
    cout << "_________________GAME INSTRUCTIONS____________" << endl;
    cout << "You have 3 lifes in the game and each health consist of 100 point" << endl;
    cout << "Score decreases by 5 by striking with the plane of enemy or due to the fire of enemy" << endl;
    cout << "Game will be over if player loses his all life" << endl;
    cout << "Hope you understand all the instructions." << endl;
    cout << "Press any key to continue to the game: ";
    getch();
    cout << endl;
    // interface_of_game();
}

// back ups

//     gotoxy(playerX + 12, playerY + 1);
//     cout << ".";
// }
// for (int y = 0; y < 50; y++)
// {
//     for (int x = 150; x > 0; x--)
//     {
//         if (getCharAtxy(x, y) == '.')
//         {
//             if (getCharAtxy(x + 1, y) == ' ')
//             {
//                 gotoxy(x, y);
//                 cout << " ";
//                 gotoxy(x + 1, y);
//                 cout << ".";
//             }
//             else if (getCharAtxy(x + 1, y) != ' ')
//             {
//                 gotoxy(x, y);
//                 cout << " ";
//             }
//         }
//     }