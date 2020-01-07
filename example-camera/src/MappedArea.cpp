#include "MappedArea.h"

MappedArea::MappedArea(){ }
MappedArea::~MappedArea(){}

// setup
//void MappedArea::setup(vector<ofPoint> setupAreaPoints){
void MappedArea::setup(float w, float h){
	cornerPoints.push_back(ofPoint(w, 0));
	cornerPoints.push_back(ofPoint(0, 0));
	cornerPoints.push_back(ofPoint(0, h));
	cornerPoints.push_back(ofPoint(w, h));

	for(int i=0; i<cornerPoints.size(); i++){
		outline.addVertex(cornerPoints.at(i));
	}
	outline.close();
}

void MappedArea::update(vector<ofPoint> originalPoints){

}

void MappedArea::draw(ofPoint leftTopPoint){
	draw(leftTopPoint.x, leftTopPoint.y);
}

void MappedArea::draw(float x, float y){
	ofPushMatrix();
	ofPushStyle();
	ofTranslate(x, y);
	ofSetHexColor(0xFFFFFF);
	outline.draw();
	ofPopStyle();
	ofPopMatrix();
}


