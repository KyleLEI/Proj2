//
//  MyWindow.hpp
//  QtTimerTryout
//
//  Created by Kyle Lei on 2/10/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QtCore>
#include <QtWidgets/QVBoxLayout>

class MyWindow: public QWidget{
    Q_OBJECT
    
public:
    MyWindow();
    ~MyWindow(){delete timer;};
    
protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    
private:
    QBasicTimer *timer;
    QLabel label;
    int counter;
};
