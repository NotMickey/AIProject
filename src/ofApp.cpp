#include "ofApp.h"

#include <math.h>

//--------------------------------------------------------------
void ofApp::setup()
{
	flock[flockSize - 1].m_mass = 6.0f;

	flock[flockSize - 1].m_kinematic.position = ofVec2f(1900, 1750);

	for (int i = 0; i < flockSize - 1; i++)
	{
		flock[i].m_kinematic.position += i * 5;
	}

	ofSetWindowShape(1920, 1080);
	ofSetWindowPosition(0 ,0);
}

//--------------------------------------------------------------
void ofApp::update()
{ 
	flockHandler.SimulateFlocking(flock, flockSize - 1, 2000.0f, 2.0f, 15.0f);

	flock[flockSize - 1].currentSteering = flock[flockSize - 1].Wander();

	double frameTime = ofGetLastFrameTime();

	for (int i = 0; i < flockSize; i++)
	{
		if (i == flockSize - 1)
			flock[i].Update(frameTime, 20.0f);
		else
			flock[i].Update(frameTime, 35.0f);

		if (flock[i].m_kinematic.position.x > ofGetWidth() + 10.0f)
			flock[i].m_kinematic.position.x = -10.0f;

		if (flock[i].m_kinematic.position.x < -10.0f)
			flock[i].m_kinematic.position.x = ofGetWidth() + 10.0f;

		if (flock[i].m_kinematic.position.y > ofGetHeight() + 10.0f)
			flock[i].m_kinematic.position.y = -10.0f;

		if (flock[i].m_kinematic.position.y < -10.0f)
			flock[i].m_kinematic.position.y = ofGetHeight() + 10.0f;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);  // Clear the screen with a black color

	ofColor color;

	ofSetColor(255);

	for (int i = 0; i < flockSize - 1; i++)
	{
		flock[i].Draw();
	}

	color.r = 255; color.g = 0; color.b = 0;
	ofSetColor(color);  // Set the drawing color to yellow
	flock[flockSize - 1].Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
