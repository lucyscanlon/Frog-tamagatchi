#pragma once

#include "ofMain.h"

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
    
        void drawTadpole();
        void drawWaterGlass();
        void drawStatusBars();
        void calculateStatusBarHeight();
        void calculateTadpoleSize();
        void determineTadpoleColourFromHunger();
    
        // Variables for the tadpole drawing
        float tadPoleOriginX;
        float tadPoleOriginY;
        int tadpoleAnimatedTailStage;
        bool tailReverseAnimation;
    
        // variables to draw the water glass
        float waterGlassOriginX;
        float waterGlassOriginY;
    
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
    
		
};
