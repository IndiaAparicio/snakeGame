#include "ofSnake.h"



ofSnake::ofSnake()
:
scl{50},
xSpeed{0},
ySpeed{0}
{

//    startcheck = 0;
//    total = 0;
//    firstPosSave = false;
    
    color.set(255);
    snake.push_back(ofVec2f(0,0)); // insert the head right away when instantiating the snake
}

ofSnake::~ofSnake() {

    snake.clear();
}

void ofSnake::updateSnake() {

    // not necessary if we work with one vector
    // the code is well done but complicated with all
    // the data and indices to keep in mind
    
//    for (int i = 0; i < tail.size(); ++i) {
//        tail[i] = tail[i + 1];
//        firstPosSave = true;
//    }
//
//    if (firstPosSave) {
//        tail[total - 1] = myPos;
//    }


    ofVec2f head = snake.front(); // get first ("head") element of the snake

    // calculate the new position based on speed/direction
    head.x = head.x + xSpeed * scl;
    head.y = head.y + ySpeed * scl;
    
    // clamp it at the window ends
    head.x = ofClamp(head.x, 0, ofGetWidth() - scl);
    head.y = ofClamp(head.y, 0, ofGetHeight() - scl);
    
    // the following two lines could be implemented better using a std:list<T> container
    // because it allows to push_front() and pop_front() elements
    auto iter = snake.begin(); // get the index ("iterator") to the first element
    snake.insert(iter, head); // insert the updated head pos at the iterator's (==index) position
    
    if (!hasEaten) {
        snake.pop_back();  // remove the last element only when the snake moves w/o having eaten
    }
    else {
        hasEaten = !hasEaten; // in case the snake has eaten, keep the last element
    }
    
    
    // well done, I use the code above, just renamed the variables slightly  : )
//    myPos.x = myPos.x + xSpeed * scl;
//    myPos.y = myPos.y + ySpeed * scl;
//
//    //min-max range maped to canvas
//    myPos.x = ofClamp(myPos.x, 0, ofGetWidth() - scl);
//    myPos.y = ofClamp(myPos.y, 0, ofGetHeight() - scl);
}


void ofSnake::drawSnake() {

    ofSetColor(color);

    // I just replaced the array with a std::vector which is more
    // easy for programming and a bit more safe
    //draw tail
//    for (int i = 0; i <= total-1; i++) {
//        ofDrawRectangle(tail[i].x, tail[i].y, scl, scl);
//    }
    
    for (int i = 0; i < snake.size(); i++) {
        
        ofDrawRectangle(snake.at(i).x, snake.at(i).y, scl, scl);
    }
    
    // not necessary any more if we just use the vector as a data structure
    // and also keep the head as part of the data structure
    //draw head
    //ofDrawRectangle(myPos.x, myPos.y, scl, scl);
    
}

void ofSnake::death() {
    
    // I did not fully understand what you are doing here
    // So I just adapted the code to my code : )
    
    /*
    for (int i = 0; i < snake.size(); i++) {
    //for (int i = 0; i < total - 1; i++) {

        ofVec2f pos = snake.at(i);

        int maxX = ofGetWidth() - scl;
        int maxY = ofGetHeight() - scl;
        
        ofVec2f myPos = snake.front(); // probably myPos == head, right?

        if (myPos.distance(pos) < scl && myPos.x > scl && myPos.x < maxX && myPos.y > scl && myPos.y < maxY) {
        //    total = 0;
            snake.clear(); // remove all elements??
            std::cout << " DEATH !" << std::endl;
        }

    }*/
}

void ofSnake::setDir(int x, int y) {
    
    xSpeed = x;
    ySpeed = y;
}



bool ofSnake::eat(ofVec2f foodPos) {


    ofVec2f head = snake.front(); // get the head
    
    if (head.distance(foodPos) < scl) {
    //if (myPos.distance(foodPos) < scl) {
        
//        if (startcheck > 0) {
//            total++;
//            std::cout << "STARTCHECK " << startcheck << std::endl;
//        }
//        startcheck++;
//        total++;
        hasEaten = true;
        
        std::cout << " eat !" << std::endl;
        //std::cout << "TOTAL TAIL NO " << total << std::endl;
        std::cout << "TOTAL TAIL NO " << snake.size()-1 << std::endl;

        return true;
    }

    return false;

}
