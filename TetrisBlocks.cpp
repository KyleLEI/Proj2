//
//  TetrisBlocks.cpp
//  Project2
//
//  Created by Kyle Lei on 26/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisBlocks.h"

#include <QtCore>

#include <stdlib.h>

void TetrixBlock::setRandomShape()
{
    setShape(TetrixShape(qrand() % 7 + 1));
}

void TetrixBlock::setShape(TetrixShape shape)
{
    static const int coordsTable[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },//default
       // { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },
	{ { 0, 1 },   { 0, 0 },   { 1, 0 },   { 1, -1 } },//SShape
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },//ZShape
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },//LineShape
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },//Tshape	
      //  { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
	{ { 0, 0 },   { 0, -1},   { -1, 0 },  { -1, -1} },//SquareShape
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },//MirroredLShapre
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }//LShape
    };

    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[shape][i][j];
    }
    pieceShape = shape;
}

int TetrixBlock::minX() const
{
    int min = coords[0][0];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][0]);
    return min;
}

int TetrixBlock::maxX() const
{
    int max = coords[0][0];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][0]);
    return max;
}

int TetrixBlock::minY() const
{
    int min = coords[0][1];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][1]);
    return min;
}

int TetrixBlock::maxY() const
{
    int max = coords[0][1];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][1]);
    return max;
}

TetrixBlock TetrixBlock::rotatedLeft() const
{
    if (pieceShape == SquareShape)
        return *this;

    TetrixBlock result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, y(i));
        result.setY(i, -x(i));
    }
    return result;
}

TetrixBlock TetrixBlock::rotatedRight() const
{
    if (pieceShape == SquareShape)
        return *this;

    TetrixBlock result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, -y(i));
        result.setY(i, x(i));
    }
    return result;
}
