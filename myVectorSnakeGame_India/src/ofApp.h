#pragma once

#include "ofMain.h"
#include "ofSnake.h"
#include "ofFood.h"



class ofApp : public ofBaseApp{

	public:
	
		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		
    ofSnake mySnake{};
    ofFood myFood{};
    
    ofLight pointLight;
    ofMaterial material;
   // ofEasyCam cam;
    
    private:
        bool goesLeft = false;
        bool goesRight = false;
        bool goesUp = false;
        bool goesDown = false;
};
