//
//  WaterGlass.cpp
//  Frog-Project
//
//  Created by Lucy Scanlon on 31/07/2023.
//

#include "WaterGlass.hpp"

WaterGlass::WaterGlass(){
    
   
    
}

WaterGlass::~WaterGlass() {
    // Nothing to do here - destroy
}

void WaterGlass::setPosition(float x, float y) {
    waterGlassOriginX = x;
    waterGlassOriginY = y;
    
}

void WaterGlass::update(){
    
}

void WaterGlass::determineCleanlinessLevel(float cleanlinessStatus) {
    cleanlinessStatusBarHeight = cleanlinessStatus;
}

void WaterGlass::draw(){
    
    if ((cleanlinessStatusBarHeight < 400) && (cleanlinessStatusBarHeight > 286)) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
        
        // sparkles
        ofSetColor(255);
        ofDrawRectangle(waterGlassOriginX + 100, waterGlassOriginY + 100, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 80, waterGlassOriginY + 100, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 93, waterGlassOriginY + 106, 6, 12);
        ofDrawRectangle(waterGlassOriginX + 93, waterGlassOriginY + 87 , 6, 12);
        
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 300, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 280, waterGlassOriginY + 300, 12, 6);
        ofDrawRectangle(waterGlassOriginX + 293, waterGlassOriginY + 306, 6, 12);
        ofDrawRectangle(waterGlassOriginX + 293, waterGlassOriginY + 287 , 6, 12);
    } else if ((cleanlinessStatusBarHeight < 286) && (cleanlinessStatusBarHeight > 210)) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
    } else if ((cleanlinessStatusBarHeight < 210) && (cleanlinessStatusBarHeight > 96)) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        ofSetColor(165, 126, 15, 30);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
    } else if (cleanlinessStatusBarHeight < 96) {
        // water in the water glass
        ofSetColor(82, 212, 255, 70);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        ofSetColor(165, 126, 15, 80);
        ofDrawRectangle(waterGlassOriginX, waterGlassOriginY, 350, 350);
        
        // water reflections on the water glass
        ofSetColor(255, 255, 255, 200);
        ofDrawRectangle(waterGlassOriginX + 300, waterGlassOriginY + 40, 10, 110);
        ofDrawRectangle(waterGlassOriginX + 40, waterGlassOriginY + 250, 10, 70);
    }
    
    // outline of the water glass
    ofSetColor(129, 62, 1, 60);
    ofDrawRectangle(waterGlassOriginX - 10, waterGlassOriginY - 40, 10, 390);
    ofDrawRectangle(waterGlassOriginX - 10, waterGlassOriginY + 350, 370, 10);
    ofDrawRectangle(waterGlassOriginX + 350, waterGlassOriginY - 40, 10, 390);
    

    
}
