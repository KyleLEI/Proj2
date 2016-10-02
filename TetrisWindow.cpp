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
    
    QLabel* label=new QLabel("you cheeky basterd");
    
    layout->addWidget(label);
    
    setLayout(layout);
    setWindowTitle(tr("Tetris"));
    resize(500, 400);
}

void TetrisWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_Left:
            game->move(left);
            break;
        case Qt::Key_Right:
            game->move(right);
            break;
        case Qt::Key_Down:
            game->move(down);
            break;
        case Qt::Key_Z:
            game->move(cw);
            break;
        case Qt::Key_X:
            game->move(acw);
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
