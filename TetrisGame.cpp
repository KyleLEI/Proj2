//
//  TetrisGame.cpp
//  Project2
//
//  Created by Kyle Lei on 26/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisGame.h"

void TetrisGame::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_Left:

            break;
        case Qt::Key_Right:

            break;
        case Qt::Key_Down:

            break;
        case Qt::Key_Up:

            break;
        case Qt::Key_Space:

            break;
        case Qt::Key_D:

            break;
        default:
            QFrame::keyPressEvent(event);
    }
}

void TetrisGame::timerEvent(QTimerEvent *event){
    if (event->timerId() == timer.timerId()) {
//        if (isWaitingAfterLine) {
//            isWaitingAfterLine = false;
//            newPiece();
//            timer.start(timeoutTime(), this);
//        } else {
//            oneLineDown();
//        }
    }
    else {
        QFrame::timerEvent(event);
    }
}
