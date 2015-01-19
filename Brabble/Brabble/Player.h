//
//  Player.h
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#ifndef __Brabble__Player__
#define __Brabble__Player__

#include <iostream>
#include <vector>
#include <deque>
#include <random>
#include "LetterBag.h"

class Player{
    private:
    int score;
    int const numTiles = 15;
    
    public:
    std::vector<std::string> letterTray;
    Player() : score(0){};
    inline void updateScore(int pts){ score += pts; };
    inline int getScore(){ return score; }
    void printScoreUpdate();
    void fillMyLetters(LetterBag & lets);
    bool wordCheck(std::string const& word);
    void removeLetters(std::string const& word);
    void letsBackToBag(LetterBag& letBag);
    void showLetters();
    
};

#endif /* defined(__Brabble__Player__) */
