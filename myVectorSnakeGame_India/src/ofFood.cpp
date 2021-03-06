#include "ofFood.h"


ofFood::ofFood() {
    
    foodColor.set(250, 0, 50);
    
    // set the first position of food randomly
    // otherwise food and snake have the same pos at (0,0) which leads to an error
    // in "snake's eat function > startcheck is increased w/o reason"
    pickLocation();
}

ofFood::~ofFood() {

}


void ofFood::pickLocation() {


    int cols = floor(ofGetWidth() / scl);
    int rows = floor(ofGetHeight() / scl);

    myPos.x = floor(ofRandom(cols))*scl;
    myPos.y = floor(ofRandom(rows))*scl;

    cout << "PICKED " << myPos.x << endl;
	foodColor.set(ofRandom(255), ofRandom(255), ofRandom(255));
}


void ofFood::drawFood() {
    
    ofSetColor(foodColor);
    ofDrawRectangle(myPos.x,myPos.y, scl, scl);
    //ofDrawBox(myPos.x,myPos.y, .0, scl, scl, scl/3);
}

