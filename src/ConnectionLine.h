#ifndef CONNECTIONLINE_H
#define CONNECTIONLINE_H

#include "ofMain.h"

class ConnectionLine
{
    public:
        ConnectionLine();
        virtual ~ConnectionLine();

        void setFirst( int _x, int _y );
        void setSecond( int _x, int _y );
        void draw();
        bool isBothPointsSet();
    protected:
    private:
        int x1, x2, y1, y2;
};

#endif // CONNECTIONLINE_H
