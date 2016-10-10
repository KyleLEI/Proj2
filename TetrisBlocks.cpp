//
//  TetrisBlocks.cpp
//  Project2
//
//  Created by Kyle Lei on 26/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisBlocks.h"

void TetrisBlocks::setRandomShape()
{
    qsrand(time(NULL));//TODO: find proper Qt random generator
    setShape(TetrisShape(qrand() % 7 + 1));
}

void TetrisBlocks::setShape(TetrisShape shape)
{
    static const int coordsTable[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },//default
	{ { 0, 1 },   { 0, 0 },   { 1, 0 },   { 1, -1 } },//SShape
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },//ZShape
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },//LineShape
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },//Tshape
	{ { 0, 0 },   { 0, -1},   { -1, 0 },  { -1, -1} },//SquareShape
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },//MirroredLShapre
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }//LShape
    };
    
    static const Qt::GlobalColor colorTable[8]={
        Qt::GlobalColor::transparent,Qt::GlobalColor::blue,Qt::GlobalColor::yellow,Qt::GlobalColor::red,
            Qt::GlobalColor::magenta,Qt::GlobalColor::green,Qt::GlobalColor::darkYellow,
            Qt::GlobalColor::cyan};

    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[shape][i][j];
    }
    t_color=colorTable[shape];
    blockShape = shape;
}

int TetrisBlocks::minX() const
{
    int min = coords[0][0];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][0]);
    return min;
}

int TetrisBlocks::maxX() const
{
    int max = coords[0][0];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][0]);
    return max;
}

int TetrisBlocks::minY() const
{
    int min = coords[0][1];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][1]);
    return min;
}

int TetrisBlocks::maxY() const
{
    int max = coords[0][1];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][1]);
    return max;
}

TetrisBlocks TetrisBlocks::rotatedLeft() const
{
    TetrisBlocks result;
    result.setShape(this->blockShape);
    for (int i = 0; i < 4; ++i) {
        result.setX(i, y(i));
        result.setY(i, -x(i));
    }
    return result;
}

TetrisBlocks TetrisBlocks::rotatedRight() const
{
    TetrisBlocks result;
    result.setShape(this->blockShape);
    for (int i = 0; i < 4; ++i) {
        result.setX(i, -y(i));
        result.setY(i, x(i));
    }
    return result;
}
