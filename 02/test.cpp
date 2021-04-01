#include "parse.h"


void TokenParser::ParserFunctionStart(){
    std::cout << "Call:Start" << std::endl;
}
void TokenParser::ParserFunctionEnd(){
    std::cout << "Call:End" << std::endl;
}
void TokenParser::ParserFunctionDigitToken(int token){
    std::cout << "found number: " << token << std::endl;
}
void TokenParser::ParserFunctionStringToken(const std::string& token){
    std::cout << "found not a number: " << token << std::endl;
}





void CorrectStringTest()
{
    TokenParser Parser;
    const std::string& strTest = " 5326 \t hfdhu 30938 sw";
    std::cout << "initial string:" << strTest << std::endl;
    std::cout << "parse result:" << std::endl;

    Parser.SetStartCallback(&TokenParser::ParserFunctionStart);
    Parser.SetEndCallback(&TokenParser::ParserFunctionEnd);
    Parser.SetDigitTokenCallback(&TokenParser::ParserFunctionDigitToken);
    Parser.SetStringTokenCallback(&TokenParser::ParserFunctionStringToken);
    Parser.Parse(strTest);
    std::cout << std::endl;
}


void CorrectStringTest2()
{
    TokenParser Parser;
    const std::string& strTest2 = "beatngu  4you 43";
    std::cout << "initial string:" << strTest2 << std::endl;
    std::cout << "parse result:" << std::endl;

    Parser.SetStartCallback(&TokenParser::ParserFunctionStart);
    Parser.SetEndCallback(&TokenParser::ParserFunctionEnd);
    Parser.SetDigitTokenCallback(&TokenParser::ParserFunctionDigitToken);
    Parser.SetStringTokenCallback(&TokenParser::ParserFunctionStringToken);
    Parser.Parse(strTest2);
    std::cout << std::endl;
}

void EmptyString()
{
    TokenParser Parser;
    const std::string& strTest2 = "";
    std::cout << "initial string:" << strTest2 << std::endl;
    std::cout << "parse result:" << std::endl;

    Parser.SetStartCallback(&TokenParser::ParserFunctionStart);
    Parser.SetEndCallback(&TokenParser::ParserFunctionEnd);
    Parser.SetDigitTokenCallback(&TokenParser::ParserFunctionDigitToken);
    Parser.SetStringTokenCallback(&TokenParser::ParserFunctionStringToken);
    Parser.Parse(strTest2);
    std::cout << std::endl;

}

void SepOnlyString()
{
    TokenParser Parser;
    const std::string& strTest2 = "\n \t \t \t \t \n \n";
    std::cout << "initial string:" << strTest2 << std::endl;
    std::cout << "parse result:" << std::endl;

    Parser.SetStartCallback(&TokenParser::ParserFunctionStart);
    Parser.SetEndCallback(&TokenParser::ParserFunctionEnd);
    Parser.SetDigitTokenCallback(&TokenParser::ParserFunctionDigitToken);
    Parser.SetStringTokenCallback(&TokenParser::ParserFunctionStringToken);
    Parser.Parse(strTest2);
    std::cout << std::endl;

}

void StdInStringTest()
{
    TokenParser Parser;
    std::string strTested;
    std::getline(std::cin, strTested);
    std::cout << "initial string:" << strTested << std::endl;
    std::cout << "parse result:" << std::endl;

    Parser.SetStartCallback(&TokenParser::ParserFunctionStart);
    Parser.SetEndCallback(&TokenParser::ParserFunctionEnd);
    Parser.SetDigitTokenCallback(&TokenParser::ParserFunctionDigitToken);
    Parser.SetStringTokenCallback(&TokenParser::ParserFunctionStringToken);
    Parser.Parse(strTested);
    std::cout << std::endl;
}

void WorkIfFirstAndLastLetterAreSep()
{
    TokenParser Parser;
    const std::string& strTest = "\t5326 \t hfdhu 30938 sw\n";
    std::cout << "initial string:" << strTest << std::endl;
    std::cout << "parse result:" << std::endl;

    Parser.SetStartCallback(&TokenParser::ParserFunctionStart);
    Parser.SetEndCallback(&TokenParser::ParserFunctionEnd);
    Parser.SetDigitTokenCallback(&TokenParser::ParserFunctionDigitToken);
    Parser.SetStringTokenCallback(&TokenParser::ParserFunctionStringToken);
    Parser.Parse(strTest);
    std::cout << std::endl;
}

void CallBackNotSet()
{
    TokenParser Parser;
    const std::string& strTest = "5326 \t hfdhu 30938 sw";
    std::cout << "initial string:" << strTest << std::endl;
    std::cout << "parse result:" << std::endl;

    //Parser.SetStartCallback(&TokenParser::ParserFunctionStart);
    //Parser.SetEndCallback(&TokenParser::ParserFunctionEnd);
    //Parser.SetDigitTokenCallback(&TokenParser::ParserFunctionDigitToken);
    //Parser.SetStringTokenCallback(&TokenParser::ParserFunctionStringToken);
    Parser.Parse(strTest);
    std::cout << std::endl;
}


int main(void){

    CorrectStringTest();
    CorrectStringTest2();
    EmptyString();
    SepOnlyString();
    WorkIfFirstAndLastLetterAreSep();
    CallBackNotSet();//ѕарсинг произошЄл,но вывод нет,так и должно быть
    //StdInStringTest()

    return 0;
}
