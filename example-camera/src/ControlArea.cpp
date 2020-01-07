#include "ControlArea.h"

ControlArea::ControlArea(){
	ofAddListener(ofEvents().mousePressed, this, &ControlArea::mousePressed);
	ofAddListener(ofEvents().mouseReleased, this, &ControlArea::mouseReleased);
	ofAddListener(ofEvents().mouseDragged, this, &ControlArea::mouseDragged);
	ofAddListener(ofEvents().mouseMoved, this, &ControlArea::mouseMoved);

	activatedCornerId = -1;
}

ControlArea::~ControlArea(){}

//void ControlArea::setup(ofApp *app){

//}
void ControlArea::addPoint(ofPoint p){
	if(cornerPoints.size() <4){
		cornerPoints.push_back(p);
		cornerActivated.push_back(false);

		poly.clear();
		for(int i=0; i<cornerPoints.size(); i++){
			poly.addVertex(cornerPoints.at(i));
		}
		poly.close();
	}


}

void ControlArea::update(){

}

void ControlArea::draw(){
	ofPushStyle();

	ofSetLineWidth(1);

	// draw corners
	for(int i=0; i< cornerPoints.size(); i++){
		if(activatedCornerId == i){
			ofFill();
			ofSetHexColor(0xFFFF00);
		} else {
			ofNoFill();
			ofSetHexColor(0xFFFFFF);
		}
		ofDrawCircle(cornerPoints.at(i), 10);


		ofNoFill();
		ofDrawBitmapString(ofToString(i+1), cornerPoints.at(i) + ofPoint( -6, -12));
		ofDrawCircle(cornerPoints.at(i), 10);
	}
	\

	ofSetLineWidth(2);
	ofSetHexColor(0xFFFFFF);
	ofNoFill();
	// draw Area
	poly.draw();

	ofPopStyle();
}


void ControlArea::mouseMoved(ofMouseEventArgs&mouse){
	if(cornerPoints.size() > 3){
		int enabledIndex = -1;
		for(int i=0; i<cornerPoints.size(); i++){
			if(ofPoint(mouse.x, mouse.y).distance(cornerPoints.at(i)) < 10){
				enabledIndex = i;
			}
		}
		activatedCornerId = enabledIndex;
	}
//	cout << activatedCornerId << endl;
}

void ControlArea::mousePressed(ofMouseEventArgs &mouse){
	if(cornerPoints.size() >3 && activatedCornerId !=-1 && !mCheck){
		cout << "mouse Pressed at : " << activatedCornerId << endl;
		cornerActivated.at(activatedCornerId) = true;
		mCheck=true;
	}
}
void ControlArea::mouseReleased(ofMouseEventArgs &mouse){
	if(mCheck){
		cornerActivated.at(activatedCornerId) = false;
		cout << "mouse Released at : " << activatedCornerId << endl;
		mCheck=false;
	}
}

void ControlArea::mouseDragged(ofMouseEventArgs & mouse){
	if(activatedCornerId !=-1 && mCheck){
		cornerPoints.at(activatedCornerId).set(mouse.x, mouse.y);
	}

	poly.clear();
	for(int i=0; i<cornerPoints.size(); i++){
		poly.addVertex(cornerPoints.at(i));
	}
	poly.close();
}
