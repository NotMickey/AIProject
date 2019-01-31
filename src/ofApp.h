#pragma once

#include "ofMain.h"

#include "Character/boid.h"
#include "AILogic/steeringBase.h"

#include "AILogic/Flocking/flocking.h";

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

		int flockSize = 10;

		AIProject::Boid flock[10];
		AIProject::Flocking flockHandler;
};
