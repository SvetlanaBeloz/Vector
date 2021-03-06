#include "Vector.h"
#include "Stack.h"


int main()
{
    Vector v;
    for (int i = 0; i < 10; i++)
        v.PushBack(rand() % 100);
    v.Print();
    v.Insert(45, 5);
    v.Print();
    v.RemoveByIndex(5);
    v.Print();
    v.RemoveByValue(62);
    v.Print();
    v.PopFront();
    v.Print();
    v.PopBack();
    v.Print();
    std::cout << v.IndexOf(34) << std::endl;
    std::cout << v.LastIndexOf(50) << std::endl;
    v.Reverse();
    v.Print();
    v.SortAsc();
    v.Print();
    v.SortDesc();
    v.Print();
    v.Shuffle();
    v.Print();
    v.RandomFill(5);
    v.Print();

    Vector a;
    a.PushBack(46);
    a.PushBack(91);
    a.PushBack(34);
    a.PushBack(42);
    a.PushBack(73);
    a.PushBack(32);
    a.PushBack(62);
    a.PushBack(61);
    a.PushBack(96);
    a.Print();
    if (v.Equals(a)) {
        std::cout << "The arrays are equal" << std::endl;
    }
    else {
        std::cout << "The arrays are not equal" << std::endl;
    }
    std::cout << a.GetElementAt(5) << std::endl;

    Vector c(a);
    c.Print();
    if (v == a)
        std::cout << "ok!\n";
    else std::cout << "no!\n";

    Vector d;
    d.RandomFill(20);
    d.Print();
    Vector e = d;
    e.Print();
    std::cout << e[15] << std::endl;
    std::cin >> e;
    e.Print();
    std::cout << e;

    
    Stack st;
    while (!st.IsFull())
        st.Push(rand() % 90 + 10);
    st.Clear();
    std::cout << st.GetCount() << std::endl;
    if (st.IsFull())
        std::cout << "ok!\n";
    else std::cout << "no\n";
    if (st.IsEmpty())
        std::cout << "ok!\n";
    else std::cout << "no\n";
    while (!st.IsFull())
        st.Push(rand() % 90 + 10);

    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();
    std::cout << st.Peek() << std::endl;
    st.Pop();

}