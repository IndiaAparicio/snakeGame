#pragma once

#include "ofMain.h"


class ofFood {
public:

    ofFood();
    ~ofFood();

    int scl{50};
	int *elementSize = reinterpret_cast<int*>(ofGetAppPtr());

    
    ofColor foodColor{};
    ofVec2f myPos{};   

    void pickLocation();
    void drawFood();


};
