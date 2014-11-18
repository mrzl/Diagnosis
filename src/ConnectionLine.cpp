#include "ConnectionLine.h"

ConnectionLine::ConnectionLine()
{
    x1 = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
}

ConnectionLine::~ConnectionLine()
{
    //dtor
}

void ConnectionLine::setFirst(int _x, int _y)
{
    x1 = _x;
    y1 = _y;
}

void ConnectionLine::setSecond(int _x, int _y)
{
    x2 = _x;
    y2 = _y;
}

void ConnectionLine::draw()
{
    if ( isBothPointsSet() ) {
      ofLine( x1, y1, x2, y2 );
    }
}

bool ConnectionLine::isBothPointsSet()
{
    if ( x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0 ) {
      return true;
    }
    return false;
}
