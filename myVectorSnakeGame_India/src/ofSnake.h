#pragma once

#include "ofMain.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();

    float xSpeed;
    float ySpeed;


    int scl;

    
    bool hasEaten{false};
    
    ofColor color;

    void updateSnake();
    void drawSnake();
    void death();
    void setDir(int x, int y);
    bool eat(ofVec2f foodPos);

    
    std::vector<ofVec2f> snake; // lets use a vector ("array") for the whole snake, head and tail
    
};
