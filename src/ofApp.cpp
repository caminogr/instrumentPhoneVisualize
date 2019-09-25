#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetColor(255);
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
  for (int i = this->life_span.size() - 1; i >= 0; i--) {
    this->life_span[i] -= 1;
    if (life_span[i] == 0) {
      this->life_span.erase(this->life_span.begin() + i);
      this->pos.erase(this->pos.begin() + i);
      this->vel.erase(this->vel.begin() + i);
      this->code_index_list.erase(this->code_index_list.begin() + i);
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
      frequency = m.getArgAsInt32(0);
      cout << "frequency: " << frequency << endl;
      vibrated = true;
    }
    if ( m.getAddress() == "/audio/stop" ){
      vibrated = false;
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (int i=0; i<pos.size(); i++) {
    ofPushMatrix();
    if (vibrated) {
      ofRotateDeg(ofRandom(0, 0.4), 0,0,1);
    }
    ttf.drawString(font_code[code_index_list[i]], pos[i].x, pos[i].y);
    ofPopMatrix();
  }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  ofVec2f p;
  p.set(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()));
  pos.push_back(p);
  
  ofVec2f v;
  v.set(ofRandom(-1, 1), ofRandom(-1, 1));
  vel.push_back(v);
  
  life_span.push_back(ofRandom(1000, 1000000));
  code_index_list.push_back(ofRandom(0, array_length(font_code)));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//  ofLog() << "mouseMoved";
//  vibrated = true;
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
