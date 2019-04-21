#ifndef _calc_engine_interface
#define _calc_engine_interface

#include <memory>
#include <string>
#include <vector>
#include <type_traits>

template <class T>
using void_t = void;

namespace aptive_exercise {

    enum class STATUS {
        SUCCESS,
        FAILURE
    };
    template <typename T>
    class EngineInterface
    {
    public:
        virtual ~EngineInterface() {};
        /*!
         * \brief Name of the engine
        */
        virtual const std::string getName() const = 0;
        /*!
         * \brief: processArguments reads the input data from a vector in memory, calculates a result
         *  and display the result on stdout.
        */
        virtual STATUS processArguments(const std::vector<T>& args) = 0;
        /*!
         * \brief ProcessFile reads the input data from a file, calculates a result
         *  and display the result on stdout.
         * This is different from processArguments as the user may not want to load all arguments to memory
         * in order to do processing.
         * \return Status: success or failure at parsing the file. 
         * This function is meant to be exception safe, and I consider the use of RTTI not something I would 
         * use in a production embedded system
        */
        virtual STATUS processFile(const std::string& aFile) = 0;
    };
} // namespace aptive_exercise
#endif /*_calc_engine_interface*/