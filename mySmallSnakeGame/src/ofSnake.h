#pragma once

#include "ofMain.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();

    float xSpeed;
    float ySpeed;

    int total;
    int startcheck = 0;
    
    int scl = 50;

    ofColor color;

    void updateSnake();
    void drawSnake();
    void death();
    void setDir(int x, int y);
    bool eat(ofVec2f foodPos);

    ofVec2f myPos{ 0,0 };
    ofVec2f tail[200];
    
    
};
