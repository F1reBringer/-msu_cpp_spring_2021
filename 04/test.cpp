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
    assert(a + b == BigInt("23333333231"));
    assert(a + c == 0);
    assert(c + a == 0);
    assert(c + d == BigInt("-23333333231"));

    assert(a + 1 == BigInt("12345678911"));
    assert(b + (-1) == BigInt("10987654320"));
    assert(d + 1 == BigInt("-10987654320"));
    assert(c + (-1) == BigInt("-12345678911"));

}

void TestingSubtraction()
{
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    assert(a - b == BigInt("1358024589"));
    assert(b - a == BigInt("-1358024589"));
    assert(a - a == 0);
    assert(c - c == 0);

    assert(a - (-1) == BigInt("12345678911"));
    assert(b - 1 == BigInt("10987654320"));
    assert(d - (-1) == BigInt("-10987654320"));
    assert(c - 1 == BigInt("-12345678911"));

}

void TestingMultiplication()
{
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    assert(a * b == BigInt("135650052221140070110"));
    assert(c * d == BigInt("135650052221140070110"));
    assert(b * c == BigInt("-135650052221140070110"));
    assert(a * d == BigInt("-135650052221140070110"));

    assert(a * 0 == 0);
    assert(a * (-1) == BigInt("-12345678910"));

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



int main(void)
{
    BigInt a("99999999999999999999999999"), b(100), c;
    c = a*b;
    std::cout << c << std::endl;
    TestingLessAndLessorequalOperators();
    TestingBiggerAndBiggerorequalOperators();
    TestingEquality();
    TestingAddition();
    TestingSubtraction();
    TestingMultiplication();
    TestingUnaryMinus();
    std::cout << "Result of printtest:"<<std::endl;
    TestingPrintFunc();
    return 0;
}
