# Byte
Byte length integer type for C++ to replace __int8.

Works like any other value type.
```C++
#include <iostream>
#include ".\byte_type.hpp"
using namespace std;

int main() {
    byte* ptr = new byte[8]();

    for(int i = 0; i < 16; i++)
        ptr[i] = (byte) i;

    for(int i = 0; i < 16; i++)
        cout << ptr[i] << endl;

    cin.get();
}
```
