#ifndef _calc_multiply
#define _calc_multiply

#include "calc_interface/EngineInterface.hpp"
#include "spec.hpp"

namespace aptive_exercise
{
    class MULTIPLY_EXPORT MultiplyIntegers : public EngineInterface<int>
    {
        virtual const std::string getName() const override {return "Multiply";}
        virtual void processArguments(const std::vector<int>& args) override;
        virtual void processFile(const std::string& aFile) override;
    };
} // namespace aptive_exercise
#endif /*_calc_multiply*/