#pragma once

#include "ofMain.h"


class ofSnake {

public:

	ofSnake();
	~ofSnake();

	float xSpeed;
	float ySpeed;
	int scl;
	int total;
	int startcheck = 0;

	ofColor color;

	void updateSnake();
	void drawSnake();
	void death();
	void setDir(int x, int y);
	bool eat(ofVec2f foodPos);

	ofVec2f myPos{ 0,0 };
	//cannot declare empty array/ c++ cannot change size of array in runtime apperently
	ofVec2f tail[200];
	
};


class ofFood {
public: 

	ofFood();
	~ofFood();

	int scl;
	ofColor color;

	ofVec2f myPos{};

	void pickLocation();
	void drawFood();


};


class ofApp : public ofBaseApp{

	public:
	


		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		
		ofSnake mySnake;
		ofFood myFood;
};
