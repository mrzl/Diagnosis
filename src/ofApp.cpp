#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen( true );
    finished = false;
    clickCounter = 0;

    doneButton.init( 100, 100, 200, 200 );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground( 0 );

    doneButton.draw();

    if ( finished == false ) {
        if ( lines.size() > 0 ) {
          lines[ lines.size() - 1].setSecond( ofGetMouseX(), ofGetMouseY() );
        }
    }

    for( int i = 0; i < lines.size(); i++ )
    {
        ConnectionLine l = lines.at( i );
        l.draw();
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
    int padding = 400;
    if( x > 1920 - padding ) {
        Display *dpy;
        Window root_window;

        dpy = XOpenDisplay(0);
        root_window = XRootWindow(dpy, 0);
        XSelectInput(dpy, root_window, KeyReleaseMask);
        XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, 1920 - padding -10, y);
        XFlush(dpy); // Flushes the output buffer, therefore updates the cursor's position. Thanks to Achernar.
    }

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

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
