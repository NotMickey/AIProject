#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(900, 900);
	ofSetWindowPosition(0 ,0);

	tileGraph = tileMap.GetGraph();

	boid = std::make_shared<AIProject::DocileBoid>(AIProject::DocileBoid(ofVec2f(30.0f, 200.0f), ofColor(0, 0, 255, 255)));
	(dynamic_cast<AIProject::DocileBoid*>(&(*boid)))->InitBrain(boid, tileMap);

	blackboard = std::make_shared<AIProject::DecisionMaking::Blackboard>(AIProject::DecisionMaking::Blackboard(boid, tileMap));

	patrolBoid = std::make_shared<AIProject::PatrolBoid>(AIProject::PatrolBoid(ofVec2f(450.0f, 300.0f)));
	(dynamic_cast<AIProject::PatrolBoid*>(&(*patrolBoid)))->InitBrain(1, patrolBoid, tileMap, blackboard);
}

//--------------------------------------------------------------
void ofApp::update()
{ 
	double frameTime = ofGetLastFrameTime();

	//myBoid.Update(frameTime, 150.0f);
	boid->Update(frameTime, 150.0f);
	patrolBoid->Update(frameTime, 150.0f);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(255);  // Clear the screen with a white color

	tileGraph.Draw();

	//myBoid.Draw();
	boid->Draw();

	patrolBoid->Draw();
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
