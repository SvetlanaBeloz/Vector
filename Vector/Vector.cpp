#include "Vector.h"

Vector::Vector() : Vector(10) {}
Vector::Vector(unsigned int capacity)
{
    if (capacity < 10)
    {
        capacity = 10;
    }
    this->capacity = capacity;
    data = new int[capacity];
}

Vector:: ~Vector()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
}

void Vector::EnsureCapacity()
{
    if (size == capacity)
    {
        capacity *= 2;
        int* temp = new int[capacity];
        for (unsigned int i = 0; i < size; i++)
            temp[i] = data[i];
        delete[] data;
        data = temp;
    }
}

void Vector::PushBack(int value)
{
    EnsureCapacity();
    data[size++] = value;
}

void Vector::PushFront(int value)
{
    EnsureCapacity();
    for (unsigned int i = size; i > 0; i--)
        data[i] = data[i - 1];
    data[0] = value;
    size++;
}

void Vector::Clear()
{
    size = 0;
}

bool Vector::IsEmpty() const
{
    return size == 0;
}

void Vector::Print() const
{
    if (IsEmpty())
    {
        std::cout << "Vector is empty.\n";
        return;
    }
    for (unsigned int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

unsigned int Vector::GetSize() const
{
    return size;
}

unsigned int Vector::GetCapacity() const
{
    return capacity;
}

void Vector::Insert(int value, int index)
{
    if (index < 0 || index > size)
        throw "Incorrect index!";
    EnsureCapacity();
    for (unsigned int i = size + 1; i >= index; i--)
        data[i + 1] = data[i];
    data[index] = value;
    size++;
}

void Vector::RemoveByIndex(int index)
{
    if (index < 0 || index >= size)
        throw "Incorrect index!";

    for (unsigned int i = index; i <= size - 1; i++)
        data[i] = data[i + 1];

    size--;
}

void Vector::RemoveByValue(int value)
{ 
    ffor (unsigned int i = 0; i < size; i++)
    {
        if (data[i] == value) {
            RemoveByIndex(i);
            i = -1;
        }
    }
}

void Vector::PopFront()
{
    for (unsigned int i = 0; i < size; i++)
        data[i] = data[i + 1];
    size--;
}

void Vector::PopBack()
{
    size--;
}

void Vector::TrimToSize()
{
    if (size != capacity)
    {
        capacity = size;
        int* temp = new int[capacity];
        for (unsigned int i = 0; i < size; i++)
            temp[i] = data[i];
        delete[] data;
        data = temp;
    }
}

int Vector::IndexOf(int value)
{
    for (unsigned int i = 0; i < size; i++) {
        if (data[i] == value)
            return i;
    }
    return -1;
}

int Vector::LastIndexOf(int value)
{
    for (int i = size - 1; i >= 0; i--) {
        if (data[i] == value)
            return i;
    }
    return -1;
}

void Vector::Reverse()
{
    for (unsigned int i = 0; i < size / 2; i++)
        std::swap (data[i], data[size - 1 - i]);
}

void Vector::SortAsc()
{
    for (unsigned int i = 0; i < size; i++)
    {
        int value = data[i];
        int index;
        for (index = i - 1; index >= 0 && data[index] > value; index--)
            std::swap(data[index + 1], data[index]);
    }
}

void Vector::SortDesc()
{
    for (unsigned int i = 0; i < size; i++)
    {
        int value = data[i];
        int index;
        for (index = i - 1; index >= 0 && data[index] < value; index--)
            std::swap(data[index + 1], data[index]);
    }
}

void Vector::Shuffle()
{
    for (unsigned int i = 0; i < size; i++) {
        int j = rand() % size;
        if (i != j) {
            std::swap(data[i], data[j]);
        }
    }
}

void Vector::RandomFill(int size)
{
    this ->size = size;
    this ->capacity = size;
    EnsureCapacity();
    for (unsigned int i = 0; i < size; i++)
        data[i] = rand() % 90 + 10;
}

bool Vector::Equals(Vector& origin)
{
    if (size != origin.size)
        return false;
    for (unsigned int i = 0; i < size; i++) {
        if (data[i] != origin.data[i]) {
            return false;
        }
    }
    return true;
}

int Vector::GetElementAt(int index)
{
    if (index < 0 || index >= size)
        throw "Incorrect index!";
    return data[index];
}

Vector::Vector(const Vector& original)
{
    size = original.size;
    capacity = original.capacity;
    data = new int[size];
    for (unsigned int i = 0; i < size; i++)
        data[i] = original.data[i];
}

bool operator == (const Vector left, const Vector right)
{
    if (left.size != right.size)
        return false;
    for (unsigned int i = 0; i < left.size; i++) {
        if (left.data[i] != right.data[i])
            return false;
    }
    return true;
}

Vector& Vector::operator = (const Vector& original)
{
    if (this == &original)
        return *this;
    delete[] data;
    size = original.size;
    capacity = original.capacity;
    data = new int[size];
    for (unsigned int i = 0; i < size; i++)
        data[i] = original.data[i];
    return *this;
}

int Vector::operator[](int index)
{
    if (index < 0 || index >= size)
        throw "Incorrect index!";
    return data[index];
}

std::istream& operator >> (std::istream& is, Vector& original)
{
    std::cout << "Please, enter the size of array: ";
    is >> original.size;
    std::cout << "Please, enter the capacity of array: ";
    is >> original.capacity;
    for (unsigned int i = 0; i < original.size; i++) {
        std::cout << "Please enter value for element " << i << " of array: ";
        is >> original.data[i];
    }
    return is;
}

std::ostream& operator << (std::ostream& os, const Vector& original)
{
    for (unsigned int i = 0; i < original.size; i++)
        os << original.data[i] << " ";
    return os;
}

