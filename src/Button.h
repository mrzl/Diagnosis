#ifndef BUTTON_H
#define BUTTON_H

#include "ofMain.h"

class Button
{
    public:
        Button();
        virtual ~Button();
        void init( int x, int y, int w, int h );
        void draw();
    protected:
    private:
        int x, y, w, h;
        ofTrueTypeFont font;

};

#endif // BUTTON_H
