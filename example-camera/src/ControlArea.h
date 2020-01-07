#pragma once
#include "ofMain.h"

class ControlArea: ofBaseApp{
public:
	ControlArea();
	~ControlArea();

	void addPoint(ofPoint p);
	void update();
	void draw();
	void mousePressed(ofMouseEventArgs &mouse);
	void mouseReleased(ofMouseEventArgs &mouse);
	void mouseDragged(ofMouseEventArgs & mouse);
	void mouseMoved(ofMouseEventArgs & mouse);

	vector<ofPoint> cornerPoints;
	vector<bool> cornerActivated;
	int activatedCornerId = -1;
	ofPolyline poly;
	bool mCheck = false;
};

