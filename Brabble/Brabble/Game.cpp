//
//  Game.cpp
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#include "Game.h"

//int const numThreads = 4;

void Game::wordVal(Dictionary const& dict, LetterBag const& lets){
    int sum = 0;
    for (auto it=dict.words.begin(); it != dict.words.end(); ++it){
        std::string word = *it;
        for (int i = 0; i< word.length(); i++){
            char let = word.at(i);
            for (auto it= lets.bagVals.begin(); it != lets.bagVals.end(); ++it){
                char compLet = it->first.at(0);
                if (let == compLet){
                    sum += it->second[1];
                    break;
                }
            }
        }
        wordValsMap.insert(std::pair<std::string,int> (word,sum));
        sum = 0;
    }
}

bool myComp(std::pair<std::string,int> const& first, std::pair<std::string,int> const& second){
    if (first.second > second.second){
        return true;
    }
    return false;
}

std::vector<std::pair<std::string,int>> possibilities(std::vector<std::string>const& myLets, std::map<std::string,int>const& wwv){
    std::map<std::string,int> goodMatches;
    std::string match = "";
    
    for (auto itt = wwv.begin(); itt != wwv.end(); ++itt){
        std::string word = itt->first;
        int val = itt->second;
        std::vector<std::string> rackCopy = myLets;
        for (int i = 0; i < word.length(); i++){
            for (int j = 0; j < rackCopy.size(); j++){
                if (word[i] == rackCopy.at(j)[0]){
                    match += rackCopy.at(j)[0];
                    rackCopy.erase(rackCopy.begin()+j);
                    break;
                }
            }
        }
        rackCopy.clear();
        if (match == word){
            goodMatches.insert(std::pair<std::string,int> (word,val));
        }
        val = 0;
        match = "";
    }
    std::vector<std::pair<std::string,int> > compVec(goodMatches.begin(), goodMatches.end());
    sort(compVec.begin(), compVec.end(), &myComp);
    return compVec;
}

void Game::showCheats(Player plyr, std::map<std::string,int> wvm){
    std::vector<std::pair<std::string,int>> cheatWords;
    cheatWords = possibilities(plyr.letterTray, wvm);
    int cnt = 0;
    
    std::cout << "-----------------------------------------------------"  << std::endl;
    std::cout << "                 Cheat Words are: " << std::endl;
    std::cout << "-----------------------------------------------------"  << std::endl;
    
    for (auto it = cheatWords.begin(); it != cheatWords.end(); ++it){
        if (cnt < numCheatWordsToShow){
            std::cout << it->first << " : " << it->second << std::endl;
        } else {
            break;
        }
        cnt++;
    }
}

void Game::showGameBag(LetterBag const& lets){
    std::cout << "-----------------------------------------------------"  << std::endl;
    std::cout << "          Remaining Letters In Game Bag              "  << std::endl;
    std::cout << "-----------------------------------------------------"  << std::endl;
    
    int cnt = 0;
    for (auto it = lets.bag.begin(); it != lets.bag.end(); ++it){
        cnt++;
        if (cnt%letModVal == 0){
            std::cout << *it << " " << std::endl;
        } else {
            std::cout << *it << " " ;
        }
    }
    
}

void Game::clearContentsOfGame(Player &plyr, LetterBag &letBag){
    plyr.letterTray.erase(plyr.letterTray.begin(), plyr.letterTray.end());
    letBag.bag.erase(letBag.bag.begin(), letBag.bag.end());
}

void Game::printWordValsMap(){
    for (auto it = wordValsMap.begin(); it !=wordValsMap.end(); ++it){
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

int Game::takeWord(Player &plyr, Utils &utils, LetterBag &letBag){
    std::string word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::cout << std::endl << std::endl;
    std::cout << "Player Tray Letters: " << std::endl;
    plyr.showLetters();
    std::cout << std::endl << std::endl;
    getline(std::cin, word);
    
    if ((word == "B")){
        letBag.printBag();
        return 0;
    } else if (word == "C"){
        showCheats(plyr, wordValsMap);
        return 0;
    } else if (word == "N"){
        plyr.letsBackToBag(letBag);
        return 0;
    } else if (word == "R"){
        utils.showRules();
        return 0;
    } else if (word == "S"){
        shuffle(plyr.letterTray.begin(), plyr.letterTray.end(), g);
        return 0;
    } else if (word == "T"){
        clearContentsOfGame(plyr, letBag);
        return 0;
    } else if (word == "V"){
        letBag.showLetterValues();
        return 0;
    } else if (word.length() < 2 ){
        std::cout << std::endl;
        std::cout << "One letter words are not valid.  If you were looking for a help character," << std::endl;
        std::cout << "please enter the upper case." << std::endl;
        return 0;
    } else if (!plyr.wordCheck(word)){
        std::cout << std::endl;
        std::cout << "This word is not in the dictionary or you do not have those letters,      "<< std::endl;
        std::cout << "please try again." << std::endl;
        return 0;
    } else {
        for (auto it = wordValsMap.begin(); it != wordValsMap.end(); ++it){
            if (it->first == word){
                if (word.length() > bonusLetWordGreaterThan){
                    plyr.updateScore(it->second + bonusPoints);
                    std::cout << std::endl << "Word Score is: " << it->second << " with " << bonusPoints << " point BONUS for a word with ";
                    std::cout << bonusLetWordGreaterThan + 1 << " letters or more!" << std::endl;
                } else {
                    plyr.updateScore(it->second);
                    std::cout << std::endl << "Word Score is: " << it->second << std::endl;
                }
                plyr.removeLetters(word);
                plyr.fillMyLetters(letBag);
                break;
            }
        }
    }
    shuffle(letBag.bag.begin(), letBag.bag.end(), g);
    showGameBag(letBag);
    return 0;
}

void Game::endGame(Player &plyr){
    std::cout << "-----------------------------------------------------"  << std::endl;
    std::cout << "   Thanks for playing!!! Your FINAL SCORE is: " << plyr.getScore() << std::endl;
    std::cout << "-----------------------------------------------------"  << std::endl;
}

void Game::playGame(Player &plyr, Utils &utils, LetterBag &letBag, Dictionary &dict, std::string const& filePath){
    std::random_device rd;
    std::mt19937 g(rd());
    
    utils.showRules();
    dict.loadDictionary(filePath);
    dict.sortDictWords();
    letBag.initializeBagVals();
    letBag.initializeBag();
    shuffle(letBag.bag.begin(), letBag.bag.end(), g);
    dict.sortDictWords();
    wordVal(dict, letBag);
    plyr.fillMyLetters(letBag);

    
    while (letBag.bag.size() != 0){
        utils.showHelpEscapes();
        takeWord(plyr, utils, letBag);
        if (letBag.bag.size() != 0){
            plyr.printScoreUpdate();
        }
    }
    
    endGame(plyr);
}

