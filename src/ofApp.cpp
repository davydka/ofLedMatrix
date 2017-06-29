#include "ofApp.h"

int gifCounter = 0;
bool flip = false;

//--------------------------------------------------------------
void ofApp::setup(){

	ofLog(OF_LOG_NOTICE, "\n\tsetting up app\n");

	ofSetWindowShape(32, 32);
	ofSetWindowPosition(0, 0);

	//ofSetWindowTitle("app");
	//system ("(sleep 1; wmctrl -r \"app\" -b toggle,above; wmctrl -a \"/bin/bash\") &");

	ofSetFrameRate(60);
	//ofSetVerticalSync(true);
	
	startTime = ofGetElapsedTimeMillis();
	initTime = 0;
	elapsedTime = 0;

	ofBackground(0, 0, 255);
	ofSetCircleResolution(100);
	fbo.allocate(32,32,GL_RGBA);
	fbo.begin();{
		ofDrawEllipse(16, 16, 32, 32);
    }
	fbo.end();
	gifloader.load("images/beatles.gif");
	
	for (int i = 0; (unsigned)i < gifloader.pages.size(); ++i){
		 gifloader.pages[i].getTexture().setAlphaMask(fbo.getTexture());
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	elapsedTime = ofGetElapsedTimeMillis() - startTime;
	if(elapsedTime >= 1000){
		//ofLog(OF_LOG_NOTICE, ofToString(OF_WINDOW));
		//ofLog(OF_LOG_NOTICE, "the number is" + ofToString(ofGetElapsedTimeMillis()));
		startTime += elapsedTime;
	}


	//ofLog( OF_LOG_NOTICE, ofToString(ofGetElapsedTimeMillis()%2) );
	if(ofGetElapsedTimeMillis() % 4 == 0){
		gifCounter++;
		if ((unsigned)gifCounter > gifloader.pages.size()-1) gifCounter = 0;
		gifloader.pages[gifCounter].getTexture().setAlphaMask(fbo.getTexture());
	}

	/*
	auto duration = 10.f;
	auto endTime = initTime + duration;
	auto now = ofGetElapsedTimef();
	auto start = 0.f;
	auto end = 1.f;
	if(flip){
		start = 1.0f;
		end = 0.0f;
	}

	tweenValue = ofxeasing::map_clamp(now, initTime, endTime, start, end, &ofxeasing::exp::easeInOut);
	if(tweenValue >= 1 || tweenValue <= 0.0){
		flip = !flip;
		initTime = now;
	}
	*/

	tweenValue = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
	//tweenValue = sin(ofGetElpasedTimef());
	//ofLog(OF_LOG_NOTICE, ofToString(tweenValue));
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofClear(255, 0, 0);
	//ofBackground(0, 0, 255);

	ofSetColor(255, 51, 0);
	ofDrawBitmapString( ofGetFrameRate(), 20,30 );
	ofSetColor(255);


	fbo.begin();{
		ofClear(0,255); 
		ofDrawEllipse(16, 16, 32*tweenValue, 32*tweenValue);
    }
	fbo.end();
		
	gifloader.pages[gifCounter].draw(0, 0, 32, 32);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
