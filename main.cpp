/**
 * Необходимо реализовать класс контейнера,
 * реализующий интерфейс dictionary и способный выбросить исключение,
 * реализующее интерфейс not_found_exception.
 * При разработке допускается использовать STL.
 */


#include <iostream>

#include "dict.h"

int main()
{
    myDictionary <size_t, std::string> dict;
    dict.Set(1, "One");
    dict.Set(2, "Two");
    dict.Set(7, "Seven");
    dict.Set(9, "Nine");
    try
    {
        std::cout << dict.Get(1) << std::endl;
        std::cout << dict.Get(2) << std::endl;
        std::cout << dict.Get(7) << std::endl;
        std::cout << dict.Get(8) << std::endl;
        std::cout << dict.Get(9) << std::endl;
    }
    catch (const my_not_found_exception<size_t> &e)
    {
        std::cerr << "Error: key '" << e.getKey() << "' is not found." << std::endl;
    }

    return 0;
}
