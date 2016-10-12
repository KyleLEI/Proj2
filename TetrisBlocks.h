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
//#include <time.h>

enum TetrisShape { NoShape=0, ZShape, SShape, LineShape, TShape, SquareShape,
                   LShape, MirroredLShape };

class TetrisBlocks
{
public:
    /*Construct TetrisBlock*/
    TetrisBlocks(){qsrand(time(NULL));}

    void setRandomShape();
    void setShape(TetrisShape shape);

    TetrisShape shape() const { return blockShape; } //Return Block shape

    /*Function to return the coordinates of square at index in the block*/
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }


    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;

    TetrisBlocks rotatedLeft() const;
    TetrisBlocks rotatedRight() const;
    
    Qt::GlobalColor getColor() const {return t_color;}

private:
    /*Functions to modify the coordinates of square at index in the block*/
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    TetrisShape blockShape;
    int coords[4][2]; //[Square num][x/y] Since each block contains 4 square, 
                    //and each square has its own x, y value
    Qt::GlobalColor t_color;
};

#endif /* TetrisBlocks_h */
