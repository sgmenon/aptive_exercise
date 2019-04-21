#include "calc_interface/EngineInterface.hpp"
#include "calc_interface/Calculator.hpp"
#include "multiply/multiply.hpp"
#include <string>
#include <vector>
#include <iomanip>

namespace {
    enum STR2INT_ERROR
    {
        SUCCESS_T,
        OVERFLOW_T,
        UNDERFLOW_T,
        INCONVERTIBLE_T
    };
    STR2INT_ERROR str2int(int &i, char const *s, int base = 0)
    {
        char *end;
        long l;
        errno = 0;
        l = strtol(s, &end, base);
        if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX)
        {
            return OVERFLOW_T;
        }
        if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN)
        {
            return UNDERFLOW_T;
        }
        if (*s == '\0' || *end != '\0')
        {
            return INCONVERTIBLE_T;
        }
        i = static_cast<int>(l); //should be same for 32bit and 64bit platforms
        return SUCCESS_T;
    }
} // namespace

void main(int argc, char *argv[])
{
    std::vector<std::string> args;
    std::vector<int> int_args;
    args.reserve(argc - 1);
    int_args.reserve(argc - 1);
    using namespace aptive_exercise;
    Calculator<int> calculator;
    if (argc<2){
        return;
    }
    calculator.addEngine<MultiplyIntegers>();
    auto engine = calculator.getEngine(argv[1]);
    bool areWeProcessingInts = true;
    //parse inputs
    for (int i = 2; i < argc; ++i)
    {
        args.push_back(argv[i]);        
        if (areWeProcessingInts)
        {
            int val;
            auto result = str2int(val, argv[i]);
            if (result != SUCCESS_T){
                areWeProcessingInts = false;
            } else {
                int_args.push_back(val);
            }
        }
    }
    if (areWeProcessingInts) {
        engine->processArguments(int_args);
    } else {
        for (const auto&arg:args) {
            if (engine->processFile(arg+".txt") != STATUS::SUCCESS) {
                exit(1);
            }
        }
    }
}