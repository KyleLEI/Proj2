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

class TetrisGame : public QFrame{
    Q_OBJECT
public:
    TetrisGame();
protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
};

#endif /* TetrisGame_h */
