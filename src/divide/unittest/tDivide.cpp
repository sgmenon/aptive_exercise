#include "divide/divide.hpp"
#include "calc_interface/Calculator.hpp"
#include "gtest/gtest.h"

using namespace aptive_exercise;

TEST(Divider, CanCalculatorFindIt){
    Calculator<int> calculator;
    calculator.addEngine<DivideIntegers>();
    auto engine = calculator.getEngine("Divide");
    ASSERT_NE(engine, nullptr);
}

TEST(Divider, ArgList){
    DivideIntegers engine;
    std::ostringstream fakeOstream;
    engine.setOutStream(fakeOstream);
    engine.processArguments({ 1,2,3,4,5,6,7,8,9,10 });
    EXPECT_EQ(fakeOstream.str(), "2.755731922e-07");
    fakeOstream.str("");
    engine.processArguments({ 1000,10,1 });
    EXPECT_EQ(fakeOstream.str(), "100");   
}

TEST(Divider, FileTester){
    auto fileLocation = std::string(UNITTEST_DIR) + "/testFiles/first.txt"; //ahh... if only adding boost would not complicate your ability to run this example easily
    DivideIntegers engine;
    std::ostringstream fakeOstream;
    engine.setOutStream(fakeOstream);
    engine.processFile(fileLocation);
    EXPECT_EQ(fakeOstream.str(), "2.755731922e-07");
    fakeOstream.str("");
    fileLocation = std::string(UNITTEST_DIR) + "/testFiles/second.txt";
    engine.processFile(fileLocation);
    EXPECT_EQ(fakeOstream.str(), "1"); 
}

TEST(Divider, FileNegative) {
    auto fileLocation = std::string(UNITTEST_DIR) + "/testFiles/negative.txt"; 
    DivideIntegers engine;
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
