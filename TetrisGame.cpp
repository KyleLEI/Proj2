//
//  TetrisGame.cpp
//  Project2
//
//  Created by Kyle Lei on 26/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisGame.h"

TetrisGame::TetrisGame():isStarted(false),level(1),score(0),x(T_WIDTH/2),y(T_HEIGHT-1){
    srand(time(NULL));
    clear_all();
    set_cur();
    timer=new QBasicTimer;
}

void TetrisGame::start(){
    if(!isStarted)
        timer->start(1000 - (level -1)*100, this);
}

void TetrisGame::move(op m_op){
    switch (m_op) {
        case t_left:
            move_LR(m_op);
            break;
            
        case t_right:
            move_LR(m_op);
            break;
            
        case t_down:
            move_down();
            break;
            
        case t_cw:
        case t_acw:
            rotate(m_op);
            break;
            
        default:
            break;
    }
}

void TetrisGame::timerEvent(QTimerEvent *event){
    if(event->timerId()==timer->timerId()){
        check_and_clear_row();
        move_down();
        timer->start(1000 - (level -1)*100, this);
    }else{
        QWidget::timerEvent(event);
    }
}

inline void TetrisGame::new_blk(){
    cur_blk=nxt_blk;
    nxt_blk.setRandomShape();
    x=T_WIDTH/2; y=T_HEIGHT;
    if(!check_clearance(x, y, cur_blk)){
        timer->stop();//game over
        return;
    }
    set_cur();
}

inline bool TetrisGame::check_clearance(int m_x,int m_y,TetrisBlocks m_blk){
    for (int i=0;i<4;i++){
        if(map[m_x+m_blk.x(i)][m_y+m_blk.y(i)]!=Qt::GlobalColor::transparent)
            return false;
    }
    return true;
}

inline void TetrisGame::check_and_clear_row(){
    for(size_t x=0;x<T_WIDTH;x++)
        if(map[x][0]!=Qt::GlobalColor::transparent)
            return;//check if bottom row is all transparent
    
    for(size_t x=0;x<T_WIDTH-1;x++)
        for(size_t y=0;y<T_HEIGHT;y++){
            map[x][y]=map[x][y+1];
            map[x][y+1]=Qt::GlobalColor::transparent;
        }
}

inline void TetrisGame::clear_cur(){
    for (int i=0;i<4;i++)
        map[x+cur_blk.x(i)][y+cur_blk.y(i)]=Qt::GlobalColor::transparent;
}

inline void TetrisGame::set_cur(){
    for (int i=0;i<4;i++)
        map[x+cur_blk.x(i)][y+cur_blk.y(i)]=cur_blk.getColor();
}

inline void TetrisGame::clear_all(){
    for(size_t w=0;w<T_WIDTH;w++){
        for(size_t h=0;h<T_HEIGHT;h++)
            map[w][h]=Qt::GlobalColor::transparent;//transparent means empty
    }
}

void TetrisGame::move_LR(op m_op){
    if(cur_blk.minX()-1>=0&&cur_blk.maxX()+1<T_WIDTH){
        if(m_op==t_left){
            if(check_clearance(x-1, y, cur_blk)){
                clear_cur();
                x--;
                set_cur();
            }
        }
        else {
            if(check_clearance(x+1, y, cur_blk)){
                clear_cur();
                x++;
                set_cur();
            }
        }
    }
}

void TetrisGame::move_down(){
    if(!check_clearance(x, y-1, cur_blk)){
        new_blk();
    }else{
        clear_cur();
        y--;
        set_cur();
    }
}

void TetrisGame::rotate(op m_op){
    if(m_op==t_cw){
        if(check_clearance(x, y, cur_blk.rotatedRight())){
            clear_cur();
            cur_blk=cur_blk.rotatedRight();
            set_cur();
        }
    }else{
        if(check_clearance(x, y, cur_blk.rotatedLeft())){
            clear_cur();
            cur_blk=cur_blk.rotatedLeft();
            set_cur();
        }
    }
}

