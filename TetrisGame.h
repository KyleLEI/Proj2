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
    
    /*------operation handlers------*/
    void start();//start the game (internal timer)
    void move(op);//handle block movement
    
    /*-----"get" functions------*/
    int getLevel() const{return level;}
    int getScore() const{return score;}
    TetrisBlocks getNextBlock() const{return nxt_blk;}
    Qt::GlobalColor getMap(int x,int y) const {return map[x][y];}//return the color to caller
    
    enum {T_WIDTH=10,T_HEIGHT=20};//define board size, not using evil #define
    
private:
    QBasicTimer* timer;
    
    Qt::GlobalColor map[T_WIDTH][T_HEIGHT];//record the color of each block on the game board
    
    TetrisBlocks cur_blk;
    TetrisBlocks nxt_blk;
    
    int x,y;//position of current block
    inline void setX(int m_x){this->x=m_x;}
    inline void setY(int m_y){this->y=m_y;}
    inline void new_blk();
    
    //set all blocks covered by blk to transparent
    inline void clear_blk(TetrisBlocks m_blk){
        for (int i=0;i<4;++i)
            map[x+m_blk.x(i)][y+m_blk.y(i)]=Qt::GlobalColor::transparent;
    }
    
    //set all blocks covered by cur_blk to its color
    inline void set_blk(TetrisBlocks m_blk){
        for (int i=0;i<4;++i)
            map[x+m_blk.x(i)][y+m_blk.y(i)]=m_blk.getColor();
    }
    
    //set all blocks on the board transparent
    inline void clear_all(){
        for(size_t w=0;w<T_WIDTH;++w){
            for(size_t h=0;h<T_HEIGHT;++h)
                map[w][h]=Qt::GlobalColor::transparent;//transparent means empty
        }
    }
    
    bool isStarted;
    int level;
    int score;
    
    inline bool check_clearance(int,int,TetrisBlocks,TetrisBlocks);//used for block change checking
    inline bool check_clearance(TetrisBlocks);//used for block spawn checking
    inline void check_and_clear_row();
    void move_down();
    void move_LR(op);
    void rotate(op);
    
protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

};

#endif /* TetrisGame_h */
