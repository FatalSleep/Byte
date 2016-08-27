#ifndef __BYTE_TYPE__
#define __BYTE_TYPE__
    #include <type_traits>

    struct byte {
    private:
        __int8 data;

    public:
        byte() {
            data = 0;
        }
        
        template<typename T>
        byte(T value) {
            #ifdef __TEMPLATE_DEBUG__
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
                std::is_same<T, double>::value;
            static_assert(type_check, "ERROR: Type <T> must be fractional, integeral or character.");
            #endif
            
            data = static_cast<__int8>(value);
        }

        byte(byte& value) {
            data = value.data;
        }

        template<typename T>
        byte& operator =(T value) {
            #ifdef __TEMPLATE_DEBUG__
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
                std::is_same<T, double>::value;
            static_assert(type_check, "ERROR: Type <T> must be fractional, integeral or character.");
            #endif
            
            data = static_cast<__int8>(value);
            return *this;
        }

        byte& operator =(byte& value) {
            data = value.data;
            return *this;
        }

        operator unsigned __int32() {
            return data;
        }
    };
#endif
