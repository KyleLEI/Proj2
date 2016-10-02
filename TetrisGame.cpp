//
//  TetrisGame.cpp
//  Project2
//
//  Created by Kyle Lei on 26/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisGame.h"

TetrisGame::TetrisGame():isStarted(false),level(1),score(0){
    timer=new QBasicTimer;
}

void TetrisGame::move(op m_op){
    return;
}

void TetrisGame::timerEvent(QTimerEvent *event){
    
}
