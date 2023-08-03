#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    // load the fonts
    secondFont.load("SecondFont.ttf", 30);
    smallerFont.load("SecondFont.ttf", 24);
    smallestFont.load("SecondFont.ttf", 12);
    tinyFont.load("SecondFont.ttf", 9);
    
    // set the initial values for the status bars
    statusBarHeight = -38;
    hungerStatusBarDecrease = -38;
    cleanlinessStatusBarDecrease = -38;
    loveStatusBarDecrease = -38;
    hungerPressed = 0;
    cleanlinessPressed = 0;
    lovePressed = 0;
    hungerStatusBarHeight = 380;
    cleanlinessStatusBarHeight = 380;
    loveStatusBarHeight = 380;

    // set the initial value of the lifespan bar to 0
    lifespanBarLength = 0;
    
    // this variables decides whether the tadpole is dead or alive
    // set it to alive at the start of the game
    isTadpoleDead = false;
    
    // this values holds the number of days the tadpole has been alive
    // this amount is determined from how far into the lifespan it is
    // set it to 0 at the start of the game
    daysLived = 0;
   
    // stage of game is 0 - this is the opening screen
    stageOfGame = 0;
    
    // load the image for the background of the opening screen
    openingScreenBackground.load("openingscreenbackground2.jpg");
    
    // set the positions for each class e.g. frog, tadpole, glass and pond
    gameTadpole.setPosition(650, 500);
    gameGlass.setPosition(540, 280);
    gameFrog.setPosition(1200, 980);
    gamePond.setPosition(400, 500);
    
    // set the initial score stats to 0 at the start of the game
    gamesPlayedStat = 0;
    TadpolesSavedStat = 0;
    HighestLifespan = 0;
    
    // this boolean decides whether its time to add a new score or not
    // this insures each game is only counted once in the stats
    addNewScore = true;


}

//--------------------------------------------------------------
void ofApp::update(){
    
    // during the game, this calls on the class to continuously animate the tadpole
    if (stageOfGame == 1) {
        if(isTadpoleDead == false) {
            gameTadpole.update();
        }
        
        
        // increase the lifespan bar as time increases.
        // Stop when it reaches 600 which is the completion of the game
        if (isTadpoleDead == false) {
            if (lifespanBarLength < 600) {
               if ((ofGetFrameNum() % 100) == 0) {
                   lifespanBarLength = lifespanBarLength + 20;
                   daysLived = lifespanBarLength / 20;
                   
                   // if the game has been completed move to the ending screen
                   if (lifespanBarLength == 600) {
                       stageOfGame = 3;
                       // increase the stats to show game has been completed
                       increaseStats();
                       
                   }
               }
           }
        }
        
        // check if the tadpole has died due to any of the status bars reaching zero
        checkifTadpoleIsDead();
    }
    
    
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // set the background colour
    ofBackground(244, 217, 191);
    
    // if the stats get too low add a red overlay to the screen to warn the player
    if ((hungerStatusBarHeight < 114) || (cleanlinessStatusBarHeight < 114) || (loveStatusBarHeight < 114)) {
        ofSetColor(255, 104, 104, 20);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    // make the red screen even darker when one point away from end of game
    if ((hungerStatusBarHeight < 76) || (cleanlinessStatusBarHeight < 76) || (loveStatusBarHeight < 76)) {
        ofSetColor(255, 104, 104, 30);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    // This controls what is displayed as the player moves through each stage of the game
    // stage 0 - the opening screen
    if (stageOfGame == 0) {
        ofSetColor(255);
        // display the opening screen background
        openingScreenBackground.draw(0, 0, ofGetWidth(), ofGetHeight());
        // call the function to draw the text display of the opening screen
        drawOpenScreenOfGame();
    } else if (stageOfGame == 1) {
        // stage 1 - the tadpole game
        // call the function to calculate the status bars
        calculateStatusBarHeight();
        // draw the statistics bar at the bottom of the screen
        drawStatsBar();
        // if the tadpole is alive - draw the stats bars
        if(isTadpoleDead == false) {
            drawStatusBars();
        } else {
            // if the tadpole is dead - call the function to draw the text for the
            // tadpole being dead as its the end of the game
            drawDeadText();
        }
        // draw life span bar
        drawLifeSpanBar();
        // set the values and draw the tadpole
        gameTadpole.determineTadpoleDead(isTadpoleDead);
        gameTadpole.determineLoveStatusBarHeight(loveStatusBarHeight);
        gameTadpole.determineColoursOfTadpole(hungerStatusBarHeight);
        gameTadpole.draw();
        // set the values and draw the waterglass
        gameGlass.determineCleanlinessLevel(cleanlinessStatusBarHeight);
        gameGlass.draw();
        ofSetColor(194, 147, 107);
        smallestFont.drawString("Press 1, 2 and 3 to feed, clean and love your tadpole", 210, 200);
    } else if (stageOfGame == 3) {
        // stage 3 - the ending screen, if the player has looked after their tadpole enough to
        // complete the game.
        // call the function to draw the ending screen text
        drawEndingScreen();
        // draw the pond
        gamePond.draw();
        // draw the frog and scale it down so it can sit on the lily pad on the pond
        ofPushMatrix();
            ofScale(0.5);
            gameFrog.draw();
        ofPopMatrix();
        // draw the statistics bar at the bottom of the screen
        drawStatsBar();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // in the opening screen, if the player presses enter, start the game (move to stage 1)
    if(stageOfGame == 0) {
        if(key == 13) {
            stageOfGame = 1;
        }
        
        // if the game is in stage 1, listen for the players to press 1, 2, 3
        // these key presses increase the status bars
    } else if (stageOfGame == 1) {
        if(isTadpoleDead == false) {
            if(key == '1') {
                hungerStatusBarDecrease = hungerStatusBarDecrease - 38;
                if (hungerStatusBarHeight < 380) {
                    hungerPressed++;
                    hungerStatusBarHeight = hungerStatusBarHeight + 38;
                }
            }
            
            if (key == '2') {
                cleanlinessStatusBarDecrease = cleanlinessStatusBarDecrease - 38;
                if (cleanlinessStatusBarHeight < 380) {
                    cleanlinessPressed++;
                    cleanlinessStatusBarHeight = cleanlinessStatusBarHeight + 38;
                }
            }
            
            if(key == '3') {
                loveStatusBarDecrease = loveStatusBarDecrease - 38;
                if (loveStatusBarHeight < 380) {
                    lovePressed++;
                    loveStatusBarHeight = loveStatusBarHeight + 38;
                }
            }
            
        }
        
        // if the tadpole has died then wait for the user to press enter to restart the game
        if (isTadpoleDead == true && key == 13) {
            stageOfGame = 0;
            // reset the starting statistics to reset the game
            resetStats();
         
        }
        
        // if the tadpole has become a frog, wait for the user to press enter to
        // play again
    } else if (stageOfGame == 3) {
        if(key == 13) {
            stageOfGame = 0;
            // reset the game and the statistics
            resetStats();
           
        }
    }
    

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
void ofApp::mousePressed(int x, int y, int button){

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

void ofApp::drawStatusBars() {
    // this function draws the status bars for the tadpole
    statusBarsOriginX = 138;
    statusBarsOriginY = 250;
    
    // draw the status bar colours
    ofSetColor(175, 159, 255, 100);
    ofDrawRectangle(statusBarsOriginX, statusBarsOriginY + 380, 60, - hungerStatusBarHeight);
    
    ofSetColor(126, 197, 134, 100);
    ofDrawRectangle(statusBarsOriginX + 110, statusBarsOriginY + 380, 60, - cleanlinessStatusBarHeight);
    
    ofSetColor(255, 154, 203, 100);
    ofDrawRectangle(statusBarsOriginX + 220, statusBarsOriginY + 380, 60, - loveStatusBarHeight);
    
    // draw the status bar outline
    ofSetColor(129, 62, 1, 60);
    ofDrawRectangle(statusBarsOriginX, statusBarsOriginY - 10, 60, 10);
    ofDrawRectangle(statusBarsOriginX, statusBarsOriginY + 380, 60, 10);
    ofDrawRectangle(statusBarsOriginX - 10, statusBarsOriginY - 10, 10, 400);
    ofDrawRectangle(statusBarsOriginX + 60, statusBarsOriginY - 10, 10, 400);
    
    ofDrawRectangle(statusBarsOriginX + 110, statusBarsOriginY - 10, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 110, statusBarsOriginY + 380, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 100, statusBarsOriginY - 10, 10, 400);
    ofDrawRectangle(statusBarsOriginX + 170, statusBarsOriginY - 10, 10, 400);
    
    ofDrawRectangle(statusBarsOriginX + 220, statusBarsOriginY - 10, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 220, statusBarsOriginY + 380, 60, 10);
    ofDrawRectangle(statusBarsOriginX + 210, statusBarsOriginY - 10, 10, 400);
    ofDrawRectangle(statusBarsOriginX + 280, statusBarsOriginY - 10, 10, 400);
    
    
    // draw the text labels for the status bars
    ofSetColor(175, 159, 255);
    ofPushMatrix();
    ofTranslate(182, 616);
    ofRotateZ(270);
    secondFont.drawString("Hunger", 0, 0);
    ofPopMatrix();
    
    ofSetColor(126, 197, 134);
    ofPushMatrix();
    ofTranslate(292, 616);
    ofRotateZ(270);
    secondFont.drawString("Cleaniness", 0, 0);
    ofPopMatrix();
    
    ofSetColor(225, 137, 180);
    ofPushMatrix();
    ofTranslate(402, 616);
    ofRotateZ(270);
    secondFont.drawString("Love", 0, 0);
    ofPopMatrix();
}

void ofApp::calculateStatusBarHeight() {
    
    // uses modulo to decrease the status bars over time
    if(isTadpoleDead == false) {
        if ((ofGetFrameNum() % 80) == 0) {
            // this makes sure the bars stop decreasing once they hit zero. it also uses
            // the amount the user has pressed the button to increase the stautus bar.
            if (statusBarHeight < (380 + (hungerPressed * 38))) {
                // decreases by 10% each time
                hungerStatusBarDecrease = hungerStatusBarDecrease + 38;
                hungerStatusBarHeight = hungerStatusBarHeight - 38;
            }
            
            if (statusBarHeight < (380 + (cleanlinessPressed * 38))) {
                cleanlinessStatusBarDecrease = cleanlinessStatusBarDecrease + 38;
                cleanlinessStatusBarHeight = cleanlinessStatusBarHeight - 38;
            }
            
            if (statusBarHeight < (380 + (lovePressed * 38))) {
                loveStatusBarDecrease = loveStatusBarDecrease + 38;
                loveStatusBarHeight = loveStatusBarHeight - 38;
            }
            
            statusBarHeight = statusBarHeight + 38;
        }
    }
    
}


void ofApp::drawLifeSpanBar() {
    // the function to draw the lifespan of the tadpole/frog
    ofSetColor(255, 239, 160, 150);
    ofDrawRectangle(190, 80, lifespanBarLength, 60);
    
    // draw the border around the life span bar
    ofSetColor(129, 62, 1, 60);
    ofDrawRectangle(190, 70, 600, 10);
    ofDrawRectangle(190, 140, 600, 10);
    ofDrawRectangle(180, 70, 10, 80);
    ofDrawRectangle(790, 70, 10, 80);
    
    ofSetColor(224, 179, 141);
    secondFont.drawString("Lifespan", 205, 125);
    
}

void ofApp::checkifTadpoleIsDead() {
    // this function checks if any of the status bars have hit 0 which means
    // the tadpole has died
    // if it has died increase the game stats
    if (cleanlinessStatusBarHeight == 0) {
        isTadpoleDead = true;
        increaseStats();
    }
    
    if (hungerStatusBarHeight == 0) {
        isTadpoleDead = true;
        increaseStats();
    }
    
    if (loveStatusBarHeight == 0) {
        isTadpoleDead = true;
        increaseStats();
    }
}

void ofApp::drawDeadText() {
    // draw the text which displays when the tadpole had died
    // convert the number of days lived, which is determined from the length
    // of the lifespan bar, to a string so it can be displayed
    string numberOfDaysLived = to_string(daysLived);
    ofSetColor(53, 53, 53, 200);
    smallerFont.drawString("Game over", 160, 310);
    
    smallestFont.drawString("Unfortunately you didn't look after", 90, 350);
    smallestFont.drawString("your tadpole well enough", 135, 375);
    smallestFont.drawString("and it has died", 190, 400);
    
    
    smallestFont.drawString("Your tadpole lived for: ", 145, 480);
    smallerFont.drawString(numberOfDaysLived + " days", 200, 540);
    
    smallestFont.drawString("Press enter to try again", 140, 600);
}

void ofApp::drawOpenScreenOfGame() {
    
    // the text for the opening screen of the game
    ofSetColor(119, 144, 86, 200);
    secondFont.drawString("Welcome to Tadpole", 250, 190);
    secondFont.drawString("Tamagotchi", 360, 230);
    
    ofSetColor(53, 53, 53, 150);
    smallestFont.drawString("We need your help! The local pond has become", 270, 300);
    smallestFont.drawString("overgrown with tadpoles. We are giving a tadpole", 235, 325);
    smallestFont.drawString("to each person in town to look after. Once they grow", 230, 350);
    smallestFont.drawString("and become frogs they can be transported to the", 255, 375);
    smallestFont.drawString("new pond across town.", 390, 400);
    
    smallestFont.drawString("Tadpoles need lots of love and care to stay alive.", 250, 455);
    smallestFont.drawString("They also need to be fed and their water needs", 270, 480);
    smallestFont.drawString("to be clean. Best of luck!", 370, 505);
    
    ofSetColor(119, 144, 86, 200);
    smallerFont.drawString("Press enter to start", 305, 600);
}

void ofApp::drawEndingScreen() {
    
    // the text for the ending screen of the game
    ofSetColor(119, 144, 86, 200);
    secondFont.drawString("Congratulations you", 220, 150);
    secondFont.drawString("saved your Tadpole!", 240, 200);
    
    ofSetColor(53, 53, 53, 150);
    smallestFont.drawString("Your Tadpole has transformed into a frog and", 250, 275);
    smallestFont.drawString("is ready to move to the new pond. Say goodbye!", 250, 300);
    smallestFont.drawString("Press enter to play again and see how many Tadpoles", 220, 325);
    smallestFont.drawString("you can save", 435, 350);
    
    string NumberofTadpolesSavedString = to_string(TadpolesSavedStat);
    smallestFont.drawString("Number of Tadpoles saved: " + NumberofTadpolesSavedString , 340, 420);
    
}

void ofApp::drawStatsBar() {
    // this function draws the statistics bar at the bottom of the screen
    ofSetColor(194, 147, 107);
    ofDrawRectangle(0, ofGetHeight() - 40, ofGetWidth(), 40);
    
    // convert the int values of the scores to strings
    ofSetColor(255);
    string gamesPlayedStatString = to_string(gamesPlayedStat);
    string TadpolesSavedString = to_string(TadpolesSavedStat);
    string highestlifespanString = to_string(HighestLifespan);
    
    // display the scores
    tinyFont.drawString("Games Played: " + gamesPlayedStatString, 20, ofGetHeight() - 15);
    tinyFont.drawString("Tadpoles Saved: " + TadpolesSavedString, ofGetWidth() - 170, ofGetHeight() - 15);
    tinyFont.drawString("Longest Lifespan: " + highestlifespanString, (ofGetWidth() / 2) - 70, ofGetHeight() - 15);
}


void ofApp::increaseStats() {
    // this function increases the relevant statistics at the end of the each game
    if (addNewScore == true && isTadpoleDead == true) {
        gamesPlayedStat = gamesPlayedStat + 1;
        // this stops the stats from continuously increasing due to the
        // function being called repetitively
        addNewScore = false;
    } else if (addNewScore == true && isTadpoleDead == false) {
        gamesPlayedStat = gamesPlayedStat + 1;
        TadpolesSavedStat = TadpolesSavedStat + 1;
        addNewScore = false;
    }
    
    // if the lifespan of the current tadpole is higher than the lifespan in
    // the highest score, then the current score replaces this as the new high score
    if(daysLived > HighestLifespan) {
        HighestLifespan = daysLived;
    }
}

void ofApp::resetStats() {
    // resets the starting values so the player can start again
    // set the initial value of the variable which decreases the status bars
    statusBarHeight = -38;
    hungerStatusBarDecrease = -38;
    cleanlinessStatusBarDecrease = -38;
    loveStatusBarDecrease = -38;
    
    hungerPressed = 0;
    cleanlinessPressed = 0;
    lovePressed = 0;
    
    hungerStatusBarHeight = 380;
    cleanlinessStatusBarHeight = 380;
    loveStatusBarHeight = 380;

    lifespanBarLength = 0;
    
    isTadpoleDead = false;
    
    daysLived = 0;
    
    addNewScore = true;
}


