//
//  Utils.cpp
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#include "Utils.h"

void Utils::showRules() {
    std::cout << std::endl;
    std::cout << "Here are the rules...you are given a group of letters with assigned points." << std::endl;
    std::cout << "Less frequent letters have higher points.  You can make any word that      " << std::endl;
    std::cout << "is in the dictionary and get the points for that word.  You will always see " << std::endl;
    std::cout << "the letters remaining so choose the words wisely.  Your goal is to make the" << std::endl;
    std::cout << "number of words that have the highest value while there are game letters   " << std::endl;
    std::cout << "remaining in the game bag. The letters in the tray will then be void.      " << std::endl;
    std::cout << std::endl;
    std::cout << "Please know that the bag is reshuffled after every guess.  So you only know" << std::endl;
    std::cout << "what is remaining as opposed to what will be coming up next.  These rules  " << std::endl;
    std::cout << "will only appear once, however you can get them from the R help key."        << std::endl;
}

void Utils::showHelpEscapes() {
    std::cout << std::endl;
    std::cout << "The single key entries that are valid are: " << std::endl;
    std::cout << "B --- See letters remaining in Bag." << std::endl;
    std::cout << "C --- Show Cheats for the words with highest points!" << std::endl;
    std::cout << "N --- New tray of letters." << std::endl;
    std::cout << "R --- Rules from the beginning." << std::endl;
    std::cout << "S --- Scramble the current letter tray to get a new perspective." << std::endl;
    std::cout << "T --- Take score and EXIT the game." << std::endl;
    std::cout << "V --- Display POINT Values of the Letters." << std::endl;
}