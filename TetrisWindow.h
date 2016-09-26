//
//  TetrisWindow.h
//  Proj2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#ifndef TetrisWindow_h
#define TetrisWindow_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QFrame>

class TetrisWindow : public QWidget
{
    Q_OBJECT
    
public:
    TetrisWindow();
    
protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
//private:
//    QPushButton *quitButton;
};

#endif /* TetrisWindow_h */
