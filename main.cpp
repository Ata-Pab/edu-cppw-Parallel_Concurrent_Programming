#include <thread>
#include <chrono>
#include <unistd.h>
#include <iostream>

// a simple function that wastes CPU cycles "forever"
void cpu_waster()
{
    std::cout << "CPU Waster Process ID: " << getpid() << "\n";
    std::cout << "CPU Waster Thread ID " << std::this_thread::get_id() << "\n";
    while (true)
        continue;
}

int main()
{
    std::cout << "Main Process ID: " << getpid() << "\n";
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << "\n";
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);

    while (true)
    {
        // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}