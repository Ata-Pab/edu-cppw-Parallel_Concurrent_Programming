#include <thread>
#include <chrono>
#include <iostream>

void chef_olivia() {
    std::cout << "Olivia started & waiting for sausage to thaw...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Olivia is done cutting sausage.\n";
}

int main() {
    std::cout << "Barron requests Olivia's help.\n";
    std::thread olivia(chef_olivia);
    std::cout << "Olivia is Joinable?" << (olivia.joinable() ? " Yes\n" : " No\n");

    std::cout << "Barron continues cooking soup.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Olivia is Joinable?" << (olivia.joinable() ? " Yes\n" : " No\n");

    std::cout << "Barron patiently waits for Olivia to finish and join...\n";
    olivia.join(); // works like await in JS, waits for the thread to finish (barrier)
    std::cout << "Olivia is Joinable?" << (olivia.joinable() ? " Yes\n" : " No\n");
    
    std::cout << "Barron and Olivia are both done!\n";
}