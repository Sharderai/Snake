#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <random>
#include <ctime>
#include <thread>

#include "player.h"
#include "field.h"
#include "points.h"

#include "typeNoMovement.h"
#include "typeFollowingMovement.h"

#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Gdi32.lib")

field gameField(30,20);
player character(0,0);
points activePoint(10, 10, std::make_shared<typeNoMovement>(typeNoMovement()), nullptr);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void moveLoop(HWND hwnd);
void collisionCheck();
void createPoint(points&, int, int);
void moveTail();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[]  = L"this window";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Test Window",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // position x, position y, width, height
        600, 300, 766, 539,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    gameField.updateTile(character.getX(), character.getY(), character.getColor(), character.getID());
    createPoint(activePoint, activePoint.getX(), activePoint.getY());
    
    ShowWindow(hwnd, nCmdShow);
    std::thread move(moveLoop, hwnd);
    move.detach();

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            gameField.paintField(hwnd, hdc);

            EndPaint(hwnd, &ps);
            return 0;
        }

    case WM_KEYDOWN:
        {
            character.changeDirection(wParam);
            return 0;
        }

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


//thread to keep the snake moving
void moveLoop(HWND hwnd) {
        while (character.checkPlayState() == true) {
            object* target = character.getTail();

            //resets field color
            if (target == nullptr) {
                gameField.updateTile(character.getX(), character.getY(), gameField.getColor(), gameField.getID());
            }
            else {
                gameField.updateTile(character.getX(), character.getY(), target->getColor(), target->getID());
                gameField.updateTile(target->getX(), target->getY(), gameField.getColor(), gameField.getID());
            }
            collisionCheck();
            moveTail();
            gameField.updateTile(activePoint.getX(), activePoint.getY(), activePoint.getColor(), activePoint.getID());

            character.move(gameField.getX(), gameField.getY());
            if (gameField.getTile(character.getX(), character.getY()).getID() == 2) {
               character.lose();
            }

            gameField.updateTile(character.getX(), character.getY(), character.getColor(), character.getID());
            InvalidateRect(hwnd, NULL, TRUE);
            UpdateWindow(hwnd);

            Sleep(50);
        }
}


//checks for collision with active point
void collisionCheck() {
    if (character.getX() == activePoint.getX() && character.getY() == activePoint.getY()) {
        points* tailSeg = new points(activePoint.getX(), activePoint.getY(), std::make_shared<typeNoMovement>(typeNoMovement()), nullptr);
        object* head = &character;
        activePoint.collect(nullptr);

        if (!character.firstPoint()) {
            tailSeg->collect(character.getTail());
            gameField.updateTile(tailSeg->getX(), tailSeg->getY(), tailSeg->getColor(), gameField.getID());
        }
        else {
            tailSeg->collect(head);
        }

        character.collect(tailSeg);
        createPoint(activePoint, gameField.getX(), gameField.getY());
    }
}


void createPoint(points& activePoint, int limitX, int limitY) {
    if (activePoint.checkFollowing()) {
        std::srand(std::time(nullptr));
        int x = std::rand() % (limitX - 1);
        int y = std::rand() % (limitY - 1);
        points p(x, y, std::make_shared<typeNoMovement>(typeNoMovement()), nullptr);
        activePoint = p;
        activePoint.resetIdentity();
    }
    gameField.updateTile(activePoint.getX(), activePoint.getY(), activePoint.getColor(), activePoint.getID());
}


void moveTail() {
    object* temp = character.getTail();
    while (temp != nullptr && temp->following != nullptr) {
        temp->move(gameField.getX(), gameField.getY());
        gameField.updateTile(temp->getX(), temp->getY(), temp->getColor(), temp->getID());
        temp = temp->following;
    }
}