#ifndef _calc_multiply
#define _calc_multiply

#include "calc_interface/EngineInterface.hpp"
#include "spec.hpp"
#include <iostream>
#include <sstream>

namespace aptive_exercise
{
    class MULTIPLY_EXPORT MultiplyIntegers : public EngineInterface<int>
    {
        std::ostream* fOutStream;
    public:
        MultiplyIntegers();
        void setOutStream(std::ostream& aStream) {
            fOutStream = &aStream;
        }
        virtual const std::string getName() const override {return "Multiply";}
        virtual void processArguments(const std::vector<int>& args) override;
        virtual STATUS processFile(const std::string& aFile) override;
    };
} // namespace aptive_exercise
#endif /*_calc_multiply*/