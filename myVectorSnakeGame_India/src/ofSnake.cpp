#include "ofSnake.h"



ofSnake::ofSnake()
:
scl{50},
xSpeed{0},
ySpeed{0}
{
    
    color.set(255);
    snake.push_back(ofVec2f(0,0)); // insert the head right away when instantiating the snake
}

ofSnake::~ofSnake() {

    snake.clear();
}

void ofSnake::updateSnake() {


    ofVec2f head = snake.front();
    // get first ("head") element of the snake
    //.front gibt eine referenz raus zum ersten element im Vector.
    // Hier ist das jetzt gerade (0,0), da es im constructor definiert wurde

    // calculate the new position based on speed/direction
    head.x = head.x + xSpeed * *elementSize;
    head.y = head.y + ySpeed * *elementSize;
    
    // clamp it at the window ends
    //head.x = ofClamp(head.x, 0, ofGetWidth() - scl);
    //head.y = ofClamp(head.y, 0, ofGetHeight() - scl);
    
    if(head.x > ofGetWidth()-*elementSize){head.x = 0;}
    else if(head.x < 0){head.x = ofGetWidth()-*elementSize;}
    if(head.y >= ofGetHeight()){head.y = 0;}
    else if(head.y <= 0-*elementSize){head.y = ofGetHeight()-*elementSize;}
    
    // the following two lines could be implemented better using a std:list<T> container
    // because it allows to push_front() and pop_front() elements
    
    
    auto iter = snake.begin(); // get the index ("iterator") of the first element
    snake.insert(iter, head); // insert the updated head pos at the iterator's (==index) position
    
    if (!hasEaten) {
        snake.pop_back();  // remove the last element only when the snake moves w/o having eaten
		
    }
    else {
        hasEaten = !hasEaten; // in case the snake has eaten, keep the last element
		ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }
    
}


void ofSnake::drawSnake() {

	ofSetColor(color);
    
    for (int i = 0; i < snake.size(); i++) {
        
        //ofDrawBox(snake.at(i).x, snake.at(i).y, 0., scl, scl, scl/3);
        ofDrawRectangle(snake.at(i).x, snake.at(i).y, *elementSize, *elementSize);
    }


    
    
}

void ofSnake::death() {
    ofVec2f head = snake.front(); // get the head
    
    for(int i = 2; i < snake.size(); i++){
        if (head.distance(snake[i]) < *elementSize){
            
            snake.clear();
            snake.push_back(head); // insert the head right away when instantiating the snake

			*score = 0;
        }
    }
    
}

void ofSnake::setDir(int x, int y) {
    
    xSpeed = x;
    ySpeed = y;
}



bool ofSnake::eat(ofVec2f foodPos) {


    ofVec2f head = snake.front(); // get the head
    
    if (head.distance(foodPos) < *elementSize) {

        hasEaten = true;
        
        
        std::cout << " eat !" << std::endl;
        std::cout << "TOTAL TAIL NO " << snake.size()-1 << std::endl;

        return true;
    }

    return false;

}
