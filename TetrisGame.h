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

#include <QtWidgets/QWidget>
#include <QtCore/QtCore>

#include "TetrisBlocks.h"

class TetrisBlocks;

enum op{t_left=0,t_right,t_down,t_cw,t_acw};

class TetrisGame:public QWidget{
public:
    TetrisGame();
    
    void start();
    void move(op);
    
    int getLevel() const{return level;}
    int getScore() const{return score;}
    
    TetrisBlocks getNextBlock() const{return nxt_blk;}
    Qt::GlobalColor getMap(int x,int y) const {return map[x][y];}//return the color to window class
//private:
    enum {T_WIDTH=10,T_HEIGHT=20};
    QBasicTimer* timer;
    
    Qt::GlobalColor map[T_WIDTH][T_HEIGHT];//record the color of each block on the game board
    
    TetrisBlocks cur_blk;
    TetrisBlocks nxt_blk;
    inline void new_blk();
    
    bool isStarted;
    int level;
    int score;
    
    int x,y;
    
    inline bool check_clearance(int,int,TetrisBlocks);
    inline void check_and_clear_row();
    inline void clear_blk(TetrisBlocks m_blk);//set all blocks covered by blk to transparent
    inline void set_blk(TetrisBlocks m_blk);//set all blocks covered by cur_blk to its color
    inline void clear_all();
    void move_down();
    void move_LR(op);
    void rotate(op);
    
protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    

};

#endif /* TetrisGame_h */
