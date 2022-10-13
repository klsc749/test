#include <iostream>
#include <vector>
#include <memory>

class test
{
private:
    /* data */
    std::string name;
public:
    test(/* args */);
    explicit test(const std::string& a){
        name = a;
    }
    ~test();

    operator double() const{
        std::cout << name << " ";
        return 0.5;
    }
};

test::test(/* args */)
{
}

test::~test()
{
}

void TestMove(int& a){
    std::cout << a << std::endl;
}


class CopyTest{
public:
    CopyTest(){
        std::cout << "construct" << std::endl;
    }

    CopyTest(const CopyTest& copy){
        std::cout << "&copy" << std::endl;
    }

    CopyTest(const CopyTest&& copy){
        std::cout << "&&copy" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::unique_ptr<int> up1(new int);
    *up1 = 5;
    
    std::cout << up1.get() << std::endl;
    std::cout << *up1 << std::endl;
    std::unique_ptr<int> up2(std::move(up1));
    std::cout << up1.get() << std::endl;
    std::cout << up2.get() << std::endl;
	return 0;
}
