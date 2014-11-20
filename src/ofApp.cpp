#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen( true );
    finished = false;
    clickCounter = 0;
	padding = 400;

	 dpy = XOpenDisplay(0);
    root_window = XRootWindow(dpy, 0);

printer.open("/dev/ttyUSB0");

std::ifstream input("data/diseases.txt");

std::string line;
for( std::string line; getline( input, line ); )
{
    diseases.push_back( line );
}

	doneButton.init( ofGetWidth() / 2 - padding / 2, ofGetHeight() - 50, 130, 50 );
}

//--------------------------------------------------------------
void ofApp::update(){

}
void ofApp::exit() {
    printer.close();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground( 0 );
	ofSetLineWidth( 1 );
    doneButton.draw();
	ofSetLineWidth( 3 );

    if ( finished == false ) {
        if ( lines.size() > 0 ) {
          lines[ lines.size() - 1].setSecond( ofGetMouseX(), ofGetMouseY() );
        }
    }

    for( int i = 0; i < lines.size(); i++ )
    {
        ConnectionLine l = lines.at( i );
        //l.draw();
    }

    for( int i = 0; i < drawnPoints.size(); i++ )
    {
        if( i < drawnPoints.size() - 1 )
        {
            ofVec2f p = drawnPoints.at( i );
            ofVec2f p2 = drawnPoints.at( i + 1 );
            if( ofDist(p.x, p.y, p2.x, p2.y ) < 100 ) {
                ofLine( p.x, p.y, p2.x, p2.y );
            }
        }
    }

	drawHistory();
}

void ofApp::drawHistory()
{
	for( int y = 0; y < 7; y ++ )
	{
		for( int x = 0; x < 2; x++ )
		{
			int index = y * 2 + x;
			if( index < recentImages.size() )
			{
				ofImage image = recentImages.at( index );
				image.draw( ofGetWidth() - padding + x * 200, y * 142 + 20 );
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if( x > 1920 - padding ) {

        XSelectInput(dpy, root_window, KeyReleaseMask);
        XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, 1920 - padding -10, y);
        XFlush(dpy); // Flushes the output buffer, therefore updates the cursor's position. Thanks to Achernar.
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
drawnPoints.push_back( ofVec2f( x, y ) );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	clickCounter++;

	if ( clickCounter > 1 ) {
        lines.at( lines.size() - 1 ).setSecond( ofGetMouseX(), ofGetMouseY() );
        lines.push_back( ConnectionLine() );
        lines.at( lines.size() - 1 ).setFirst( ofGetMouseX(), ofGetMouseY() );
    } else {
        lines.push_back( ConnectionLine() );
        lines.at( lines.size() - 1 ).setFirst( ofGetMouseX(), ofGetMouseY() );
    }

	if( !doneButton.isIn( x, y ))
	{

	} else
	{
		ofBackground( 0 );
		ofSetLineWidth( 25 );
		for( int i = 0; i < drawnPoints.size(); i++ )
        {
            if( i < drawnPoints.size() - 1 )
            {
                ofVec2f p = drawnPoints.at( i );
                ofVec2f p2 = drawnPoints.at( i + 1 );
                if( ofDist(p.x, p.y, p2.x, p2.y ) < 100 ) {
                    ofLine( p.x, p.y, p2.x, p2.y );
                }
            }
        }
		ofSetLineWidth( 3 );
		ofFill();
		ofSetColor( 0 );
		ofRect( doneButton.x - 2, doneButton.y, doneButton.w, doneButton.h );
		ofImage grabbed;
		grabbed.grabScreen( 0, 0, ofGetWidth() - padding, ofGetHeight() );
		grabbed.resize( grabbed.width * 0.1315, grabbed.height * 0.1315 );
		recentImages.push_back( grabbed );

		if( recentImages.size() > 14 )
		{
			recentImages.pop_front();
		}

		grabbed.saveImage( "out.jpg" );
		ofBackground( 0 );
		lines.clear();
		drawnPoints.clear();

		colorImg.allocate( grabbed.width, grabbed.height );
		colorImg.setFromPixels( grabbed.getPixels(), grabbed.width, grabbed.height );
		colorImg.invert();
		colorImg.resize( 384, 272 );

        std::string disease = diseases.at( static_cast< int > ( ofRandom( 0, diseases.size() - 2 ) ) );
        std::stringstream text;
        text << "Your diagnosis is: ";
        printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
        printer.setAlign( MIDDLE );
        printer.setBold( false );
        printer.println( text.str() );
        printer.setAlign( MIDDLE );
        printer.setBold( true );
        printer.println( disease );
        printer.setBold( false );
		printer.print( colorImg, 127 );
		printer.setAlign( MIDDLE );

		while( printer.isThreadRunning() ) {

		}

        printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		printer.feed( );
		clickCounter = 0;
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
