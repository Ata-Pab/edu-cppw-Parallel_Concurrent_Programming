#include <thread>
#include <chrono>
#include <iostream>

void xCleanerThreadHandler()
{
    while (true)
    {
        std::cout << "Cleaned the kitchen.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread cleanerThread(xCleanerThreadHandler);
    cleanerThread.detach(); // Detach the thread to let it run independently, terminating when main thread ends

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Processing other tasks...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

    std::cout << "Main thread is done!\n";
    // cleanerThread.join(); // Not needed since we detached the thread
}