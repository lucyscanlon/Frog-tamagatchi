#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Frog.hpp"
#include "Tadpole.hpp"
#include "WaterGlass.hpp"
#include "Pond.hpp"

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
        void drawStatusBars();
        void calculateStatusBarHeight();
        void drawLifeSpanBar();
        void checkifTadpoleIsDead();
        void drawDeadText();
        void drawOpenScreenOfGame();
        void drawEndingScreen();
        void drawStatsBar();
        void increaseStats();
        void resetStats();
    
        // Variables for the status bars
        float statusBarsOriginX;
        float statusBarsOriginY;
        float statusBarHeight;
        float hungerStatusBarDecrease;
        float cleanlinessStatusBarDecrease;
        float loveStatusBarDecrease;
        float hungerPressed;
        float cleanlinessPressed;
        float lovePressed;
        float hungerStatusBarHeight;
        float cleanlinessStatusBarHeight;
        float loveStatusBarHeight;

        // stores the light and dark green colour of the tadpole, this changes with the hunger level
        ofColor tadpoleDarkColour;
        ofColor tadpoleLightColour;
        // custom font
        ofTrueTypeFont secondFont;
        ofTrueTypeFont smallerFont;
        ofTrueTypeFont smallestFont;
        ofTrueTypeFont tinyFont;
    
        // variable that controls the length of the lifespan bar
        float lifespanBarLength;
    
        // variable to control if the tadpole is dead or alive
        bool isTadpoleDead;
        int daysLived;
    
        int stageOfGame;
        ofImage openingScreenBackground;
        
        // classes
        Tadpole gameTadpole;
        WaterGlass gameGlass;
    
        Frog gameFrog;
    
        Pond gamePond;
    
        // scores
        int gamesPlayedStat;
        int TadpolesSavedStat;
        int HighestLifespan;
    
        bool addNewScore;
        
};
