#ifndef _calc_divide
#define _calc_divide

#include "calc_interface/EngineInterface.hpp"
#include "spec.hpp"
#include <iostream>
#include <sstream>

namespace aptive_exercise
{
    class DIVIDE_EXPORT DivideIntegers : public EngineInterface<int>
    {
        std::ostream* fOutStream;
    public:
        DivideIntegers();
        void setOutStream(std::ostream& aStream) {
            fOutStream = &aStream;
        }
        virtual const std::string getName() const override {return "Divider";}
        virtual STATUS processArgumentsImpl(const std::vector<int>& args) override;
        virtual STATUS processFileImpl(const std::string& aFile) override;
    };
} // namespace aptive_exercise
#endif /*_calc_divide*/