//
//  LetterBag.cpp
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#include "LetterBag.h"

void LetterBag::initializeBagVals(){
    bagVals["a"]={9,1};
    bagVals["b"]={2,3};
    bagVals["c"]={2,3};
    bagVals["d"]={4,2};
    bagVals["e"]={12,1};
    bagVals["f"]={3,4};
    bagVals["g"]={3,2};
    bagVals["h"]={2,4};
    bagVals["i"]={9,1};
    bagVals["j"]={2,8};
    bagVals["k"]={2,5};
    bagVals["l"]={4,1};
    bagVals["m"]={3,3};
    bagVals["n"]={6,1};
    bagVals["o"]={8,1};
    bagVals["p"]={2,3};
    bagVals["q"]={1,10};
    bagVals["r"]={7,1};
    bagVals["s"]={5,1};
    bagVals["t"]={6,1};
    bagVals["u"]={4,1};
    bagVals["v"]={2,4};
    bagVals["w"]={2,4};
    bagVals["x"]={1,8};
    bagVals["y"]={3,4};
    bagVals["z"]={1,10};
}

void LetterBag::initializeBag(){
    for(auto it = bagVals.cbegin(); it != bagVals.cend(); ++it){
        std::string tile = it->first;
        for (int j = 0; j < it->second[0]; j++){
            bag.push_back(tile);
        }
    }
}

void LetterBag::printBag(){
    int ctr = 0;
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "---------       Current Letter Bag       ------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for(auto it = bag.cbegin(); it != bag.cend(); ++it){
        ctr++;
        if (ctr%letModVal == 0){
            std::cout << *it  << std::endl;
        } else {
            std::cout << *it  << " ";
        }
    }
    std::cout << std::endl ;
}

void LetterBag::showLetterValues(){
    int ctr = 0;
    for (auto it = bagVals.begin(); it != bagVals.end(); it++){
        ctr++;
        if (ctr%modVal == 0){
            std::cout << it->first.at(0) << " : " << it->second[1] << std::endl;
        } else {
            std::cout << it->first.at(0) << " : " << it->second[1] << " , ";
        }
    }
}

