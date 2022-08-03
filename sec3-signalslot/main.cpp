#include <iostream>

int main(int argc, char* argv[]){

    /*
        auto foo = [capturelist] (parameterlist)->returntype{
            funciton body
        };
    */

    // generic lambda, operator() is a template with two parameters
    // auto glambda = []<class T>(T a, auto&& b) { return a < b; };
 

    auto foo = [](int a, int b){
        std::cout << "Sum " << a + b << std::endl;
    };

    class lambda;
    foo(6, 5);

    [](int a, int b){
        std::cout << "Sum2 " << a + b << std::endl;
    }(2,4);


    auto foo2 = [](int a, int b){
        return "al;sd";
    };
    std::cout << foo2(5, 6) << std::endl;

    auto foo3 = [](int a, int b)->int{
        return a+b;
    };
    std::cout << foo3(5, 6) << std::endl;

    int val = [](int a, int b)->int{
        return a+b;
    }(3, 5);
    std::cout << val << std::endl;


    std::cout << "======" << std::endl;
    // Capture List

    int a = 7;
    int b = 3;
    int c = 1;

    // not reachable
    // [](){
    //     std::cout << a  << std::endl;
    // };

    [a](){
        std::cout << a  << std::endl;
        // a = 12;  // not valid cunku burda a lvalue olarak alinmiyor
    }();

    // copy of variable , original variable
    [a, &b](){
        std::cout << a  << std::endl;
        std::cout << b  << std::endl;
        b = 123;  
    }();
    std::cout << b << std::endl;

    [&](){
        std::cout << a  << std::endl;
        std::cout << b  << std::endl;
        std::cout << c  << std::endl;
        c = 14;
    }();
    std::cout << c << std::endl;

    // passing capture value
    a = 0;
    auto f = [a](){
        std::cout << "+++ : " << a << "  ";
    };
    auto f2 = [&a](){
        std::cout << "--- : " << a << "  ";
    };

    for(int i=0; i<5; ++i){
        f();
        f2();
        std::cout << "=== : " << a << std::endl;
        a++;
    }

    // Capture everything

    // By Value
    [=](){
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }();

    // By reference
    [&](){
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        c = 12;
    }();

    return 0;
}