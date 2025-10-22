#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <windows.h>
#include "Tile.h"

class field {
    public:
        field(int, int);
        void paintField(HWND, HDC);
        RECT getField();
        long getX();
        long getY();
        COLORREF getColor();
        int getID();
        void updateTile(int, int, COLORREF, int);
        Tile getTile(int, int);
    private:
        int sizeX;
        int sizeY;
        int gridSize = 25;
        RECT gridRect;
        std::vector<std::vector<Tile>> grid;
        COLORREF color = RGB(150, 30, 180);
        int ID = 0;
};

field::field(const int x,const  int y) {
    sizeX = x;
    sizeY = y;

    gridRect.left = 0;
    gridRect.top = 0;
    gridRect.right = (sizeX * gridSize);
    gridRect.bottom = (sizeY * gridSize);

    grid.resize(sizeX);
    for (int row = 0; row < sizeX; row++) {
        for (int col = 0; col < sizeY; col++) {
            grid[row].push_back(Tile(gridSize, (row * gridSize), (col * gridSize), color, ID));
        }
    }
}


void field::paintField(HWND hwnd, HDC hdc) {
    for (int row = 0; row < sizeX; row++) {
        for (int col = 0; col < sizeY; col++) {
            HBRUSH tileColor = CreateSolidBrush(grid[row][col].getColor());
            FillRect(hdc, &grid[row][col].getTile(), tileColor);
            DeleteObject(tileColor);
        }
    }
    UpdateWindow(hwnd);
}


RECT field::getField() {
    return gridRect;
}


long field::getX() {
    return (long)(sizeX);
}


long field::getY() {
    return (long)(sizeY);
}


COLORREF field::getColor() {
    return color;
}


int field::getID() {
    return ID;
}


void field::updateTile(int x, int y, COLORREF tileColor, int tileID) {
    grid[x][y].changeColor(tileColor);
    grid[x][y].changeID(tileID);
}


Tile field::getTile(int x, int y) {
    return grid[x][y];
}

#endif