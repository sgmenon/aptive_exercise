#include "multiply/multiply.hpp"
#include "calc_interface/Calculator.hpp"
#include "gtest/gtest.h"
#include <climits>
#include <fstream>

using namespace aptive_exercise;

TEST(Multiplier, CanCalculatorFindIt){
    Calculator<int> calculator;
    calculator.addEngine<MultiplyIntegers>();
    auto engine = calculator.getEngine("Multiply");
    ASSERT_NE(engine, nullptr);
}

TEST(Multiplier, ArgListNegative){
    MultiplyIntegers engine;
    std::ostringstream fakeOstream;
    engine.setOutStream(fakeOstream);
    auto result = engine.processArguments({ 1,2,3,4,5,6,7,8,9,10 });
    EXPECT_EQ(fakeOstream.str(), "");
    EXPECT_EQ(result, STATUS::FAILURE);
}

TEST(Multiplier, FileTester){
    auto fileLocation = std::string(UNITTEST_DIR) + "/testFiles/first.txt"; //ahh... if only adding boost would not complicate your ability to run this example easily
    MultiplyIntegers engine;
    std::ostringstream fakeOstream;
    engine.setOutStream(fakeOstream);
    engine.processFile(fileLocation);
    EXPECT_EQ(fakeOstream.str(), "3628800");
    fakeOstream.str("");
    fileLocation = std::string(UNITTEST_DIR) + "/testFiles/second.txt";
    engine.processFile(fileLocation);
    EXPECT_EQ(fakeOstream.str(), "-5031812438398746"); //-5.031812438398746e+15
}

TEST(Multiplier, FileNegative) {
    auto fileLocation = std::string(UNITTEST_DIR) + "/testFiles/negative.txt"; 
    MultiplyIntegers engine;
    std::ostringstream fakeOstream;
    engine.setOutStream(fakeOstream);
    auto out = engine.processFile(fileLocation);
    EXPECT_EQ(fakeOstream.str(), "");
    EXPECT_EQ(out,STATUS::FAILURE);
    fakeOstream.str("");
    fileLocation = std::string(UNITTEST_DIR) + "/testFiles/doesNotExist.txt";
    out = engine.processFile(fileLocation);
    EXPECT_EQ(out, STATUS::FAILURE);
}

TEST(Multiplier, FileNegative2) {
    MultiplyIntegers engine;
    std::ostringstream fakeOstream;
    engine.setOutStream(fakeOstream);
    std::ofstream foo("foo.txt");
    for (auto i = 0; i < 3; i++) {
        foo << INT_MAX << std::endl;
    }
    foo.close();
    auto result = engine.processFile("foo.txt");
    EXPECT_EQ(fakeOstream.str(), "");
    EXPECT_EQ(result, STATUS::FAILURE);
    foo.open("foo.txt");
    for (auto i = 0; i < 2; i++) {
        foo << INT_MIN<< std::endl;
    }
    foo.close();
    result = engine.processFile("foo.txt");
    EXPECT_EQ(fakeOstream.str(), "");
    EXPECT_EQ(result, STATUS::FAILURE);
}
