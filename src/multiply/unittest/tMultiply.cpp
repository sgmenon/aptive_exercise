#include "multiply/multiply.hpp"
#include "calc_interface/Calculator.hpp"
#include "gtest/gtest.h"

using namespace aptive_exercise;

TEST(Multiplier, CanCalculatorFindIt){
    Calculator<int> calculator;
    calculator.addEngine<MultiplyIntegers>();
    auto engine = calculator.getEngine("Multiply");
    ASSERT_NE(engine, nullptr);
}

TEST(Multiplier, ArgList){
    MultiplyIntegers engine;
    std::ostringstream fakeOstream;
    engine.setOutStream(fakeOstream);
    engine.processArguments({ 1,2,3,4,5,6,7,8,9,10 });
    EXPECT_EQ(fakeOstream.str(), "3628800");
    fakeOstream.str("");
    engine.processArguments({ 1,0,3,4,5,6,7,8,9,10 });
    EXPECT_EQ(fakeOstream.str(), "0");
    fakeOstream.str("");
    engine.processArguments({});
    EXPECT_EQ(fakeOstream.str(), "1");
    fakeOstream.str("");
    engine.processArguments({93493, 2323, 23235});
    EXPECT_EQ(fakeOstream.str(), "5046275793165");    
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
