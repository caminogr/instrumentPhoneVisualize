#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetColor(255);
  ofBackground(0);
  
  // font
  ofTrueTypeFontSettings fontSettings("NotoSansCJKjp-Regular.ttf", 36);
  fontSettings.addRanges(ofAlphabet::Japanese);
  ttf.load(fontSettings);

  // osc
  ofLog() << "listening for osc messages on port " << PORT;
  receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
  for (int i = life_span.size() - 1; i >= 0; i--) {
    life_span[i] -= 1;
    if (life_span[i] == 0) {
      life_span.erase(life_span.begin() + i);
      pos.erase(pos.begin() + i);
      vel.erase(vel.begin() + i);
      code_index_list.erase(code_index_list.begin() + i);
    }
  }

  for (int i=0; i<pos.size(); i++) {
    pos[i] += vel[i];
    if (pos[i].x > ofGetWidth()) {pos[i].x = 0;}
    if (pos[i].x < 0) {pos[i].x = ofGetWidth();}
    if (pos[i].y > ofGetHeight()) {pos[i].y = 0;}
    if (pos[i].y < 0) {pos[i].y = ofGetHeight();}
  }

  if (vel.size() > 0) {
    if (rand() % 100 < 5) {
      ofVec2f v;
      v.set(ofRandom(-1, 1), ofRandom(-1, 1));
      vel[ofRandom(0, vel.size())] = v;
    }
  }

  while( receiver.hasWaitingMessages() )
  {
    ofxOscMessage m;
    receiver.getNextMessage( m );
    int frequency;
    if ( m.getAddress() == "/audio/start" ){
      vibrated = true;
    }
    if ( m.getAddress() == "/audio/stop" ){
      vibrated = false;
    }
    if ( m.getAddress() == "/shake" ){
      ofVec2f p;
      p.set(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()));
      pos.push_back(p);
      
      ofVec2f v;
      v.set(ofRandom(-1, 1), ofRandom(-1, 1));
      vel.push_back(v);
      
      life_span.push_back(ofRandom(100, 1000));
      code_index_list.push_back(ofRandom(0, array_length(font_code)));
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (int i=0; i<pos.size(); i++) {
    ofPushMatrix();
    if (vibrated) {
      ofRotateDeg(ofRandom(-0.3, 0.3), 0,0,1);
      ofTranslate(ofGetWidth()/2, ofGetHeight());
      ofRotateDeg(ofRandom(-0.3, 0.3), 0,0,1);
      ofTranslate(ofGetWidth()/2, -ofGetHeight());
      ofRotateDeg(ofRandom(-0.3, 0.3), 0,0,1);
      ofTranslate(-ofGetWidth(), 0);
    }
    ttf.drawString(font_code[code_index_list[i]], pos[i].x, pos[i].y);
    ofPopMatrix();
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
