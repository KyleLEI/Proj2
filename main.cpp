//
//  main.cpp
//  QtTimerTryout
//
//  Created by Kyle Lei on 2/10/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include <QtWidgets/QApplication>
#include "MyWindow.h"

int main(int argc, char * argv[]) {
    // insert code here...
    QApplication app(argc,argv);
    MyWindow *window=new MyWindow;
    window->show();
    
    return app.exec();
}
