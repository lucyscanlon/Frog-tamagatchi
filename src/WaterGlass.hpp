//
//  WaterGlass.hpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 31/07/2023.
//

#ifndef WaterGlass_hpp
#define WaterGlass_hpp

#include <stdio.h>
#include "ofMain.h"

class WaterGlass{
    public:
    
    
    // declare the variables needed to animate the tadpole
    float waterGlassOriginX;
    float waterGlassOriginY;
    
    float cleanlinessStatusBarHeight;

    
    
    WaterGlass();
        ~WaterGlass();
    
        void update();
    
        void draw();
    
        void setPosition(float x, float y);
    
        void determineCleanlinessLevel(float cleanlinessStatus);

        
    
    private:

    
    };

#endif /* WaterGlass_hpp */
