#include "Button.h"

Button::Button( )
{

}

void Button::init( int x, int y, int w, int h  )
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    font.loadFont( "arial.ttf", 32 );
}

Button::~Button()
{
    //dtor
}

void Button::draw()
{
    ofSetColor( 255 );
    ofNoFill();
    ofRect( x, y, w, h );

    font.drawString( "DONE", x + 50, y + 20 );
}
