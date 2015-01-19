//
//  Game.h
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#ifndef __Brabble__Game__
#define __Brabble__Game__

#include <iostream>
#include <algorithm>
#include "Player.h"
#include "LetterBag.h"
#include "Dictionary.h"
#include "Utils.h"

class Game{
    private:
    int const numCheatWordsToShow = 5;
    int const letModVal = 20;
    int const bonusLetWordGreaterThan = 9;
    int const bonusPoints = 10;
    
    public:
    std::map<std::string,int> wordValsMap;
    Game() : wordValsMap() {};
    void wordVal(Dictionary const& dict, LetterBag const& lets);
    void printWordValsMap();
    void showCheats(Player plyr,std::map<std::string,int> wvm);
    void showGameBag(LetterBag const& lets);
    void clearContentsOfGame(Player &plyr, LetterBag &letBag);
    int takeWord(Player &plyr, Utils &utils, LetterBag &letBag);
    void endGame(Player &plyr);
    void playGame(Player &plyr, Utils &utils, LetterBag &letBag, Dictionary &dict, std::string const& filePath);

};

#endif /* defined(__Brabble__Game__) */
