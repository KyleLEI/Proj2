//
//  TetrisGame.cpp
//  Project2
//
//  Created by Kyle Lei on 26/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisGame.h"

TetrisGame::TetrisGame():x(T_WIDTH/2),y(T_HEIGHT-3),isStarted(false),level(1),score(0){
    cur_blk.setRandomShape();
    nxt_blk.setRandomShape();
    clear_all();
    timer=new QBasicTimer;
}

void TetrisGame::start(){
    if(!isStarted){
        new_blk();
        timer->start(1000 - (level -1)*100, this);
        isStarted=true;
    }
}

void TetrisGame::move(op m_op){
    switch (m_op) {
        case t_left:
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
        move_down();
        check_and_clear_row();
        timer->start(1000 - (level -1)*100, this);
    }else{
        QWidget::timerEvent(event);
    }
}

inline void TetrisGame::new_blk(){
    cur_blk=nxt_blk;
    nxt_blk.setRandomShape();
    setX(T_WIDTH/2); setY(T_HEIGHT-3);
    if(!check_clearance(cur_blk)){//game over
        level=1;
        score=0;
        clear_all();
    }
    set_blk(cur_blk);
}

inline bool TetrisGame::check_clearance(int m_x,int m_y,TetrisBlocks m_blk,TetrisBlocks pre_blk){
    clear_blk(pre_blk);//remove itself before  checking
    if(m_x+m_blk.maxX()>=T_WIDTH||m_x+m_blk.minX()<0){//check boundary and prevent segfault
        set_blk(pre_blk);
        return false;
    }
    for (int i=0;i<4;i++){
        if(map[m_x+m_blk.x(i)][m_y+m_blk.y(i)]!=Qt::GlobalColor::transparent){
            set_blk(pre_blk);
            return false;
        }
    }
    set_blk(pre_blk);
    return true;
}

inline bool TetrisGame::check_clearance(TetrisBlocks m_blk){
    for (int i=0;i<4;i++){
        if(map[x+m_blk.x(i)][y+m_blk.y(i)]!=Qt::GlobalColor::transparent){
            return false;
        }
    }
    return true;
}

inline void TetrisGame::check_and_clear_row(){
    clear_blk(cur_blk);//remove current block before checking and clearing
    int combo=0;
    for (size_t row=0;row<T_HEIGHT;++row){
        bool isFull=true;
        for(size_t col=0;col<T_WIDTH;++col){
            if(map[col][row]==Qt::GlobalColor::transparent){
                isFull=false;
                break;//break column scan
            }
        }
        
        if(isFull){//if indeed full, move everything down and start increasing combo
            combo++;
            level++;
            for(size_t m_x=0;m_x<T_WIDTH;++m_x)
                for(size_t m_y=row;m_y<T_HEIGHT-1;++m_y)
                    map[m_x][m_y]=map[m_x][m_y+1];
            row--;//decrease row to allow this row to check recursively
        }
    }
    score+=10*combo*combo;
    set_blk(cur_blk);
}

void TetrisGame::move_LR(op m_op){
    if(isStarted){
        if(m_op==t_left){
            if(check_clearance(x-1, y, cur_blk,cur_blk)){
                clear_blk(cur_blk);
                setX(x-1);
                set_blk(cur_blk);
            }
        }else{
            if(check_clearance(x+1, y, cur_blk,cur_blk)){
                clear_blk(cur_blk);
                setX(x+1);
                set_blk(cur_blk);
            }
        }
    }
}

void TetrisGame::move_down(){
    if(isStarted){
        if(y+cur_blk.minY()==0||!check_clearance(x, y-1, cur_blk,cur_blk)){
            new_blk();
        }else{
            clear_blk(cur_blk);
            setY(y-1);
            set_blk(cur_blk);
        }
    }
}

void TetrisGame::rotate(op m_op){
    if(isStarted){
        if(m_op==t_cw){
            if(check_clearance(x, y, cur_blk.rotatedRight(),cur_blk)){
                clear_blk(cur_blk);
                cur_blk=cur_blk.rotatedRight();
                set_blk(cur_blk);
            }
        }else{
            if(check_clearance(x, y, cur_blk.rotatedLeft(),cur_blk)){
                clear_blk(cur_blk);
                cur_blk=cur_blk.rotatedLeft();
                set_blk(cur_blk);
            }
        }
    }
}

