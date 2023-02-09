#pragma once
#include <cassert>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length);

    IntArray(const IntArray& a);

    ~IntArray();

    void erase();

    int& operator[](int index);

    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength);

    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength);

    IntArray& operator=(const IntArray& a);

    void insertBefore(int value, int index);

    void remove(int index);

    // A couple of additional functions just for convenience
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    int getLength() const { return m_length; }
};