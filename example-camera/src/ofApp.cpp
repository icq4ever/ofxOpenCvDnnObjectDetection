#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	yoloType = YOLO3_TINY;
  
    ofSetFrameRate(60);
    // setup camera
    // camera.setDeviceID( 0 );
    // camera.setDesiredFrameRate( 30 );
    // camera.initGrabber( 1280, 720 );
    // camera.setFrameRate(30);
	camera.load("cctv_sample.mp4");
    camera.play();

	resizedVideoFrame.allocate(camera.getWidth()/2, camera.getHeight()/2, OF_IMAGE_COLOR);
//    ofSetWindowShape(camera.getWidth(), camera.getHeight());

	switch(yoloType){
	case YOLO2_TINY:
		// setup dnn network for object detection. Case: Yolov2-tiny
		detector.setNetworkImageSize(416, 416);
		detector.setup(ofToDataPath("dnn/yolov2-tiny.cfg"),
					   ofToDataPath("dnn/yolov2-tiny.weights"),
					   ofToDataPath("dnn/coco.txt"));
		break;
	case YOLO2:
		detector.setNetworkImageSize(608, 608);
		detector.setup(ofToDataPath("dnn/yolov2.cfg"),
					   ofToDataPath("dnn/yolov2.weights"),
					   ofToDataPath("dnn/coco.txt"));
		break;
	case YOLO3_TINY:
		// so far best
		 detector.setNetworkImageSize(416, 416);
		 detector.setup(ofToDataPath("dnn/yolov3-tiny.cfg"),
						ofToDataPath("dnn/yolov3-tiny.weights"),
						ofToDataPath("dnn/coco.txt"));
		break;
	default:
		detector.setNetworkImageSize(608, 608);
		detector.setup(ofToDataPath("dnn/yolov3.cfg"),
					   ofToDataPath("dnn/yolov3.weights"),
					   ofToDataPath("dnn/coco.txt"));
		break;
	}

	detector.setConfidenceThreshold(0.4);

	//register mouse Event
//	original.setup(this);
	mappedArea.setup(720, 400);
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    if( camera.isFrameNew() ){
        // camera image automatically will be croped to detector.setNetworkImageSige
        uint64_t t0 = ofGetElapsedTimeMillis();
//		resizedVideoFrame = camera.getPixels();
//		resizedVideoFrame.resize(camera.getWidth()/2, camera.getHeight()/2, OF_INTERPOLATE_NEAREST_NEIGHBOR);
//		detector.update(resizedVideoFrame);

		detector.update(camera.getPixels());
        detection_time = ofGetElapsedTimeMillis()-t0;

		pedestrianPoints.clear();
		for(int i=0; i<detector.object.size(); i++){
			// only human
			if(detector.object.at(i).class_id == 0)	pedestrianPoints.push_back(detector.object.at(i).getCenterPoint(0, 0, camera.getWidth(), camera.getHeight()));
		}
    }
//	cout << pedestrianPoints.size() << endl;
//	cout << originalPoly.size() << endl;

//	original.getIndexOfCorner(mouseX, mouseY);
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

	original.draw();

	mappedArea.draw(720, 0);
}


void ofApp::saveOriginalPoints(){
//	for(int i=0; i<originalPoly.size(); i++){
//		originalPoly.
//	}
}
void ofApp::mousePressed(int x, int y, int button){
	if(x < camera.getWidth()){	// left Side
		original.addPoint(ofPoint(x, y));
	}
}

void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mouseMoved(int x, int y){}


void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){
	if(key == 'i'){

	}
	else if(key == 'o'){

	}
}

