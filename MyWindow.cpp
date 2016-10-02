//
//  MyWindow.cpp
//  QtTimerTryout
//
//  Created by Kyle Lei on 2/10/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include "MyWindow.h"

MyWindow::MyWindow():counter(0){
    timer=new QBasicTimer;
    timer->start(counter*1000,this);
    label.setNum(counter);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(&label);
    setLayout(layout);
}

void MyWindow::timerEvent(QTimerEvent *event){
    if(event->timerId()==timer->timerId()){
        label.setNum(++counter);
        timer->start(counter*1000, this);
    }else{
        QWidget::timerEvent(event);
    }
}
