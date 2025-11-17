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

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Processing other tasks...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

    std::cout << "Main thread is done!\n";
    cleanerThread.join();
    // Even after the main thread is done, the cleanerThread will keep running
}