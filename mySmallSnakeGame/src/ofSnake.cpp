#include "ofSnake.h"



ofSnake::ofSnake() {

    xSpeed = 0;
    ySpeed = 0;

    color.set(255);
}

ofSnake::~ofSnake() {

}

void ofSnake::updateSnake() {

    myPos.x = myPos.x + xSpeed * scl;
    myPos.y = myPos.y + ySpeed * scl;

    //min-max range maped to canvas
    myPos.x = ofClamp(myPos.x, 0, ofGetWidth() - scl);
    myPos.y = ofClamp(myPos.y, 0, ofGetHeight() - scl);

}


void ofSnake::drawSnake() {

    ofSetColor(color);
    ofDrawRectangle(myPos.x, myPos.y, scl, scl);
    
}


void ofSnake::setDir(int x, int y) {
    xSpeed = x;
    ySpeed = y;
}



bool ofSnake::eat(ofVec2f foodPos) {

    if (myPos.distance(foodPos) < scl) {
        
        std::cout << " eat !" << std::endl;

        return true;
    }

    return false;

}
