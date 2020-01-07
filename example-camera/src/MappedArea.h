#include "ofMain.h"

class MappedArea : ofBaseApp{
public:
	MappedArea();
	~MappedArea();

//	void setup(vector<ofPoint> setupAreaPoints);
	void setup(float w, float h);
	void update(vector<ofPoint> originalPoints);
	void draw(ofPoint point);
	void draw(float x, float y);

	vector<ofPoint> cornerPoints;
	vector<ofPoint> convertedPoints;
	ofPolyline outline;

};
