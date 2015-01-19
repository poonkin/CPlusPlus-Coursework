//
//  Dictionary.cpp
//  Brabble
//
//  Created by bsaterfiel on 3/22/14.
//  Copyright (c) 2014 bsaterfiel. All rights reserved.
//

#include "Dictionary.h"

int const removeGreater = 15;
int const removeLower = 2;

std::vector<std::string> Dictionary::getWords(){
    return words;
}

bool isOneLetter(std::string const& str){
    if (str.length() > removeGreater || str.length()< removeLower ){
        return true;
    }
    return false;
}

std::vector<std::string> Dictionary::loadDictionary(std::string const& filepath){
    //std::vector<std::string> gameDictionary;
    std::string word;
    std::ifstream wordsfile (filepath);
    while (wordsfile.is_open()){
        while ( getline (wordsfile,word) ){
            words.push_back(word);
        }
        wordsfile.close();
    }
    return words;
}

std::vector<std::string> Dictionary::sortDictWords(){
    std::string word;
    for (int i =0; i < words.size(); i++){
        word = words[i];
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words[i] = word;
    }
    sort(words.begin(), words.end());
    words.erase(remove_if(begin(words), end(words), isOneLetter), end(words));
    return words;
}

void Dictionary::printDictionary(){
    for (auto it=words.begin(); it != words.end(); ++it){
        std::cout << *it << std::endl;
    }
}