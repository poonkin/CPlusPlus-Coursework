//
//  Player.cpp
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#include "Player.h"

void Player::printScoreUpdate(){
    std::cout << std::endl << std::endl << "-----------------------------------------------------"  << std::endl;
    std::cout << "            Player TOTAL Score is: " << score << std::endl;
    std::cout << "-----------------------------------------------------"  << std::endl;
}

void Player::fillMyLetters(LetterBag & lets){
    for (auto it=lets.bag.begin(); it != lets.bag.end(); ++it){
        if (letterTray.size() < numTiles){
            letterTray.push_back(*it);
            lets.bag.pop_front();
        } else {
            break;
        }
    }
    std::cout << std::endl;
}

void Player::removeLetters(std::string const& word){
    for(int i = 0; i< word.length(); i++){
        for (int j=0; j<letterTray.size(); j++){
            if (word.at(i) == letterTray[j].at(0)){
                letterTray.erase(letterTray.begin()+j);
                break;
            }
        }
    }
}

bool Player::wordCheck(std::string const& word){
    std::string match = "";
    std::vector<std::string> letsCpy = letterTray;
    
    for (int j=0 ; j< word.length(); j++){
        if (match.length() < j){
            return false;
        }
        for (int i = 0; i < letsCpy.size(); i++){
            if (word.at(j) == letsCpy[i].at(0)){
                letsCpy.erase(letsCpy.begin()+i);
                match += word.at(j);
                break;
            }
        }
        if (match == word){
            return true;
        }
    }
    return false;
}

void Player::letsBackToBag(LetterBag& letBag){
    std::random_device rd;
    std::mt19937 g(rd());
    
    for(auto it=letterTray.begin(); it != letterTray.end(); ++it){
        letBag.bag.push_back(*it);
    }
    
    letterTray.erase(letterTray.begin(),letterTray.end());
    shuffle(letBag.bag.begin(), letBag.bag.end(), g);
    Player::fillMyLetters(letBag);
}

void Player::showLetters(){
    for (auto it = letterTray.begin(); it != letterTray.end(); ++it){
        std::cout << *it << " ";
    }
}