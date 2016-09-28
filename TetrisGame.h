//
//  TetrisGame.h
//  Project2
//  internal logic of the game
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#ifndef TetrisGame_h
#define TetrisGame_h

#include <QtCore/QBasicTimer>
#include "TetrisBlocks.h"

class TetrisBlocks;

enum op{left=0,right,down,cw,acw};

class TetrisGame{
public:
    TetrisGame();
    
    void move(op);
    
    int getLevel() const{return level;}
    int getScore() const{return score;}
    
    TetrisBlocks getNextBlock() const{return nxt_blk;}
    Qt::GlobalColor getMap(int x,int y) const;//return the color to window class
    
private:
    enum {T_WIDTH=10,T_HEIGHT=20};
    QBasicTimer timer;
    
    Qt::GlobalColor map[T_WIDTH][T_HEIGHT];//record the color of each block on the game board
    
    TetrisBlocks cur_blk;
    TetrisBlocks nxt_blk;
    
    bool isStarted;
    int level;
    int score;
    
    void refresh();
};

#endif /* TetrisGame_h */
