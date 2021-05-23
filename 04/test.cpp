#include "BigInt.h"
#include <cassert>


void TestingLessAndLessorequalOperators()
{
    assert(BigInt(234) < BigInt(423));
    assert(BigInt(234) <= BigInt(423));
    assert(BigInt(100) <= BigInt(100));

    assert(BigInt(234) < BigInt("423"));
    assert(BigInt(234) <= BigInt("423"));
    assert(BigInt(77) <= BigInt("77"));

    assert(BigInt(300) < 301);
    assert(BigInt(401) <= 602);
    assert(BigInt(100) <= 100);

    assert(BigInt(-10000) < BigInt(-1000));
    assert(BigInt(-5555) <= BigInt(-555));
    assert(BigInt(-666) <= BigInt(-666));

    assert(BigInt(-322) < BigInt("-128"));
    assert(BigInt(-322) <= BigInt("-128"));
    assert(BigInt(-444) <= BigInt("-444"));

    assert(BigInt(-300) < -100);
    assert(BigInt(-300) <= -100);
    assert(BigInt(-333) <= -333);
}

void TestingBiggerAndBiggerorequalOperators()
{
    assert(BigInt(1000) > BigInt(100));
    assert(BigInt(1000) >= BigInt(100));
    assert(BigInt(100) >= BigInt(100));

    assert(BigInt(1000) > BigInt("100"));
    assert(BigInt(1000) >= BigInt("100"));
    assert(BigInt(77) >= BigInt("77"));

    assert(BigInt(301) > 300);
    assert(BigInt(602) >= 401);
    assert(BigInt(100) >= 100);

    assert(BigInt(-1000) > BigInt(-10000));
    assert(BigInt(-555) >= BigInt(-5555));
    assert(BigInt(-666) >= BigInt(-666));

    assert(BigInt(-100) > BigInt("-1000"));
    assert(BigInt(-100) >= BigInt("-1000"));
    assert(BigInt(-444) >= BigInt("-444"));

    assert(BigInt(-100) > -300);
    assert(BigInt(-100) >= -300);
    assert(BigInt(-333) >= -333);

}

void TestingEquality()
{
    assert(BigInt(100) == 100);
    assert(BigInt(-123456) == -123456);
    assert(BigInt(654321) != -654321);
    assert(BigInt(-654321) != 654321);
}

void TestingAddition()
{
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");

    assert( (a + b).ToString() == "23333333231");
    assert((a + c).ToString() == "0");
    assert((c + a).ToString() == "0");
    assert((c + d).ToString() == "-23333333231");

    assert( (a + 1).ToString() == "12345678911");
    assert( (b + (-1)).ToString() == "10987654320");
    assert( (d + 1).ToString() == "-10987654320");
    assert( (c + (-1)).ToString() == "-12345678911");

}

void TestingSubtraction()
{
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    assert((a - b).ToString() ==  "1358024589");
    assert( (b - a).ToString() == "-1358024589");
    assert( (a - a).ToString() == "0");
    assert( (c - c).ToString() == "0");

    assert( (a - (-1)).ToString() == "12345678911");
    assert( (b - 1).ToString() == "10987654320");
    assert( (d - (-1)).ToString() == "-10987654320");
    assert( (c - 1).ToString() == "-12345678911");

}

void TestingMultiplication()
{
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    assert( (a * b).ToString() == "135650052221140070110");
    assert( (c * d).ToString() == "135650052221140070110");
    assert( (b * c).ToString() == "-135650052221140070110");
    assert( (a * d).ToString() == "-135650052221140070110");
    assert( (a * 0).ToString() == "0");
    assert( (a * (-1)).ToString() == "-12345678910");

}

void TestingUnaryMinus()
{
    BigInt a = 10, b = -123;
    assert(-a == -10);
    assert(-b == 123);
}

void TestingPrintFunc()
{
    BigInt a("12345678910"), b("-10987654321"), c("00005"), d("-0000");
    std::cout << "Print test" << std::endl;
    std::cout << "12345678910 = " << a << std::endl;
    std::cout << "-10987654321 = " << b << std::endl;
    std::cout << "5 = " << c << std::endl;
    std::cout << "0 = " << d << std::endl;
}



void ComparingNearZero()
{
    BigInt num1("12345678910"), num2("12345678911"), num3("-12345678911");
    assert( (num1 - num1).ToString() == "0");
    assert( (num3 - num3).ToString() == "0");
    assert( (num2 - num1) >= 0);
    assert( (num1 - num2 ) <= 0);
    assert( (num1 + num3) < 0);
    assert( (num1 + num2 + num3 ) > 0);
}

void ComparingCloseNumbers()
{
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    assert( (a - (-1)).ToString() == "12345678911");
    assert( (b - 1).ToString() == "10987654320");
    assert(BigInt(301) > 300);
    assert(BigInt(602) >= 601);
    assert(BigInt(100) >= 100);
    assert(BigInt(100) == 100);
    assert(BigInt(-123456) != -123457);
    assert(BigInt(300) < 301);
    assert(BigInt(401) <= 402);
    assert(BigInt(100) <= 100);

}

void ComparingBigNumbers()
{
    BigInt num1("111111111111111111111111111111111111111");;
    BigInt num2("22222222222222222222222222222222222222222222222");
    BigInt num3("-3333333333333333333333333333333333333333333333333333");
    assert( (num1 - num1).ToString() == "0");
    assert( (num3 - num3).ToString() == "0");
    assert( (num2 - num1) >= 0);
    assert( (num1 - num2 ) <= 0);
    assert( (num1 + num3) < 0);
    assert( (num1 + num2 + num3 ) < 0);

}


void Move_const_testing() {
    std::string str1 = "12948124712481287125712758919";
    BigInt num1(str1);
    BigInt num3(str1);
    BigInt num2 = std::move(num1);
    assert(num2 == num3);
    assert(num1.ArrIsNull() && (num1.GetSize() == 0));
}

void Move_operator_testing() {
    std::string str1 = "9812482174817841241";
    std::string str2 = "5125129853123131131291975";
    BigInt num1(str1);
    BigInt num2(str2);
    BigInt num3(str1);
    BigInt num4(str2);
    num1 = std::move(num2);
    assert(num2.ArrIsNull() && (num2.GetSize() == 0));
    assert(num1 == num4);
}



int main(void)
{
    //BigInt a("99999999999999999999999999"), b(100), c;
    //c = a*b;
    //std::cout << c << std::endl;
    ComparingBigNumbers();
    ComparingNearZero();
    ComparingCloseNumbers();
    TestingLessAndLessorequalOperators();
    TestingBiggerAndBiggerorequalOperators();
    TestingEquality();
    TestingAddition();
    TestingSubtraction();
    TestingMultiplication();
    TestingUnaryMinus();
    std::cout << "Result of printtest:"<<std::endl;
    TestingPrintFunc();
    Move_const_testing();
    Move_operator_testing();
    return 0;
}

