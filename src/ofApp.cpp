#include "ofApp.h"

#include <math.h>

#include "AILogic/Dynamic/DynamicSeek/dynamicSeek.h"
#include "AILogic/Dynamic/DynamicAlign/dynamicAlign.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	steering.linearAcceleration = ofVec2f();
	steering.angularAcceleration = 0.0f;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (move == 0)
	{
		if (myBoid.m_kinematic.position.x < 1000.0f)
		{
			myBoid.m_kinematic.position.x += 50.0f * ofGetLastFrameTime();
		}
		else
		{
			myBoid.m_kinematic.orientation = PI / 180 * 270.0f;
			move = 1;
		}
	}
	else if (move == 1)
	{
		if (myBoid.m_kinematic.position.y > 0.0f)
		{
			myBoid.m_kinematic.position.y -= 50.0f * ofGetLastFrameTime();
		}
		else
		{
			myBoid.m_kinematic.orientation = PI / 180 * 180.0f;
			move = 2;
		}
	}
	else if (move == 2)
	{
		if (myBoid.m_kinematic.position.x > 0.0f)
		{
			myBoid.m_kinematic.position.x -= 50.0f * ofGetLastFrameTime();
		}
		else
		{
			myBoid.m_kinematic.orientation = PI / 180 * 90.0f;
			move = 3;
		}
	}
	else
	{
		if (myBoid.m_kinematic.position.y < 750.0f)
		{
			myBoid.m_kinematic.position.y += 50.0f * ofGetLastFrameTime();
		}
		else
		{
			myBoid.m_kinematic.orientation = PI / 180 * 0.0f;
			move = 0;
		}
	}

	myBoid.Update(steering, ofGetLastFrameTime(), 35.0f);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);  // Clear the screen with a black color

	ofColor color;
	color.r = 255; color.g = 255, color.b = 0;
	ofSetColor(color);  // Set the drawing color to yellow

	myBoid.Draw();
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
{
}

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
