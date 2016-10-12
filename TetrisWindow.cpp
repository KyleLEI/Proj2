//
//  TetrisWindow.cpp
//  Project2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisWindow.h"

TetrisWindow::TetrisWindow(){
    
    /*Initiallize Window*/
    game = new TetrisGame;//Start new Game

    //Initialize buffer
    Level.sprintf("%s","Level: ");
    Score.sprintf("%s","Score: ");

    //Start Timer
    timer.start(15,this);

    /*Initialize Labels and Layout*/
    QGridLayout *layout = new QGridLayout;
    Level_Dis = new QLabel;
    Score_Dis = new QLabel;
    Bg_Dis = new QLabel;
    Next_Dis = new QLabel;
    Level_Dis->setText("Level");
    Score_Dis->setText("Score");
 
    image.load("background.bmp");
    Bg_Dis->setPixmap(QPixmap::fromImage(image));
    Bg_Dis->show();

    //Layout Arrangement
    layout->addWidget(Bg_Dis,0,0,3,1);
    layout->addWidget(Next_Dis,0,1);
    layout->addWidget(Level_Dis,1,1);
    layout->addWidget(Score_Dis,2,1);
    layout->setRowStretch(0, 200);
    layout->setRowStretch(1, 10);
    layout->setRowStretch(2, 30);
    setLayout(layout);
    
    QPainter painter_win(&image);//QPainter for Drawing on board
    painter_win.setPen(Qt::black);

    setWindowTitle(tr("Tetris"));
}

void TetrisWindow::keyPressEvent(QKeyEvent *event){
    //Modify Game Status based on Keypress
    switch (event->key()) {
        case Qt::Key_Left:
            game->move(t_left);
            break;
        case Qt::Key_Right:
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
            game->start();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

void TetrisWindow::UpdateNext(){
    
    nextPiece = game->getNextBlock();//Get Next Block from Game
    
    //Initialize Preview Window
    QPixmap pixmap(5 * squareSize, 8 * squareSize);
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), Qt::GlobalColor::white);
    
    for (int i = 0; i < 4; ++i) {
        
        int x = 2 + nextPiece.x(i);
        int y = 3 - nextPiece.y(i);
        
        drawSquare(painter, x * squareSize, y * squareSize, nextPiece.getColor());
    }//Draw Next Block on Preview Window
    
    Next_Dis->setPixmap(pixmap);
    Next_Dis->show();
}

void TetrisWindow::drawSquare(QPainter &painter, int x, int y, Qt::GlobalColor SquareColor)
{
    painter.drawRect(x, y,squareSize-1,squareSize-1);
    painter.fillRect(x + 1, y + 1, squareSize - 2, squareSize - 2, SquareColor);
}//Draw a square at (x,y) of the corresponding Pixmap of QPainter and fill the square with Qt::GlobalColor

void TetrisWindow::timerEvent(QTimerEvent *event){
    if (event->timerId() == timer.timerId()) {
        //Update Level and Score Labels
        Level.sprintf("%s%d","Level: ", game->getLevel());
        Level_Dis->setText(Level);
        Score.sprintf("%s%d","Score: ", game->getScore());
        Score_Dis->setText(Score);
        
        UpdateNext(); //Update Preview Window
    }else{
        QObject::timerEvent(event);
    }
}

void TetrisWindow::paintEvent(QPaintEvent *event) {
    /*Update the Game Board*/
    QWidget::paintEvent(event);
    
    image.load("background.bmp");
    QPainter painter_win(&image);
    
    for (int i=0;i<TetrisGame::T_WIDTH;i++){
        for (int j=0;j<TetrisGame::T_HEIGHT;j++){
            if (game->getMap(i,j)!=Qt::GlobalColor::transparent){
                drawSquare(painter_win,i*squareSize,(TetrisGame::T_HEIGHT-1-j)*squareSize,game->getMap(i,j));
            }
        }
    }//Get information from Game and Draw on the Board

    Bg_Dis->setPixmap(QPixmap::fromImage(image));     
    Bg_Dis->show();
}
