#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // these are just local variables that you don't use
    // mySnake and myFood are initialized in the header ofApp.h already
    // actually, we are lacking a proper constructor ofApp::ofApp
	//ofSnake mySnake;
	//ofFood myFood;

	ofSetFrameRate(8);
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	mySnake.updateSnake();
	mySnake.death();

	if (mySnake.eat(myFood.myPos)) {
		myFood.pickLocation();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	mySnake.drawSnake();
	myFood.drawFood();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key) {

	case OF_KEY_LEFT: // left
		mySnake.setDir(-1, 0);
		break;
	case OF_KEY_RIGHT: // right
		mySnake.setDir(1, 0);
		break;
	case OF_KEY_UP: // up
		mySnake.setDir(0, -1);
		break;
	case OF_KEY_DOWN: // down
		mySnake.setDir(0, 1);
		break;
	}
}






