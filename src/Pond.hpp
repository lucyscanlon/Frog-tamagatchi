//
//  Pond.hpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 03/08/2023.
//

#ifndef Pond_hpp
#define Pond_hpp

#include <stdio.h>

#include "ofMain.h"

class Pond{
    public:
    
    float pondXPos;
    float pondYPos;
    
    Pond();
        ~Pond();
    
        void update();
    
        void draw();
    
        void setPosition(float x, float y);
    
    private:

    
    };

#endif /* Pond_hpp */
