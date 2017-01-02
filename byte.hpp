#ifndef __BYTE_TYPE__
#define __BYTE_TYPE__
    #include <type_traits>
    #include <iostream>
    using namespace std;

    struct byte {
    private:
        unsigned __int8 data;

    public:
        byte() {}
        
        template<typename T>
        byte(T value) {
            #ifdef _DEBUG
            const bool type_check = std::is_same<T, bool>::value ||
                std::is_same<T, __int8>::value ||
                std::is_same<T, unsigned __int8>::value ||
                std::is_same<T, __int16>::value ||
                std::is_same<T, unsigned __int16>::value ||
                std::is_same<T, __int32>::value ||
                std::is_same<T, unsigned __int32>::value ||
                std::is_same<T, __int64>::value ||
                std::is_same<T, unsigned __int64>::value ||
                std::is_same<T, float>::value ||
                std::is_same<T, double>::value ||
                std::is_same<T, byte>::value;
            static_assert(type_check, "ERROR: Type <T> must be fractional, integeral or character.");
            #endif
            
            data = static_cast<unsigned __int8>(value);
        }
        
        operator unsigned __int32() {
            return data;
        }
    };
#endif
