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
    Level_Dis = new QLabel;
    Score_Dis = new QLabel;
    Bg_Dis = new QLabel;
    Level_Dis->setText("Level");
    Score_Dis->setText("Score");
   // frame.setText("You Wanker");
    image.load("background.bmp");
    Bg_Dis->setPixmap(QPixmap::fromImage(image)); 
    Bg_Dis->show(); 

   // layout->addWidget(&frame);
   // layout->addWidget(&next_frame);
    layout->addWidget(Bg_Dis); 
    layout->addWidget(Level_Dis);
    layout->addWidget(Score_Dis);
   //layout->addWidget(Bg_Dis);   
    setLayout(layout);

    setWindowTitle(tr("Tetris"));
    resize(500, 400);
    timer.start(15, this);
}

void TetrisWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_Left:
           // frame.setText("Left");
            game->move(t_left);
            break;
        case Qt::Key_Right:
          //  frame.setText("Right");
            game->move(t_right);
            break;
        case Qt::Key_Down:
            game->move(t_down);
            break;
        case Qt::Key_Z:
            game->move(t_cw);
            break;
        case Qt::Key_X:
            game->move(t_acw);
            break;
        case Qt::Key_Up:
         // frame.setText("Start");
            game->start();
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
       // frame.setNum(game->y);
       // next_frame.setNum(game->x);
    }else{
        QObject::timerEvent(event);
    }
}
