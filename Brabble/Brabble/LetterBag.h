//
//  LetterBag.h
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#ifndef __Brabble__LetterBag__
#define __Brabble__LetterBag__

#include <iostream>
#include <deque>
#include <map>
#include <vector>

class LetterBag{
    private:
    int const modVal = 13;
    int const letModVal = 20;
    
    public:
    std::map<std::string,std::vector<int> > bagVals;
    std::deque<std::string> bag;
    LetterBag() : bag() {};
    void initializeBagVals();
    void initializeBag();
    void printBag();
    void showLetterValues();
    
};

#endif /* defined(__Brabble__LetterBag__) */
