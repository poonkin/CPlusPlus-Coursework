//
//  main.cpp
//  Brabble
//
//  Created by bsaterfiel on 3/5/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//



#include "Player.h"
#include "Game.h"
#include "Utils.h"
#include "Dictionary.h"
#include "LetterBag.h"


int main(){
    
    Utils utils;
    Player plyr;
    Dictionary dict;
    LetterBag lets;
    Game game;
    std::string const& filePath =  "brabblewords.txt";
    
    // Please note that if the 'C' function is not working, you need to
    // go to Product -> Scheme -> Edit Scheme -> Run (on left Menu)
    // -> Check box with "Use Custom Wroking Directory" -> Then add the Brabble directory
    // Uncomment the code below if you need to test the file connectivitiy
    
    /*
    std::ifstream myfile;
    myfile.open("brabblewords.txt");
    if (myfile.is_open()){
        std::cout << "File successfully open";
        myfile.close();
    } else {
        std::cout << "Error opening file";
    }
     */
    
    game.playGame(plyr, utils ,lets, dict, filePath);

    return 0;
    
}