#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
    ofSetFrameRate(60);
    // setup camera
    // camera.setDeviceID( 0 );
    // camera.setDesiredFrameRate( 30 );
    // camera.initGrabber( 1280, 720 );
    // camera.setFrameRate(30);
	camera.load("cctv_sample.mp4");
    camera.play();
    ofSetWindowShape(camera.getWidth(), camera.getHeight());

    // setup dnn network for object detection. Case: Yolov2-tiny
//	detector.setNetworkImageSize(416, 416);
//	detector.setup(ofToDataPath("dnn/yolov2-tiny.cfg"),
//				   ofToDataPath("dnn/yolov2-tiny.weights"),
//				   ofToDataPath("dnn/coco.txt"));


//	detector.setNetworkImageSize(608, 608);
//	detector.setup(ofToDataPath("dnn/yolov2.cfg"),
//				   ofToDataPath("dnn/yolov2.weights"),
//				   ofToDataPath("dnn/coco.txt"));

	detector.setNetworkImageSize(608, 608);
	detector.setup(ofToDataPath("dnn/yolov3.cfg"),
				   ofToDataPath("dnn/yolov3.weights"),
				   ofToDataPath("dnn/coco.txt"));

//	detector.setNetworkImageSize(416, 416);
//	detector.setup(ofToDataPath("dnn/yolov2-tiny-voc.cfg"),
//				   ofToDataPath("dnn/yolov2-tiny-voc.weights"),
//				   ofToDataPath("dnn/voc.txt"));


	// so far best
	// detector.setNetworkImageSize(416, 416);
	// detector.setup(ofToDataPath("dnn/yolov3-tiny.cfg"),
	// 			   ofToDataPath("dnn/yolov3-tiny.weights"),
	// 			   ofToDataPath("dnn/coco.txt"));

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

		pedestrianPoints.clear();
		for(int i=0; i<detector.object.size(); i++){
			// only human
			if(detector.object.at(i).class_id == 0)	pedestrianPoints.push_back(detector.object.at(i).getCenterPoint(0, 0, camera.getWidth(), camera.getHeight()));
		}
    }
	cout << pedestrianPoints.size() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    camera.draw(0,0);

//    detector.draw(0,0, camera.getWidth(), camera.getHeight());
    ofDrawBitmapStringHighlight("FPS:"+ofToString(ofGetFrameRate(), 0),20, 20);
    ofDrawBitmapStringHighlight("Detection Time:"+ofToString(detection_time),20, 40);

	ofPushStyle();
	for(int i=0; i<pedestrianPoints.size(); i++){
		ofSetColor(255, 255, 0);
		ofDrawCircle(pedestrianPoints.at(i), 3);

	}
	ofPopStyle();
}

void ofApp::keyPressed(int key)
{

}


