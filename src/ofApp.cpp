#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

    // ofVec2f
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    vel.x = ofRandom(-10, 10);
    vel.y = ofRandom(-10, 10);
     
    // font
    ofTrueTypeFontSettings fontSettings("NotoSansCJKjp-Regular.ttf", 24);
    fontSettings.addRanges(ofAlphabet::Japanese);
    ttf.load(fontSettings);

    // osc
    ofLog() << "listening for osc messages on port " << PORT;
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
  pos += vel;
  if (pos.x > ofGetWidth()) {pos.x = 0;}
  if (pos.x < 0) {pos.x = ofGetWidth();}
  if (pos.y > ofGetHeight()) {pos.y = 0;}
  if (pos.y < 0) {pos.y = ofGetHeight();}
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    char t[] = u8"\u3042";
    ttf.drawString(t, pos.x, pos.y);
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
