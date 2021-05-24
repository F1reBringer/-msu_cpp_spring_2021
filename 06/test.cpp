#include "format.h"

#include <iostream>
#include <cassert>

void PositiveTesting()
{
    std::string text = format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");
    text = format("{001} + {0} + {2} = {3}", 1, 2, 3, 6);
    assert(text == "2 + 1 + 3 = 6");

    std::cout<<"PositiveTesting is Done!"<<std::endl;
}



void WrongValueTesting()
{
    bool flag = false;
    try
    {
        std::string text = format("{1.2} + {2}", 3, 4);
    }
    catch(const ValueError &e)
    {
        flag = true;
    }
    assert(flag);
    flag = false;
    try
    {
        std::string text = format("{0}, {1}", 1);
    }
    catch(const ValueError &e)
    {
        flag = true;
    }
    assert(flag);
    flag = false;
    try
    {
        std::string text = format("{}, {}", 1);
    }
    catch(const ValueError &e)
    {
        flag = true;
    }
    assert(flag);

    std::cout<<"WrongValueTesting is Done!"<<std::endl;
}

void BadBracketsTesting()
{
    bool flag = false;
    try
    {
        std::string text = format("{1} + {{2}}", 1, 2, 3);
    }
    catch(const BracketsError &e)
    {
        flag = true;
    }
    assert(flag);
    flag = false;
    try
    {
        std::string text = format("{1} + {2}}", 1, 2, 3);
    }
    catch(const BracketsError &e)
    {
        flag = true;
    }
    assert(flag);
    flag = false;
    try
    {
        std::string text = format("{{1} + {2}", 1, 2, 3);
    }
    catch(const BracketsError &e)
    {
        flag = true;
    }
    assert(flag);
    std::cout<<"BadBracketsTesting is Done!"<<std::endl;
}


void WrongArgumentsTesting()
{
  bool flag = false;
  try
  {
    std::string text = format("{1} + {2} + {3}", 1, 2, 3,4,5);
  } catch (const ArgumentError &e)
  {
      flag = true;
      std::cout << "WrongNumOfArguments!"<<std::endl;
  }
  assert(flag);
  std::cout<<"WrongArgumentsTestingIsDone!"<<std::endl;
}


void emptystringtest()
{
    std::string text = format("");
    assert( text == "");
    std::cout << "EmptyStringIsDone!"<<std::endl;
}

void juststring()
{
  std::string text = format("abcd");
  assert(text == "abcd");
  std::cout << "JustStringIsDone!"<<std::endl;
}

void NoSeparatorsTesting()
{
  std::string text = format("{0}{1}{2}{3}{4}", 1, 2, 3, 4, 5);
  assert(text == "12345");

  text = format("{0}{1}{2}{3}{4}{5}{6}{7}{8}{9}{10}{11}", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
  assert(text == "01234567891011");

  text = format("{0}{1}{0}{1}{0}{1}{0}{1}{0}{1}", "-", "+");
  assert(text == "-+-+-+-+-+");

  std::cout << "NoSeparatorsIsDone!"<<std::endl;
}

void OneArgumentTesting()
{
  std::string text = format("{0}{0} {0}{0}", "5");
  assert(text == "55 55");
  text = format("{0}", "5");
  assert(text == "5");
  std::cout << "OneArgumentIsDone!"<<std::endl;
}



void ExcessBracketsTesting()
{
  bool flag = false;
  try
  {
    std::string text = format("{0}{", 2);
  } catch (const BracketsError &e)
  {
      flag = true;
      std::cout << "expected } after {"<<std::endl;
  }
  assert(flag);

  flag = false;
  try
  {
    std::string text = format("{0}}", 2);
  } catch (const BracketsError &e)
  {
      flag = true;
      std::cout << "expected { before }"<<std::endl;
  }
  assert(flag);

  flag = false;
  try
  {
    std::string text = format("{1} + {1} = {0} }", 1, 2);
  } catch (const BracketsError &e)
  {
      flag = true;
      std::cout<<"expected { before }"<<std::endl;
  }
  assert(flag);

  std::cout<<"ExcessBracketsTestingIsDone!"<<std::endl;
}


void OutOfRangeValues()
{
   bool flag = false;
   try
  {
    std::string text = format("{3}", 2);
  } catch (const ValueError &e)
  {
      flag = true;
      std::cout<<"OutOfRange"<<std::endl;
  }
   assert(flag);
    std::cout<<"OutOfRangeIsDone!"<<std::endl;
}


void NotANumberTesting()
{
  bool flag = false;
  try {
    std::string text = format("{}");
  } catch (const ValueError &e)
  {
      std::cout<<"NotANumber"<<std::endl;
      flag = true;
  }
  assert(flag);

  flag = false;
  try {
   std::string text = format("{1} + {2} + {a}", 1, 2, 3);
      } catch (const ValueError &e){
    std::cout<<"NotANumber2"<<std::endl;
    flag = true;
    }

  assert(flag);
  std::cout<<"NotANumberTestingIsDone!"<<std::endl;

}


void BigNumberTesting()
{
  bool flag = false;
  try {
    std::string text = format("{2131412521545435436}", 1);
  } catch (const ValueError &e) {
      flag = true;
      std::cout<<"IncorrectValue"<<std::endl;
  }
  assert(flag);
  std::cout <<"BigNumberTestingIsDone!"<<std::endl;
}

void NotEnoughArgumentsTesting()
{
  bool flag = false;
  try {
    std::string text = format("{1}+{1} = {0}", 2);
  } catch (const ValueError &e) {
    std::cout<<"NotEnoughArguments"<<std::endl;
    flag = true;
  }
  assert(flag);
  std::cout<<"NotEnoughArgumentsTestingIsDone!"<<std::endl;

}




int main(){
    PositiveTesting();
    WrongValueTesting();
    BadBracketsTesting();
    WrongArgumentsTesting();
    emptystringtest();
    juststring();
    NoSeparatorsTesting();
    OneArgumentTesting();
    ExcessBracketsTesting();
    OutOfRangeValues();
    NotANumberTesting();
    BigNumberTesting();
    NotEnoughArgumentsTesting();

    return 0;
}


