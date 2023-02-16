#include "Classes\IntArray.h"

int main()
{    
    // создать контейнер;
    
    IntArray* array1 = new IntArray(10);
    delete array1;
    

    /**имитация исключений*/
    try
    {
        // создание массива с отрицательной длиной
        IntArray array2(-1);
    }    
    catch(IntArrayBadLength &e){
        std::cout << e.what() << std::endl;
    }


    try
    {
        // Присвоить значение индексу вне диапазона
        IntArray array3(10);
        array3[11] = 5;
    }
    catch (IntArrayBadRange &e)
    {
        std::cout << e.what()<< std::endl;
    }
    
    return 0;
}