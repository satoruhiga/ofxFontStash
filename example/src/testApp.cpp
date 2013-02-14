#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(22, 22, 22, 255);

	font.setup("OpenSans.ttf", 1.3); //load verdana font, set lineHeight to be 130%

}


//--------------------------------------------------------------
void testApp::draw(){
	
	float x = 50 + mouseX * 0.1;
	float y = 50;
	
	string demoText = "This is my text in verdana font.";
	float fontSize = 22.0f;
		
	
	// simple demo //////////////////////////////////////////////////////////
	
	drawPoint(x, y);		//draw insertion point	
	
	ofSetColor(255);
	font.draw(
				  demoText,	//text to draw
				  fontSize,	//font size
				  x,		//x coord where to draw
				  y			//y coord where to draw
			  );

	
	// bounding box demo ///////////////////////////////////////////////////
	
	ofSetColor(255, 0, 0, 64);
	ofRectangle bbox = font.getBoundingBoxSize( demoText, fontSize, x, y);
	ofRect( bbox );
		
	
	// draw multiline text /////////////////////////////////////////////////
	
	y = 150;
	drawPoint(x, y);		//draw insertion point	
	
	ofSetColor(255);
	string s = (string)"this paragraph has" + "\n" + "multiple lines.";
	font.drawMultiLine( s,  fontSize, x, y);
	
	
	// multiline bounding box demo ///////////////////////////////////////////////////
	
	ofSetColor(255, 0, 0, 64);
	bbox = font.getBoundingBoxSizeMultiLine( s, fontSize, x, y);
	ofRect( bbox );

	
	// batch drawing, optimized for multiple drawing calls /////////////////
	
	y = 250;
	drawPoint(x, y);		//draw insertion point	
	
	ofSetColor(255);
	font.begin();
	for (int i = 0; i < 11; i++){
		font.draw("my line #" + ofToString(i+1), fontSize, x, y + i * fontSize, false );
	}
	font.end();
	
}

void testApp::drawPoint(float x, float y){
	
	ofSetColor(0, 255, 0, 128);	
	ofCircle(x, y, 2);
}
