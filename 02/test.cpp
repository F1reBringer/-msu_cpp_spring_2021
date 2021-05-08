#include "parse.h"
#include <cassert>


void CorrectStringTestOne(){
    Parser parser;
    std::string str = "123 abc abc123 \t ABC1 \n 123a";
    std::vector<std::string> ans;
    std::vector<std::string> rightAns = {"123", "abc", "abc123", "ABC1", "123a"};
    ans = parser.Parse(str);
    assert(ans == rightAns);
}

void CorrectStringTestTwo(){
    Parser parser;
    std::string str = "5326 \t hfdhu 30938 sw";
    std::vector<std::string> ans;
    std::vector<std::string> rightAns = {"5326", "hfdhu", "30938", "sw"};
    ans = parser.Parse(str);
    assert(ans == rightAns);
}


void SepOnlyString(){
    std::cout << "SepOnlyString" <<std::endl;
    Parser parser;
    std::vector<std::string> ans;
    std::string str ="\n \t \t \t \t \n \n";
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true;
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true;
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}

void EmptyString(){
    std::cout << "EmptyString" <<std::endl;
    Parser parser;
    std::vector<std::string> ans;
    std::string str ="";
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true;
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true;
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}


void WorkIfFirstAndLastLetterAreSep(){
    std::cout << "WorkIfFirstAndLastLetterAreSep" <<std::endl;
    Parser parser;
    std::vector<std::string> ans;
    std::string str ="\t5326 \t hfdhu 30938 sw\n";
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true;
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true;
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}


void Uint64Test(){
    Parser parser;
    uint64_t s =  (uint64_t)(pow(2,48));
    std::string str;
    std::vector<std::string> ans;
    str += std::to_string(s);
    std::cout << "The Uint64 number is "<<s << std::endl;
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true;
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true;
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}

void Test2in64Plus1(){
    Parser parser;
    uint64_t s =  (uint64_t)(pow(2,64)+1);
    std::string str;
    std::vector<std::string> ans;
    str += std::to_string(s);
    std::cout << "The Uint64 +1  number is "<<s << std::endl;
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true;
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true;
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}

void TestingString_a(){
    Parser parser;
    std::string str = "a";
    std::vector<std::string> ans;
    std::cout << "Testing a"<< std::endl;
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true;
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true;
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}

void TestingNumber_1(){
    Parser parser;
    std::string str = "1";
    std::vector<std::string> ans;
    std::cout << "Testing 1"<< std::endl;
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true;
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true;
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}

int main(){
    CorrectStringTestOne();
    CorrectStringTestTwo();
    SepOnlyString();
    EmptyString();
    WorkIfFirstAndLastLetterAreSep();
    Uint64Test();
    Test2in64Plus1();
    TestingString_a();
    TestingNumber_1();
    std::cout << "Done!"<< std::endl;
    return 0;
}


