#include "ofApp.h"

#include <math.h>

#include "Graph/Algorithm/AStar/AStar.h"
#include "Graph/Algorithm/AStar/AStarHelper.h"

#include "Graph/Algorithm/AStar/Heuristic/eulerHeuristic.h"
#include "Graph/Algorithm/AStar/Heuristic/manhattanHeuristic.h"

#include "Graph/TileMap/tileMap.h"

#include <chrono>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 720);
	ofSetWindowPosition(0 ,0);

	AIProject::Graph::TileMap tileMap(50, 20, 5.0f,ofVec2f(0.0f, 0.0f));
	tileGraph = tileMap.GetGraph();


	AIProject::Graph::Heuristic* complexHeuristic = new AIProject::Graph::ManhattanHeuristic(2123, 20, tileGraph);
	delete complexHeuristic;
}

//--------------------------------------------------------------
void ofApp::update()
{ 
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);  // Clear the screen with a black color
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
