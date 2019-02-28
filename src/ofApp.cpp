#include "ofApp.h"

#include <math.h>

#include "Graph/Algorithm/AStar/AStar.h"
#include "Graph/Algorithm/AStar/AStarHelper.h"

#include "Graph/Algorithm/Dijkstra/dijkstra.h"
#include "Graph/Algorithm/Dijkstra/dijkstraHelper.h"

#include "Graph/Algorithm/AStar/Heuristic/eulerHeuristic.h"
#include "Graph/Algorithm/AStar/Heuristic/manhattanHeuristic.h"

#include <chrono>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 1280);
	ofSetWindowPosition(0 ,0);

	tileGraph = tileMap.GetGraph();
}

//--------------------------------------------------------------
void ofApp::update()
{ 
	myBoid.Update(ofGetLastFrameTime(), 150.0f);
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
	int goalNode = tileMap.GetNodeFromMouseClick(ofVec2f(x, y));

	if (goalNode == -1)
		return;

	AIProject::Graph::Heuristic* complexHeuristic = new AIProject::Graph::EulerHeuristic(goalNode, tileGraph);
	
	int startNode = tileMap.GetNodeFromMouseClick(myBoid.m_kinematic.position);

	if (startNode == -1)
		startNode = 0;

	std::vector<AIProject::Graph::DirectedWeightedEdge> path = AIProject::Graph::FindPath(startNode, goalNode, tileGraph, complexHeuristic);
	
	if (path.empty())
		return;

	std::vector<ofVec2f> waypoints;

	for (int i = path.size() - 1; i >= 0; --i)
	{
		ofVec2f point = tileGraph.Localize(path[i].GetSink());

		waypoints.push_back(point);
	}

	ofVec2f point = tileGraph.Localize(startNode);

	waypoints.push_back(point);

	myBoid.SetWayPoints(waypoints);

	delete complexHeuristic;
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
