#include "ofApp.h"

#include <math.h>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 720);
	ofSetWindowPosition(0 ,0);

	ofVec2f positions[18] = {ofVec2f(600, 300), ofVec2f(550, 300), ofVec2f(600, 275), ofVec2f(700, 300), ofVec2f(720, 250), ofVec2f(650, 230)
	, ofVec2f(800, 290) , ofVec2f(850, 225) , ofVec2f(1000, 275) , ofVec2f(100, 225), ofVec2f(900, 125), ofVec2f(800, 150), ofVec2f(700, 125)
	, ofVec2f(600, 100) , ofVec2f(600, 225) , ofVec2f(500, 220) , ofVec2f(550, 250) , ofVec2f(500, 280) };

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

	AIProject::Graph::Heuristic simpleHeuristic(10, simpleGraph);

	std::vector<AIProject::Graph::DirectedWeightedEdge> path = AIProject::Graph::FindPath(0, 10, simpleGraph, simpleHeuristic);

	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i].GetSource()<<"->";
	}

	std::cout << "10";
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
