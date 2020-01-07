#pragma once

#include "ofMain.h"
#include "ofxOpenCvDnnObjectDetection.h"
#include "ofxHomography.h"
#include "ControlArea.h"
#include "MappedArea.h"

enum Yolotype {
	YOLO2_TINY ,
	YOLO2,
	YOLO3_TINY,
	YOLO3
};

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseMoved(int x, int y);
	void saveOriginalPoints();

	void drawPolyline();

    // ofVideoGrabber camera;
    ofVideoPlayer camera;
    ofxOpenCvDnnObjectDetection detector;
    
    ofImage img;
    uint64_t detection_time;

	vector<ofPoint> pedestrianPoints;
	ofPixels resizedVideoFrame;

	Yolotype yoloType;
	ControlArea original;
	MappedArea mappedArea;

	vector<ofPoint> convertedPedestrainPoints;
};
