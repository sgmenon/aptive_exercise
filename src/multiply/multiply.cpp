#include "multiply/multiply.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

namespace aptive_exercise
{
    MultiplyIntegers::MultiplyIntegers() 
        :fOutStream{ &std::cout } {}
    void MultiplyIntegers::processArguments(const std::vector<int> &args) {
        long long result = 1;
        for (const auto& arg:args){
            result*=arg;
            if (result==0){
                break;
            }
        }
        (*fOutStream)<<result;
    }
    STATUS MultiplyIntegers::processFile(const std::string &aFile) {
        std::fstream ifile(aFile);
        ifile<<std::dec;
        long long result = 1;
        if (ifile.fail()){
            std::cerr << "corrupted or missing file";
            return STATUS::FAILURE;
        }
        while (!ifile.eof()){
            int val;
            ifile>>std::dec>>val;
            if (ifile.fail()){
                std::cerr << "corrupted file";
                return STATUS::FAILURE;
            }
            result *= val;
            if (result == 0) {
                break;
            }
        }
        (*fOutStream)<<result;
        return STATUS::SUCCESS;
    }
} // namespace aptive_exercise