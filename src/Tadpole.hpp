//
//  Tadpole.hpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 31/07/2023.
//

#ifndef Tadpole_hpp
#define Tadpole_hpp

#include <stdio.h>
#include "ofMain.h"

class Tadpole{
    public:
    
    
    // declare the variables needed to animate the tadpole
    float tadPoleOriginX;
    float tadPoleOriginY;
    
    float tadpoleState;
    bool tadpoleDead;
    
    float tadpoleLoveBarStatus;
    float tadpoleHungerBarStatus;
    
    ofColor tadpoleDarkGreen;
    ofColor tadpoleLightGreen;
    
    
    Tadpole();
        ~Tadpole();
    
        void update();
    
        void draw();
    
        void setPosition(float x, float y);
    
        void setState(float state);

        void determineTadpoleDead(bool t);
    
        void determineLoveStatusBarHeight(float loveStatus);
    
        void determineColoursOfTadpole(float hungerStatus);
    
    private:

    bool tailAnimationReversed;
    int tailAnimationStageClass;
    
    };

#endif /* Tadpole_hpp */
