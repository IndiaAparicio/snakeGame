#pragma once

#include "ofMain.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();

    float xSpeed;
    float ySpeed;

//    int total;
//    int startcheck;
    
    int scl;
//    bool firstPosSave;
    
    bool hasEaten{false};
    
    ofColor color;

    void updateSnake();
    void drawSnake();
    void death();
    void setDir(int x, int y);
    bool eat(ofVec2f foodPos);

    //ofVec2f myPos{};
    //ofVec2f tail[200]; // I have changed this into a vector below that stores head and tail
    
    std::vector<ofVec2f> snake; // lets use a vector ("array") for the whole snake, head and tail
    
};
