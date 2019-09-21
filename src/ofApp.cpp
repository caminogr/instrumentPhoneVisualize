#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
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
  for (int i=0; i<pos.size(); i++) {
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
    for (int i=0; i<pos.size(); i++) {
        ttf.drawString(t, pos[i].x, pos[i].y);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    ofVec2f p;
    p.set(ofGetWidth()/2, ofGetHeight()/2);
    pos.push_back(p);
    
    ofVec2f v;
    v.set(ofRandom(-1, 1), ofRandom(-1, 1));
    vel.push_back(v);
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
