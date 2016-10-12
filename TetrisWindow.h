//
//  TetrisWindow.h
//  Project2
//  frame refresh handler
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#ifndef TetrisWindow_h
#define TetrisWindow_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtGui/QKeyEvent>
#include <QtGui/QPainter>
#include <QtWidgets/QLabel>
#include <QtCore/QBasicTimer>
#include <QtCore/QString>
#include "TetrisGame.h"

class TetrisGame;
class TetrisBlocks;
enum TetrisShape;
enum op;

class TetrisWindow : public QWidget{
public:
    TetrisWindow();
    
protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
 
private:
    QBasicTimer timer;
    QLabel* Level_Dis;
    QLabel* Score_Dis;
    QLabel* Bg_Dis;
    QLabel* Next_Dis;
    TetrisBlocks nextPiece;
    QString Score,Level;
    const int squareSize= 20;
    QImage image; 
    QPainter painter_win;    
    
    TetrisGame *game;

    void drawSquare(QPainter &painter, int x, int y, Qt::GlobalColor SquareColor);
    void UpdateNext();
};

#endif /* TetrisWindow_h */
