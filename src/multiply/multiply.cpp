#include "multiply/multiply.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

namespace aptive_exercise
{
    void MultiplyIntegers::processArguments(const std::vector<int> &args) {
        long long result = 1;
        for (const auto& arg:args){
            result*=arg;
            if (result==0){
                break;
            }
        }
        std::cout<<result;
    }
    void MultiplyIntegers::processFile(const std::string &aFile) {
        std::fstream ifile(aFile);
        ifile<<std::dec;
        long long result = 1;
        if (ifile.fail()){
            assert(false, "corrupted or missing file");
        }
        while (!ifile.eof()){
            int val;
            ifile>>std::dec>>val;
            if (ifile.fail()){
                assert(false, "corrupted file");
            }
            result *= val;
        }
        std::cout<<result;
    }
} // namespace aptive_exercise