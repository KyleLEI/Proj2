//
//  TetrisWindow.cpp
//  Project2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "TetrisWindow.h"

TetrisWindow::TetrisWindow(){
   // squareHeight = 10;
   // squareWidth = 10;
    game=new TetrisGame;
    QGridLayout *layout = new QGridLayout;
    Level_Dis = new QLabel;
    Score_Dis = new QLabel;
    Bg_Dis = new QLabel;
    Next_Dis = new QLabel;
    Level_Dis->setText("Level");
    Score_Dis->setText("Score");
    // frame.setText("You Wanker");
    image.load("background.bmp");
    Bg_Dis->setPixmap(QPixmap::fromImage(image)); 
    Bg_Dis->show(); 

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

void TetrisWindow::UpdateWindow() {
  for (int i=0;i<30;i++){
	for (int j=0;j<30;j++ ){
	
}
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
}

void TetrisWindow::drawSquare(QPainter &painter, int x, int y, Qt::GlobalColor SquareColor)
{

   // static const QRgb colorTable[8] = {
   //     0x000000, 0xCC6666, 0x66CC66, 0x6666CC,
  //      0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00
    //};

   // QColor color;
    painter.fillRect(x + 1, y + 1, squareWidth - 2, squareHeight - 2, SquareColor);

    painter.setPen(Qt::black);
    painter.drawLine(x, y + squareHeight - 1, x, y);
    painter.drawLine(x, y, x + squareWidth - 1, y);
    painter.drawLine(x + 1, y + squareHeight - 1,
                     x + squareWidth - 1, y + squareHeight - 1);
    painter.drawLine(x + squareWidth - 1, y + squareHeight - 1,
                     x + squareWidth - 1, y + 1);

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

	//	UpdateBoard();
	
    }else{
        QObject::timerEvent(event);
    }
}
