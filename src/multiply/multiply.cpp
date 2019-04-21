#include "multiply/multiply.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <climits>

namespace {
    bool checkOverUnderFlow(long long a, int x) {
        if (std::abs(x) > INT64_MAX / std::abs(a)) /* `a * x` would overflow/underflow */ {
            return false;
        }
        ///\todo: there's some specific condition involving 2s complement that may also overflow/underflow
        return true;
    }
}

namespace aptive_exercise
{
    MultiplyIntegers::MultiplyIntegers()
        :fOutStream{ &std::cout } {}
    STATUS MultiplyIntegers::processArguments(const std::vector<int> &args) {
        long long result = 1;
        for (const auto& arg : args) {
            if (!checkOverUnderFlow(result, arg)) {
                std::cerr << "Overflow/Underflow occurred";
                return STATUS::FAILURE;
            }
            result *= arg;
            if (result == 0) {
                break;
            }
        }
        (*fOutStream) << result;
        ///\todo:handle overflow/underflow
        return STATUS::SUCCESS; //nothing can go wrong with multiplying numbers apart from overflow/underflow
    }
    STATUS MultiplyIntegers::processFile(const std::string &aFile) {
        std::fstream ifile(aFile);
        ifile << std::dec;
        long long result = 1;
        if (ifile.fail()) {
            std::cerr << "corrupted or missing file" << std::endl;
            return STATUS::FAILURE;
        }
        while (!ifile.eof()) {
            int val;
            ifile >> std::dec >> val;
            if (ifile.fail()) {
                std::cerr << "corrupted file" << std::endl;
                return STATUS::FAILURE;
            }
            if (!checkOverUnderFlow(result, val)) {
                std::cerr << "Overflow/Underflow occurred";
                return STATUS::FAILURE;
            }
            result *= val;
            if (result == 0) {
                break;
            }
        }
        (*fOutStream) << result;
        return STATUS::SUCCESS;
    }
} // namespace aptive_exercise