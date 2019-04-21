#ifndef _cacl_calculator_
#define _cacl_calculator_

#include <memory>
#include <string>
#include <vector>
#include <type_traits>
#include <unordered_map>
#include "EngineInterface.hpp"

namespace aptive_exercise
{
    template <typename T, typename K, 
        std::enable_if<
            std::is_trivially_constructible<K>::value && 
            std::is_base_of<EngineInterface<T>, K>::value>>
    struct EngineFactory
    {
        EngineFactory() = delete;
        static std::unique_ptr<EngineInterface<T>> create(){
            return {new K()};
        }
    };
    
    template<typename T>
    class Calculator {
        std::unordered_map<std::string, std::unique_ptr<EngineInterface<T>>> fEngines;
    public:
        template<typename K>
        void addEngine() {
            auto lEngine = EngineFactory<T, K>::create();
            fEngines[lEngine->name] = lEngine;
        }
        EngineInterface<T>* getEngine(const std::string& aName) {
            auto fr = fEngines.find(aName);
            if (fr!=fEngines.end()){
                return fr->second.get();
            } else {
                return nullptr;
            }
        }
    };
} // namespace aptive_exercise
#endif /*_cacl_calculator_*/