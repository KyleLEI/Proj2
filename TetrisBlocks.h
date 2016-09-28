//
//  TetrisBlocks.h
//  Project2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#ifndef TetrisBlocks_h
#define TetrisBlocks_h

#include <QtCore/qnamespace.h>//for Qt::GlobalColor
#include <stdlib.h>

enum TetrisShape { NoShape=0, ZShape, SShape, LineShape, TShape, SquareShape,
                   LShape, MirroredLShape };

enum TetrisColor{};
class TetrisBlocks
{
public:
    TetrisBlocks(TetrisShape shape=NoShape) { setShape(shape); }

    void setRandomShape();
    void setShape(TetrisShape shape);

    TetrisShape shape() const { return blockShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;
    TetrisBlocks rotatedLeft() const;
    TetrisBlocks rotatedRight() const;
    
    int getColor() const {return color;}

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    TetrisShape blockShape;
    int coords[4][2];//[block num][x/y]
    int color;
};

#endif /* TetrisBlocks_h */
