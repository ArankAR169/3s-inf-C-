#include <iostream>

int fibonacci(int number) 
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    int number, numeric_fib;
    std::cout << "enter the number of the required numeric: ";
    std::cin >> number;
    for (int i = 0; i <= number; i++)
        numeric_fib = fibonacci(i);
    std::cout << "The required Fibonacci number: " << numeric_fib;

}


