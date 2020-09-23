#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>

// The function we want to execute on the new thread.
void task1(std::string msg)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200+std::rand()%200));
    std::cout << "task1 says: " << msg << std::endl;
}

int main()
{
    // Randomize the pseudorandom number generator
    std::srand(std::time(NULL));

    // Constructs the new thread and runs it. Does not block execution.
    std::thread t1(task1, "Hello");
    std::thread t2(task1, "Bonjour");
    std::thread t3(task1, "Hola");

    std::cout << "Thread 1 ID is " << t1.get_id() << std::endl;
    std::cout << "Thread 2 ID is " << t2.get_id() << std::endl;
    std::cout << "Thread 3 ID is " << t3.get_id() << std::endl;

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    t1.join();
    t2.join();
    t3.join();
}

