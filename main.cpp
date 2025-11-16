#include <iostream>
#include <string>

int main() {
    std::string name;
    
    std::cout << "Welcome to C++ Fundamentals!" << std::endl;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "This is a simple C++ program." << std::endl;
    
    return 0;
}
