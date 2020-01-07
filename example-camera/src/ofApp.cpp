#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
    ofSetFrameRate(60);
    // setup camera
    camera.setDeviceID( 0 );
    camera.setDesiredFrameRate( 30 );
    camera.initGrabber( 1280, 720 );
    ofSetWindowShape(camera.getWidth(), camera.getHeight());

    // setup dnn network for object detection. Case: Yolov2-tiny
    detector.setNetworkImageSize(416, 416);
    detector.setup(ofToDataPath("dnn/yolov2-tiny.cfg"),
                   ofToDataPath("dnn/yolov2-tiny.weights"),
                   ofToDataPath("dnn/coco.txt"));

    detector.setConfidenceThreshold(0.4);
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    if( camera.isFrameNew() ){
        // camera image automatically will be croped to detector.setNetworkImageSige
        uint64_t t0 = ofGetElapsedTimeMillis();
        detector.update(camera.getPixels());
        detection_time = ofGetElapsedTimeMillis()-t0;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    camera.draw(0,0);
    detector.draw(0,0, camera.getWidth(), camera.getHeight());
    ofDrawBitmapStringHighlight("FPS:"+ofToString(ofGetFrameRate(), 0),20, 20);
    ofDrawBitmapStringHighlight("Detection Time:"+ofToString(detection_time),20, 40);
}

void ofApp::keyPressed(int key)
{

}


