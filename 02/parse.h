#ifndef parse_h
#define parse_h

#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <functional>
#include <math.h>

using TokenCallback = std::function<std::string (const std::string &token)>;
using InfoCallback = std::function<void ()>;

class Parser{
private:
    InfoCallback StartCallback_;
    InfoCallback FinishCallback_;
    TokenCallback DigitCallback_;
    TokenCallback StringCallback_;
public:
    Parser();
    ~Parser() = default;
    std::vector<std::string> Parse(const std::string & str);
    void SetStartCallback(InfoCallback call);
    void SetFinishCallback(InfoCallback call);
    void SetDigitCallback(TokenCallback call);
    void SetStringCallback(TokenCallback call);
};

#endif


