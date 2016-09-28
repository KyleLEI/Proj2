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
#include <QtWidgets/QLabel>
#include <QtCore/QBasicTimer>
#include "TetrisGame.h"

class TetrisGame;
class TetrisBlocks;
enum op;

class TetrisWindow : public QWidget{
    Q_OBJECT
    
public:
    TetrisWindow();
    
protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    
private:
    QBasicTimer timer;
    QLabel frame;
    QLabel next_frame;
    
    TetrisGame *game;
};

#endif /* TetrisWindow_h */
