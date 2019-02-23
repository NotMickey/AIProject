#include "ofApp.h"

#include <math.h>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 720);
	ofSetWindowPosition(0 ,0);

	ofVec2f positions[18] = {ofVec2f(600, 300), ofVec2f(550, 300), ofVec2f(600, 350), ofVec2f(700, 300), ofVec2f(730, 370), ofVec2f(670, 500)
	, ofVec2f(750, 300) , ofVec2f(125, 550) , ofVec2f(1200, 600) , ofVec2f(569, 111), ofVec2f(232, 346), ofVec2f(124, 455), ofVec2f(900, 650)
	, ofVec2f(890, 540) , ofVec2f(100, 750) , ofVec2f(650, 700) , ofVec2f(120, 345) , ofVec2f(550, 900) };

	int nodes[18];

	for (int i = 0; i < 18; i++)
	{
		nodes[i] = simpleGraph.AddNode(positions[i]);
	}

	simpleGraph.AddEdge(0, 1, 5);
	simpleGraph.AddEdge(1, 2, 10);
	simpleGraph.AddEdge(0, 2, 5);
	simpleGraph.AddEdge(2, 5, 35);
	simpleGraph.AddEdge(0, 3, 30);
	simpleGraph.AddEdge(3, 6, 70);
	simpleGraph.AddEdge(3, 4, 20);
	simpleGraph.AddEdge(4, 7, 35);
	simpleGraph.AddEdge(7, 6, 20);
	simpleGraph.AddEdge(7, 8, 5);
	simpleGraph.AddEdge(8, 9, 45);
	simpleGraph.AddEdge(9, 10, 10);
	simpleGraph.AddEdge(11, 10, 70);
	simpleGraph.AddEdge(12, 11, 45);
	simpleGraph.AddEdge(13, 12, 50);
	simpleGraph.AddEdge(14, 13, 10);
	simpleGraph.AddEdge(5, 14, 15);
	simpleGraph.AddEdge(14, 15, 27);
	simpleGraph.AddEdge(15, 16, 10);
	simpleGraph.AddEdge(16, 17, 15);
	simpleGraph.AddEdge(15, 17, 35);

	AIProject::Graph::Heuristic simpleHeuristic(17, simpleGraph);

	std::vector<AIProject::Graph::DirectedWeightedEdge> path = AIProject::Graph::FindPath(0, 17, simpleGraph, simpleHeuristic);

	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i].GetSource();
	}
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
