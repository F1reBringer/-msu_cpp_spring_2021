#include <iostream>
#include <cstddef>
#include <string>

class TokenParser
{
public:
    typedef void (TokenParser::*ParserFunction)();
    typedef void (TokenParser::*ParserFunctionDigit)(int token);
    typedef void (TokenParser::*ParserFunctionString)(const std::string& token);
private:
    ParserFunction StartFunction;
    ParserFunction EndFunction;
    ParserFunctionDigit DigitTokenFunction;
    ParserFunctionString StringTokenFunction;

public:
    TokenParser(){
        StartFunction = nullptr;
        EndFunction = nullptr;
        DigitTokenFunction = nullptr;
        StringTokenFunction = nullptr;
    };

    void ParserFunctionStart();
    void ParserFunctionEnd();
    void ParserFunctionDigitToken(int token);
    void ParserFunctionStringToken(const std::string& token);

    void SetStartCallback(ParserFunction StartFunctionArg){
      StartFunction = StartFunctionArg;
    }
    void SetEndCallback(ParserFunction EndFunctionArg){
        EndFunction = EndFunctionArg;
    }
    void SetDigitTokenCallback(ParserFunctionDigit DigitTokenFunctionArg){
        DigitTokenFunction = DigitTokenFunctionArg;
    }
    void SetStringTokenCallback(ParserFunctionString StringTokenFunctionArg){
        StringTokenFunction = StringTokenFunctionArg;
    }

    void Parse(const std::string& StringToProcess);
};
