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
    timer.start(15,this); 
  
    image.load("background.bmp");
    Bg_Dis->setPixmap(QPixmap::fromImage(image)); 
    Bg_Dis->show(); 
    
    QPainter painter_win(&image);
    painter_win.setPen(Qt::black);
    // layout->addWidget(&frame);
    // layout->addWidget(&next_frame);
    
    layout->addWidget(Bg_Dis);
    layout->addWidget(Next_Dis,0,1); 
    layout->addWidget(Level_Dis,1,1);
    layout->addWidget(Score_Dis,2,1);
    setLayout(layout);

    setWindowTitle(tr("Tetris"));
}

void TetrisWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_Left:
            // frame.setText("Left");
            game->move(t_left);
            break;
        case Qt::Key_Right:
            // frame.setText("Right");
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

void TetrisWindow::UpdateNext(){

    nextPiece = game->getNextBlock();
 
    int dx = nextPiece.maxX() - nextPiece.minX() + 1;
    int dy = nextPiece.maxY() - nextPiece.minY() + 1;

    QPixmap pixmap(dx * squareWidth, dy * squareHeight);
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), Next_Dis->palette().background());

    for (int i = 0; i < 4; ++i) {
        int x = nextPiece.x(i) - nextPiece.minX();
        int y = nextPiece.y(i) - nextPiece.minY();
        drawSquare(painter, x * squareWidth, y * squareHeight , nextPiece.getColor());
    }
    Next_Dis->setPixmap(pixmap);
    Next_Dis->show();
}

void TetrisWindow::drawSquare(QPainter &painter, int x, int y, Qt::GlobalColor SquareColor)
{
    painter.drawRect(x, y,squareHeight-1,squareWidth-1);
    painter.fillRect(x + 1, y + 1, squareWidth - 2, squareHeight - 2, SquareColor);

    //painter.setPen(Qt::black);
    //painter.drawLine(x, y + squareHeight - 1, x, y);
    //painter.drawLine(x, y, x + squareWidth - 1, y);
    //painter.drawLine(x + 1, y + squareHeight - 1, x + squareWidth - 1, y + squareHeight - 1);
    //painter.drawLine(x + squareWidth - 1, y + squareHeight - 1,x + squareWidth - 1, y + 1);

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
        
        Level_Dis->setNum(game->getLevel());
        Score_Dis->setNum(game->getScore());
        UpdateNext();
	//UpdateWindow();
	
    }else{
        QObject::timerEvent(event);
    }
}

void TetrisWindow::paintEvent(QPaintEvent *event) {

        QWidget::paintEvent(event);

        image.load("background.bmp");
	QPainter painter_win(&image);

	for (int i=0;i<10;i++){
   	   for (int j=0;j<20;j++){
        	 if (game->getMap(i,j)!=Qt::GlobalColor::transparent){
            drawSquare(painter_win,i*squareWidth,(19-j)*squareHeight,game->getMap(i,j));
       }
    }
 }
    Bg_Dis->setPixmap(QPixmap::fromImage(image));     
    Bg_Dis->show();
}
