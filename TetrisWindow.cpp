//
//  TetrisWindow.cpp
//  Project2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisWindow.h"

TetrisWindow::TetrisWindow(){

 
    game = new TetrisGame;
    QGridLayout *layout = new QGridLayout;
    Level_Dis = new QLabel;
    Score_Dis = new QLabel;
    Bg_Dis = new QLabel;
    Next_Dis = new QLabel;
    Level_Dis->setText("Level");
    Score_Dis->setText("Score");
    sprintf(Level, "%s","Level: ");
    sprintf(Score, "%s","Score: ");
    timer.start(15,this); 
  
    image.load("background.bmp");
    Bg_Dis->setPixmap(QPixmap::fromImage(image)); 
    Bg_Dis->show(); 
    
    QPainter painter_win(&image);
    painter_win.setPen(Qt::black);
    
    layout->addWidget(Bg_Dis,0,0,3,1);
    layout->addWidget(Next_Dis,0,1); 
    layout->addWidget(Level_Dis,1,1);
    layout->addWidget(Score_Dis,2,1);
    layout->setRowStretch(0, 100);
    setLayout(layout);

    setWindowTitle(tr("Tetris"));
}

void TetrisWindow::keyPressEvent(QKeyEvent *event){
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

    nextPiece = game->getNextBlock();
 
    //int dx = nextPiece.maxX() - nextPiece.minX() + 1;
    //int dy = nextPiece.maxY() - nextPiece.minY() + 1;

    QPixmap pixmap(3 * squareWidth, 4 * squareHeight);
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), Next_Dis->palette().background());

    for (int i = 0; i < 4; ++i) {
        int x = nextPiece.x(i) - nextPiece.minX();
        int y = nextPiece.maxY() - nextPiece.y(i);
	
        drawSquare(painter, x * squareWidth, y * squareHeight , nextPiece.getColor());
    }
    Next_Dis->setPixmap(pixmap);
    Next_Dis->show();
}

void TetrisWindow::drawSquare(QPainter &painter, int x, int y, Qt::GlobalColor SquareColor)
{
    painter.drawRect(x, y,squareHeight-1,squareWidth-1);
    painter.fillRect(x + 1, y + 1, squareWidth - 2, squareHeight - 2, SquareColor);
}

void TetrisWindow::timerEvent(QTimerEvent *event){
    if (event->timerId() == timer.timerId()) {
	
	sprintf(Level,"%s%d","Level: ", game->getLevel());
        Level_Dis->setText(Level);
	sprintf(Score,"%s%d","Score: ", game->getScore());
        Score_Dis->setText(Score);

        UpdateNext();
    }else{
        QObject::timerEvent(event);
    }
}

void TetrisWindow::paintEvent(QPaintEvent *event) {

        QWidget::paintEvent(event);

        image.load("background.bmp");
	QPainter painter_win(&image);

    for (int i=0;i<TetrisGame::T_WIDTH;i++){
        for (int j=0;j<TetrisGame::T_HEIGHT;j++){
        	 if (game->getMap(i,j)!=Qt::GlobalColor::transparent){
                 drawSquare(painter_win,i*squareWidth,(TetrisGame::T_HEIGHT-1-j)*squareHeight,game->getMap(i,j));
       }
    }
 }
    Bg_Dis->setPixmap(QPixmap::fromImage(image));     
    Bg_Dis->show();
}
