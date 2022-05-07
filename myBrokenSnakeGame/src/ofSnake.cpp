#include "ofSnake.h"


bool firstPosSave = false;


ofSnake::ofSnake() {

    xSpeed = 0;
    ySpeed = 0;
    startcheck = 0;
    total = 0;

    color.set(255);
}

ofSnake::~ofSnake() {

}

void ofSnake::updateSnake() {

    for (int i = 0; i <= total - 1; i++) {
        tail[i] = tail[i + 1];
        firstPosSave = true;
    }
    if (firstPosSave) {
        tail[total - 1] = myPos;
    }
    


    myPos.x = myPos.x + xSpeed * scl;
    myPos.y = myPos.y + ySpeed * scl;

    //min-max range maped to canvas
    myPos.x = ofClamp(myPos.y, 0, ofGetWidth() - scl);
    myPos.y = ofClamp(myPos.y, 0, ofGetHeight() - scl);


    
}


void ofSnake::drawSnake() {

    ofSetColor(color);

    //draw tail
    for (int i = 0; i <= total-1; i++) {
        ofDrawRectangle(tail[i].x, tail[i].y, scl, scl);
    }
    
    //draw head
    ofDrawRectangle(myPos.x, myPos.y, scl, scl);
    
}

void ofSnake::death() {
    for (int i = 0; i < total - 1; i++) {

        ofVec2f pos = tail[i];

        int maxX = ofGetWidth() - scl;
        int maxY = ofGetHeight() - scl;

        if (myPos.distance(pos) < scl && myPos.x > scl && myPos.x < maxX && myPos.y > scl && myPos.y < maxY) {
            total = 0;
            std::cout << " DEATH !" << std::endl;
        }

    }
}

void ofSnake::setDir(int x, int y) {
    xSpeed = x;
    ySpeed = y;
}



bool ofSnake::eat(ofVec2f foodPos) {

    if (myPos.distance(foodPos) < scl) {
        
        
        if (startcheck > 0) {
            total++;
            std::cout << "STARTCHECK " << startcheck << std::endl;
        }
        startcheck++;
        //total++;
        std::cout << " eat !" << std::endl;
        std::cout << "TOTAL TAIL NO " << total << std::endl;

        return true;
    }

    return false;

}
