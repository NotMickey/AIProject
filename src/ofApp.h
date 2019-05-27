#pragma once

#include "ofMain.h"

#include "Character/Docile/docileBoid.h"
#include "Character/Patrol/patrolBoid.h"

#include "DecisionMaking/Blackboard/blackboard.h"

#include "Graph/TileMap/tileMap.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		AIProject::Graph::TileMap tileMap = AIProject::Graph::TileMap(30, 30, 5.0f, ofVec2f(0.0f, 0.0f));
		AIProject::Graph::DirectedWeightedGraph tileGraph;

		//AIProject::Boid myBoid = AIProject::Boid(ofVec2f(100.0f, 100.0f));

		std::shared_ptr<AIProject::Boid> boid;

		std::shared_ptr<AIProject::DecisionMaking::Blackboard> blackboard;
		std::shared_ptr<AIProject::Boid> patrolBoid;
		
};
