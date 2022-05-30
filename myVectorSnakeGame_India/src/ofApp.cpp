#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // these are just local variables that you don't use
    // mySnake and myFood are initialized in the header ofApp.h already
    // actually, we are lacking a proper constructor ofApp::ofApp
	// ofSnake mySnake;
	// ofFood myFood;

	ofSetFrameRate(gameSpeed);
	ofBackground(0);

	snakeColor.set(255, 0, 255);

	mySnake.score = &score;

	myFood.elementSize = &elementSize;
	mySnake.elementSize = &elementSize;
	

    
    pointLight.setPosition(ofGetWidth()/2, ofGetHeight()/50, 600); //
    pointLight.setAmbientColor(ofFloatColor(0.0, 0.0, 0.));
    pointLight.setDiffuseColor(ofFloatColor(0.75, 0.65, 0.));
    pointLight.setSpecularColor(ofFloatColor(1., 1., 1.));
    pointLight.setPointLight();

    material.setAmbientColor(ofFloatColor(0.25f, 0.25f, 0.f));
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	myFood.scl = elementSize;

	mySnake.updateSnake();
	mySnake.death();

	if (mySnake.eat(myFood.myPos)) {
		snakeColor = myFood.foodColor;
		myFood.pickLocation();
		score += 1;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //cam.begin();
    
    //pointLight.enable();
    //material.begin();

	
	mySnake.color.set(snakeColor);
	mySnake.drawSnake();
	myFood.drawFood();

	ofSetColor(255, 255, 255);
	ofDrawBitmapString("Your score: " + ofToString(score), 20, 40);

    //ofDisableDepthTest();
    //material.end();
    //pointLight.disable();
    //ofDisableLighting();

	
    //cam.end();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
	switch (key) {
            
	case OF_KEY_LEFT: // left
        if(!goesRight){
            mySnake.setDir(-1, 0);
            goesLeft = true;
            goesRight = false;
            goesUp = false;
            goesDown = false;
        }
		break;
	case OF_KEY_RIGHT: // right
        if(!goesLeft){
            mySnake.setDir(1, 0);
            goesLeft = false;
            goesRight = true;
            goesUp = false;
            goesDown = false;
        }
		break;
	case OF_KEY_UP: // up
        if(!goesDown){
            mySnake.setDir(0, -1);
            goesLeft = false;
            goesRight = false;
            goesUp = true;
            goesDown = false;
        }
		break;
	case OF_KEY_DOWN: // down
        if(!goesUp){
            mySnake.setDir(0, 1);
            goesLeft = false;
            goesRight = false;
            goesUp = false;
            goesDown = true;
        }
		break;
	}
}






