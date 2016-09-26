//
//  TetrisWindow.cpp
//  Project2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisWindow.h"

TetrisWindow::TetrisWindow(){
    game=new TetrisGame;
    QGridLayout *layout = new QGridLayout;
    
    setLayout(layout);
    setWindowTitle(tr("Tetris"));
}

void TetrisWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_Left:
            game->move(op::left);
            break;
        case Qt::Key_Right:
            game->move(op::right);
            break;
        case Qt::Key_Down:
            game->move(op::down);
            break;
        case Qt::Key_Z:
            game->move(op::cw);
            break;
        case Qt::Key_X:
            game->move(op::acw);
    }
}

void TetrisWindow::timerEvent(QTimerEvent *event){
    if (event->timerId() == timer.timerId()) {
        //        if (isWaitingAfterLine) {
        //            isWaitingAfterLine = false;
        //            newPiece();
        //            timer.start(timeoutTime(), this);
        //        } else {
        //            oneLineDown();
        //        }
    }
}
