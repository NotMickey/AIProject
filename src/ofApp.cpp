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
	myBoid.Update(steering, ofGetLastFrameTime(), 35.0f);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);  // Clear the screen with a black color
	ofSetColor(255);  // Set the drawing color to white

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
	AIProject::Kinematic kinematic;
	kinematic.position = ofVec2f(x, y);

	ofVec2f direction = (ofVec2f(x, y) - myBoid.m_kinematic.position).normalize();
	kinematic.orientation = atan2f(direction.y, direction.x);

	AIProject::DynamicSeek seek(myBoid, kinematic, 50.0f);
	AIProject::DynamicAlign align(myBoid, kinematic, PI / 180 * 75, PI / 180 * 90, PI / 180 * 2, PI / 180 * 5, 2.0f);

	AIProject::DynamicSteeringOutput linear = seek.GetSteering();
	AIProject::DynamicSteeringOutput angular = align.GetSteering();

	steering.linearAcceleration = linear.linearAcceleration;
	steering.angularAcceleration = angular.angularAcceleration;
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
