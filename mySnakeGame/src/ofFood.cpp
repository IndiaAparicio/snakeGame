#include "ofFood.h"


ofFood::ofFood() {
    color.set(250, 0, 50);
}

ofFood::~ofFood() {

}


void ofFood::pickLocation() {

    int cols = floor(ofGetWidth() / scl);
    int rows = floor(ofGetHeight() / scl);

    myPos.x = floor(ofRandom(cols))*scl;
    myPos.y = floor(ofRandom(rows))*scl;

    cout << "PICKED " << myPos.x << endl;
}


void ofFood::drawFood() {
    ofSetColor(color);
    ofDrawRectangle(myPos.x,myPos.y, scl, scl);
}

