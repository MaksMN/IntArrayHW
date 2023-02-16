#pragma once
#include <iostream>
#include <cassert>
#include <exception>
#include "IntArrayBadRange.h"
#include "IntArrayBadLength.h"

/// @brief Создает массив Integer
class IntArray
{
private:
    int m_length{};
    int* m_data{};
    int null_ptr = 0;

public:
    IntArray() = default;

    /// @brief Создает массив указанной длинны
    /// @param <int>length Длина массива
    IntArray(int length);

    /// @brief Конструктор копирования
    /// @param <IntArray>a 
    IntArray(const IntArray &a);

    ~IntArray();

    /// @brief Удаляет все элементы массива
    void erase();

    int &operator[](int index);

    /// @brief Меняет размер массива с удалением существующих элементов.
    /// @exception IntArrayBadLength
    /// @param <int>newLength Новая длинна массива.
    void reallocate(int newLength);

    /// @brief Меняет размер массива. Существующие элементы сохранены.
    /// @exception IntArrayBadLength
    /// @param <int>newLength Новая длинна массива.
    void resize(int newLength);

    IntArray &operator=(const IntArray &a);

    /// @brief Добавляет в массив элемент перед указанным индексом
    /// @exception IntArrayBadRange
    /// @param value Значение нового элемента
    /// @param index Индекс перед которым будет создан новый элемент
    void insertBefore(int value, int index);

    /// @brief Удаляет из массива элемент с указанным индексом
    /// @exception IntArrayBadRange
    /// @param index Индекс перед которым будет создан новый элемент
    void remove(int index);

    /// @brief Добавляет элемент в начало массива
    /// @param value Значение нового элемента
    void insertAtBeginning(int value) { insertBefore(value, 0); }

    /// @brief Добавляет элемент в конец массива
    /// @param value Значение нового элемента
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    /// @brief Возвращает длину массива
    /// @return int
    int getLength() const { return m_length; }
};