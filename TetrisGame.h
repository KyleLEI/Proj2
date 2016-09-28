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
    
    int getLevel() const;
    int getScore() const;
    
private:
    enum {T_WIDTH=10,T_HEIGHT=20};
    QBasicTimer timer;
    
    bool map[T_WIDTH][T_HEIGHT];//record which block has been taken
    
    TetrisBlocks cur_blk;
    TetrisBlocks nxt_blk;
    
    bool isStarted;
    
    int level;
    int score;
};

#endif /* TetrisGame_h */
