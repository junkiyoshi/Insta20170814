#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(3);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	this->cam.begin();

	float radius = 300;

	for (int i = 0; i < 3; i++) {

		if (i == 0) { ofSetColor(255, 0, 0); }
		if (i == 1) { ofSetColor(0, 255, 0); }
		if (i == 2) { ofSetColor(0, 0, 255); }

		float pre_x = 0;
		float pre_y = 0;
		float start_x, start_y;

		for (int deg = 0; deg <= 360; deg += 1) {
			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);

			float tmp_radius = ofMap(ofNoise(i, x * 0.5, y * 0.5, ofGetFrameNum() * 0.005), 0, 1, radius * 0.6, radius * 1.4);

			float tmp_x = tmp_radius * cos(deg * DEG_TO_RAD);
			float tmp_y = tmp_radius * sin(deg * DEG_TO_RAD);

			if (pre_x != 0 && pre_y != 0) {
				ofLine(tmp_x, tmp_y, pre_x, pre_y);
			}
			else {
				start_x = tmp_x;
				start_y = tmp_y;
			}

			pre_x = tmp_x;
			pre_y = tmp_y;
		}

		ofLine(pre_x, pre_y, start_x, start_y);
	}

	this->cam.end();
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
