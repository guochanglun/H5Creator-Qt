#ifndef CONST_H
#define CONST_H

#include "QString"
#include "state.h"

class Const
{
public:
    Const();
    static const int PHONE_WIDTH = 375;
    static const int PHONE_HEIGHT = 667;

    static int PHONE_X;
    static int PHONE_Y;

    static QString APP_PATH;

    static State *state;

};

#endif // CONST_H
