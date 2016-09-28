//
//  TetrisBlocks.h
//  Project2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#ifndef TetrisBlocks_h
#define TetrisBlocks_h

#include <QtCore/QtGlobal>

enum TetrisShape { NoShape, ZShape, SShape, LineShape, TShape, SquareShape,
                   LShape, MirroredLShape };

class TetrisBlocks
{
public:
    TetrisBlocks() { setShape(NoShape); }

    void setRandomShape();
    void setShape(TetrisShape shape);

    TetrisShape shape() const { return pieceShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;
    TetrisBlocks rotatedLeft() const;
    TetrisBlocks rotatedRight() const;

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    TetrisShape pieceShape;
    int coords[4][2];
};

#endif /* TetrisBlocks_h */
