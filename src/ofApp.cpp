#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(900, 900);
	ofSetWindowPosition(0 ,0);

	tileGraph = tileMap.GetGraph();

	//myBoid.ShowBoidPath(true);
}

//--------------------------------------------------------------
void ofApp::update()
{ 
	double frameTime = ofGetLastFrameTime();

	myBoid.Update(frameTime, 150.0f);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(255);  // Clear the screen with a white color

	tileGraph.Draw();

	ofColor color;
	color.r = 255; color.g = 0, color.b = 0;
	ofSetColor(color);  // Set the drawing color to red

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
