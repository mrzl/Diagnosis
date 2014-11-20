#pragma once

#include "ofMain.h"
#include "ConnectionLine.h"
#include "Button.h"

#include "ofxThermalPrinter.h"
#include "ofxOpenCv.h"

#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <string>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void exit();
		void draw();

		void drawHistory();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofxCvColorImage	colorImg;

    int clickCounter;
    bool finished;
    std::vector< ConnectionLine > lines;
    std::vector< std::string> diseases;
    std::vector< ofVec2f > drawnPoints;
	std::deque< ofImage > recentImages;
    DoneButton doneButton;
	int padding;

	ofxThermalPrinter printer;

	// cursor stuff
    Display *dpy;
    Window root_window;


};
