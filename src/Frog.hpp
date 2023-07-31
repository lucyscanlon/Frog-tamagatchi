//
//  Frog.hpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 31/07/2023.
//

#ifndef Frog_hpp
#define Frog_hpp

#include <stdio.h>
#include "ofMain.h"

class Frog{
    public:
    
    float frogXPos;
    float frogYPos;
    
    Frog();
        ~Frog();
    
        void update();
    
        void draw();
    
        void setPosition(float x, float y);
    
    private:

    
    };

#endif /* Frog_hpp */
