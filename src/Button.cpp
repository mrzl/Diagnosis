#include "Button.h"

DoneButton::DoneButton( )
{

}

void DoneButton::init( int x, int y, int w, int h  )
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    font.loadFont( "arial.ttf", 30 );
}

DoneButton::~DoneButton()
{
    //dtor
}

void DoneButton::draw()
{
    ofSetColor( 255 );
    ofNoFill();
    ofRect( x, y, w, h );

    font.drawString( "DONE", x + 10, y + this->h - 10 );
}

bool DoneButton::isIn( int x, int y )
{
	return ( x > this->x && x < this->x + this->w && y > this->y && y < this->y + this->h );
}
