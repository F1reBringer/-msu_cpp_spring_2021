#include "deserializer.h"
#include <cassert>
#include <sstream>

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a, b, c);
    }
};

struct AnotherData{
    uint64_t b;
    bool a;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a, b);
    }
};

void MainTesting(){
    Data data1 {110, true, 200};
    Data data2 {0, false, 110};

    std::stringstream streamstr;

    Serializer serializer(streamstr);
    Error err1 = serializer.Save(data1);

    Deserializer deserializer(streamstr);
    Error err2 = deserializer.Load(data2);

    assert(err1 == Error::NoError);
    assert(err2 == Error::NoError);

    assert(data1.a == data2.a);
    assert(data1.b == data2.b);
    assert (data1.c == data2.c);
}

void ErrorTesting(){
    AnotherData data1 {110, true};
    Data data2 {0, false, 0};

    std::stringstream streamstr;

    Serializer serializer(streamstr);
    Error err1 = serializer.Save(data1);

    Deserializer deserializer(streamstr);
    Error err2 = deserializer.Load(data2);

    assert(err1 == Error::NoError);
    assert(err2 == Error::CorruptedArchive);

    streamstr.clear();

    err1 = serializer.Save(data2);

    err2 = deserializer.Load(data1);

    assert(err1 == Error::NoError);
    assert(err2 == Error::CorruptedArchive);
}

void FourStructuresTesting(){
    AnotherData data1 {110, true};
    Data data2 {0, false, 0};
    AnotherData data3{0, false};
    Data data4 {100, true, 200};

    std::stringstream streamstr;

    Serializer serializer(streamstr);
    Error err1 = serializer.Save(data1);
    Error err3 = serializer.Save(data2);

    Deserializer deserializer(streamstr);
    Error err2 = deserializer.Load(data3);
    Error err4 = deserializer.Load(data4);

    assert(err1 == Error::NoError);
    assert(err2 == Error::NoError);
    assert(err3 == Error::NoError);
    assert(err4 == Error::NoError);

    assert(data1.a == data3.a);
    assert(data1.b == data3.b);

    assert(data2.a == data4.a);
    assert(data2.b == data4.b);
    assert(data2.c == data4.c);
}

int main(){
    MainTesting();
    ErrorTesting();
    FourStructuresTesting();
    return 0;
}
