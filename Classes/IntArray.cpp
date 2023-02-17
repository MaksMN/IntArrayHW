#include "IntArray.h"
#include <climits>

IntArray::IntArray(int length) : m_length{length}
{
    if (length < 0)
    {
        throw IntArrayBadLength();
    }
    if (length > 0)
    {
        m_data = new int[length]{};
    }
}

IntArray::IntArray(const IntArray &a)
{
    reallocate(a.getLength());
    for (int index{0}; index < m_length; ++index)
    {
        m_data[index] = a.m_data[index];
    }
}

IntArray::~IntArray()
{
    delete[] m_data;
}

void IntArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int &IntArray::operator[](int index)
{
    if (index < 0 || index > m_length || m_length == 0)
    {
        throw IntArrayBadRange();
    }
    return m_data[index];
}

void IntArray::reallocate(int newLength)
{
    if (newLength <= 0 || newLength == m_length)
    {
        throw IntArrayBadLength();
    }
    erase();
    if (newLength <= 0)
        return;
    m_data = new int[newLength];
    m_length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength <= 0 || newLength == m_length)
    {
        throw IntArrayBadLength();
    }
    int *data{new int[newLength]};
    if (m_length > 0)
    {
        int elementsToCopy{(newLength > m_length) ? m_length : newLength};

        for (int index{0}; index < elementsToCopy; ++index)
        {
            data[index] = m_data[index];
        }
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

IntArray &IntArray::operator=(const IntArray &a)
{
    if (&a == this)
    {
        return *this;
    }
    reallocate(a.getLength());
    for (int index{0}; index < m_length; ++index)
    {
        m_data[index] = a.m_data[index];
    }
    return *this;
}

void IntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)
    {
        throw IntArrayBadRange();
    }
    int *data{new int[m_length + 1]};
    for (int before{0}; before < index; ++before)
    {
        data[before] = m_data[before];
    }
    data[index] = value;
    for (int after{index}; after < m_length; ++after)
    {
        data[after + 1] = m_data[after];
    }
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index)
{
    if (index < 0 || index > m_length)
    {
        throw IntArrayBadRange();
    }
    if (m_length == 1)
    {
        erase();
        return;
    }
    int *data{new int[m_length - 1]};
    for (int before{0}; before < index; ++before)
    {
        data[before] = m_data[before];
    }
    for (int after{index + 1}; after < m_length; ++after)
    {
        data[after - 1] = m_data[after];
    }
    delete[] m_data;
    m_data = data;
    --m_length;
}

int IntArray::search(int value)
{
    for (int i = 0; i < getLength(); i++)
    {
        if (m_data[i] == value)
        {
            return i;
        }
    }
    throw IntArrayNotFound();
}

IntArray IntArray::searchAll(int value)
{
    IntArray results;
    for (int i = 0; i < getLength(); i++)
    {
        if (m_data[i] == value)
        {
            results.insertAtEnd(i);
        }
    }
    if (results.getLength() > 0)
    {
        return results;
    }
    else
    {
        throw IntArrayNotFound();
    }
}

void IntArray::listValues(std::string message, bool showIndexes)
{
    std::cout << message;
    for (int i = 0; i < getLength(); i++)
    {
        if (showIndexes)
        {
            std::cout << "[" << i << "]=>";
        }
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}