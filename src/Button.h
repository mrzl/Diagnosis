#pragma once

#include "ofMain.h"

class DoneButton
{
    public:
        DoneButton();
        virtual ~DoneButton();
        void init( int x, int y, int w, int h );
        void draw();
		bool isIn( int x, int y );

        int x, y, w, h;
        ofTrueTypeFont font;

};
