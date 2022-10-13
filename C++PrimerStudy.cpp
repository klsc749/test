#include <iostream>

template <typename T>
class Test
{
public:
    T a, b;
    Test(T n, T m) : a(n), b(m){}
};


int main()
{
    Test<int> test(1, 2);
    std::cout << test.a << "," << test.b;
}