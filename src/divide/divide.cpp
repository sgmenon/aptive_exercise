#include "divide/divide.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cmath>

namespace aptive_exercise
{
    DivideIntegers::DivideIntegers() 
        :fOutStream{ &std::cout } {}
    STATUS DivideIntegers::processArgumentsImpl(const std::vector<int> &args) {
        long double result = std::nanl("");
        bool isFirst = true;
        for (const auto& arg:args){
            if (isFirst) {
                result = static_cast<long double>(arg);
                isFirst = false;
                continue;
            }
            if (arg == 0) {
                std::cerr << "divide by zero error!" << std::endl;
                return STATUS::FAILURE;
            }
            result/=arg;
            if (result==0){
                break;
            }
        }
        (*fOutStream) << std::setprecision(10) << std::defaultfloat <<result;
        return STATUS::SUCCESS;
    }
    STATUS DivideIntegers::processFileImpl(const std::string &aFile) {
        std::fstream ifile(aFile);
        ifile<<std::dec;
        long double result = std::nanl("");
        bool isFirst = true;
        if (ifile.fail()){
            std::cerr << "corrupted or missing file"<<std::endl;
            return STATUS::FAILURE;
        }
        while (!ifile.eof()){
            int val;
            ifile>>std::dec>>val;
            if (ifile.fail()){
                std::cerr << "corrupted file"<<std::endl;
                return STATUS::FAILURE;
            }
            if (isFirst){
                result = static_cast<long double>(val);
                isFirst = false;
                continue;
            }
            if (val == 0) {
                std::cerr << "divide by zero error!"<<std::endl;
                return STATUS::FAILURE;
            }
            result /= val;
            if (result == 0) {
                break;
            }
        }
        (*fOutStream)<<std::setprecision(10)<<std::defaultfloat<<result;
        return STATUS::SUCCESS;
    }
} // namespace aptive_exercise