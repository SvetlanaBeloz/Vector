#include <iostream>
#include <algorithm>
#pragma once

class Vector
{
    unsigned int size = 0;
    unsigned int capacity = 10;
    int* data = nullptr; 

public:
    Vector();
    Vector(unsigned int capacity);
    ~Vector();

private:
    void EnsureCapacity();

public:
    unsigned int GetSize() const;
    unsigned int GetCapacity() const;
    void PushBack(int value);
    void PushFront(int value);
    void Clear();
    bool IsEmpty() const;
    void Print() const;
    void Insert(int number, int index);
    void RemoveByIndex(int index);
    void RemoveByValue(int value);
    void PopFront();
    void PopBack();
    void TrimToSize();
    int IndexOf(int index);
    int LastIndexOf(int value);
    void Reverse();
    void SortAsc();
    void SortDesc();
    void Shuffle();
    void RandomFill(int size);
    bool Equals(Vector& origin);
    int GetElementAt(int index);
    Vector(const Vector& original);
    Vector& operator = (const Vector& original);
    int operator[](int index);
    friend bool operator == (const Vector left, const Vector right);
    friend std::istream& operator >> (std::istream& is, Vector& original);
    friend std::ostream& operator << (std::ostream& os, const Vector& original);
};

