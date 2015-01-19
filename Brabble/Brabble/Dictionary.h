//
//  Dictionary.h
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#ifndef __Brabble__Dictionary__
#define __Brabble__Dictionary__

#include <iostream>
#include <vector>
#include <fstream>

class Dictionary{
    private:
    
    public:
    std::vector<std::string> words;
    Dictionary() : words() {};
    std::vector<std::string> getWords();
    std::vector<std::string> loadDictionary(std::string const& filepath);
    std::vector<std::string> sortDictWords();
    void printDictionary();
    
};

#endif /* defined(__Brabble__Dictionary__) */
