//
//  main.cpp
//  Proj2
//
//  Created by Kyle Lei on 25/9/2016.
//  Copyright © 2016 LEI Zhao. All rights reserved.
//

#include <QtWidgets/QApplication>
#include "TetrisWindow.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);

    TetrisWindow window;
    window.show();
    
    return app.exec();
}
