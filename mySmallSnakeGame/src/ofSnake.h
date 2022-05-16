#pragma once

#include "ofMain.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();

    float xSpeed;
    float ySpeed;
    
    int scl = 50;

    ofColor color;

    void updateSnake();
    void drawSnake();
    void setDir(int x, int y);
    bool eat(ofVec2f foodPos);

    ofVec2f myPos{ 0,0 };

    
    
};
