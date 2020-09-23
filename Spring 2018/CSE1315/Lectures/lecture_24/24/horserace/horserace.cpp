#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include "horse.h"

// Our three competitors, assigned random speeds (smaller is faster)
Horse horse1("Legs of Spaghetti", 100 + std::rand() % 100);
Horse horse2("Ride Like the Calm", 100 + std::rand() % 100);
Horse horse3("Duct-taped Lightning", 100 + std::rand() % 100);

// The gallop threads, which decrement position after a random delay
void gallop(Horse& horse)
{
    while (horse.position() > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(horse.speed() + std::rand() % 200));
        horse.move();
    }
}

// Utility function to print the horse track
void view(int position) {
    for (int i = 0; i < position; ++i) std::cout << (i%5 == 0 ? ':' : '.');
}

int main()
{
    // Randomize the pseudorandom number generator
    std::srand(std::time(NULL));

    // Constructs the new threads (horses) and runs them
    std::thread t1{gallop, std::ref(horse1)};
    std::thread t2{gallop, std::ref(horse2)};
    std::thread t3{gallop, std::ref(horse3)};

    // Display the horse track as the race runs
    while (horse1.position() > 0
       &&  horse2.position() > 0
       &&  horse3.position() > 0) {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        view(horse1.position());
        std::cout << " " << horse1.name() << std::endl;
        view(horse2.position());
        std::cout << " " << horse2.name() << std::endl;
        view(horse3.position());
        std::cout << " " << horse3.name() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
        
    // Join the threads
    t1.join();
    t2.join();
    t3.join();
}

