#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

    // ofVec2f
    for (int i=0; i<NUM; i++) {
      pos[i].x = ofGetWidth()/2;
      pos[i].y = ofGetHeight()/2;
      vel[i].x = ofRandom(-10, 10);
      vel[i].y = ofRandom(-10, 10);
    }
     
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
  for (int i=0; i<NUM; i++) {
    pos[i] += vel[i];
    if (pos[i].x > ofGetWidth()) {pos[i].x = 0;}
    if (pos[i].x < 0) {pos[i].x = ofGetWidth();}
    if (pos[i].y > ofGetHeight()) {pos[i].y = 0;}
    if (pos[i].y < 0) {pos[i].y = ofGetHeight();}
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    char t[] = u8"\u3042";
    for (int i=0; i<NUM; i++) {
        
      ttf.drawString(t, pos[i].x, pos[i].y);
    }
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
