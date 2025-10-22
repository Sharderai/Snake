#ifndef TILE_H
#define TILE_H

#include <windows.h>

class Tile {
    public:
        Tile(int, long, long, COLORREF, int);
        RECT getTile();
        COLORREF getColor();
        void changeColor(COLORREF);
        int getID();
        void changeID(int);
    private:
        RECT tile;
        COLORREF tileColor;
        int tileID;
        long locX;
        long locY;
};

Tile::Tile(int size, long x, long y, COLORREF color, int ID) {
    locX = x;
    locY = y;
    tileColor = color;
    tileID = ID;

    tile.left = locX;
    tile.top = locY;
    tile.right = locX + size;
    tile.bottom = locY + size;
}


RECT Tile::getTile() {
    return tile;
}


COLORREF Tile::getColor() {
    return tileColor;
}


void Tile::changeColor(COLORREF newColor) {
    tileColor = newColor;
}


int Tile::getID() {
    return tileID;
}


void Tile::changeID(int newID) {
    tileID = newID;
}

#endif