//
//  TetrisGame.h
//  Proj2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#ifndef TetrisGame_h
#define TetrisGame_h

#include <QtWidgets/QFrame>
#include <QtGui/QKeyEvent>
#include <QtCore/QBasicTimer>

class TetrisGame : public QFrame{
    Q_OBJECT
public:
    TetrisGame();
    
protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    
private:
    QBasicTimer timer;
};

#endif /* TetrisGame_h */
