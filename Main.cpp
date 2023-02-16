#include "Classes\IntArray.h"

int main()
{
    // создать контейнер;
    IntArray array1 = IntArray(10);
    // заполнить его
    for (int i = 0; i < array1.getLength(); i++)
    {
        array1[i] = i;
    }
    array1.listValues("Все элементы массива array1: ");

    // скопировать контейнер
    IntArray array2;
    array2 = array1;
    array2.listValues("Все элементы массива array2, он копия массива array1: ");

    try
    {
        IntArray arr(-5);
    }
    catch (IntArrayBadLength &e)
    {
        std::cout << "Исключение - Создание массива. IntArray arr(-5); " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // получить доступ к любому элементу контейнера по индексу
    std::cout << "Доступ по индексу: "
              << "array1[4] = " << array1[4] << " | array2[3] = " << array2[3] << std::endl;
    try
    {
        int x = array1[100500];
    }
    catch (IntArrayBadRange &e)
    {
        std::cout << "Исключение - доступ по индексу. array1[100500]; " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // изменить размер контейнера;
    array1.resize(5);
    array1.listValues("Все элементы массива array1 после уменьшения размера: ");

    array2.resize(15);
    for (int i = 10; i < array2.getLength(); i++)
    {
        array2[i] = 0; // присвоить нули неопределенным значениям
    }
    array2.listValues("Все элементы массива array2 после увеличения размера: ");
    try
    {
        array1.resize(-5);
    }
    catch (IntArrayBadLength &e)
    {
        std::cout << "Исключение - размер контейнера. array1.resize(-5); " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // вставить элемент в контейнер;
    array1.insertBefore(333, 2);
    array1.listValues("Вставка значения 333 в индекс 2 в array1: ");
    try
    {
        array1.insertBefore(333, 100500);
    }
    catch (IntArrayBadRange &e)
    {
        std::cout << "Исключение - Вставка значения. array1.insertBefore(333, 100500); " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // удалить элемент из контейнера.
    array1.remove(2);
    array1.listValues("Удаление элемента с индексом 2 в array1: ");
    try
    {
        array1.remove(-5);
    }
    catch (IntArrayBadRange &e)
    {
        std::cout << "Исключение - Удаление элемента. array1.remove(-5); " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Вставка в начало
    array1.insertAtBeginning(444);
    array1.listValues("Вставка элемента со значением 444 в начало array1: ");

    // Вставка в конец
    array1.insertAtEnd(777);
    array1.listValues("Вставка элемента со значением 777 в конец array1: ");
    std::cout << std::endl;

    // Поиск в контейнере элемента по значению
    array1.insertBefore(55, 6);
    array1.listValues("Массив array1: ");
    int index = array1.search(55);
    std::cout << "В массиве array1 найдено число 55 под индексом: " << index << std::endl;
    try
    {
        int index = array1.search(100500);
    }
    catch (IntArrayNoFoundException &e)
    {
        std::cout << "Исключение - Поиск элемента. " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Поиск в контейнере элементов по значению
    IntArray search;
    search = array2.searchAll(0);
    array2.listValues("Массив array2: ");
    search.listValues("В массиве array2 найдены значения 0 в индексах: ");
    try
    {
        search = array2.searchAll(100500);
    }
    catch (IntArrayNoFoundException &e)
    {
        std::cout << "Исключение - Поиск элементов. " << e.what() << std::endl;
    }

    return 0;
}