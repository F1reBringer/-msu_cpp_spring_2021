#include "parse.h"



void TokenParser::Parse(const std::string& StringToProcess){
    if( (TokenParser::StartFunction) != nullptr ) (this->*StartFunction)();

    std::string token;
    int position = -1;
    int lengthString = StringToProcess.length();
    while(position <= lengthString){
            position++;
            int TokenStartPosition = position;
            bool DigitToken = true;
            bool TokenFound = false;
            while( (position < lengthString) && (StringToProcess[position] != ' ') && (StringToProcess[position] != '\t') && (StringToProcess[position] != '\n')){
                if(isdigit(StringToProcess[position]) == false) DigitToken = false;
                TokenFound = true;
                position++;
            }
            if(!TokenFound) continue;
            int TokenEndPosition = position;
            token = StringToProcess.substr(TokenStartPosition, TokenEndPosition-TokenStartPosition);
            if(DigitToken){
                int num = atoi(token.c_str());
                if( (TokenParser::DigitTokenFunction) != nullptr ) (this->*DigitTokenFunction)(num);
            }
            else if( (TokenParser::StringTokenFunction) != nullptr ) (this->*StringTokenFunction)(token);
    }


    if( (TokenParser::EndFunction) != nullptr ) (this->*EndFunction)();
}

