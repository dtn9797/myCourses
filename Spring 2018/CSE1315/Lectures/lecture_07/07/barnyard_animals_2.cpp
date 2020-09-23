#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

class Critter {
  public:
    Critter(int frequency) : _frequency{frequency}, _timer{0} { }
    void count() {if (++_timer > _frequency) _timer = 0;}
    void speak() { if (!_timer) cout << "Generic critter sound!" << endl; }
  protected:
    int _frequency;
    int _timer;
};

class Cow : public Critter {
  public:
    Cow(int frequency) : Critter(frequency) { }
    void speak() { if (!_timer) cout << "Moo! Mooooo!" << endl; }
};

class Dog : public Critter {
  public:
    Dog(int frequency) : Critter(frequency) { }
    void speak() { if (!_timer) cout << "Woof! Woof!" << endl; }
};

class Chicken : public Critter {
  public:
    Chicken(int frequency) : Critter(frequency) { }
    void speak() { if (!_timer) cout << "Cluck! Cluck!" << endl; }
};

int main() {
  vector<Dog> dogs = {Dog{11}, Dog{9}, Dog{3}};
  vector<Cow> cows = {Cow{7}, Cow{13}};
  vector<Chicken> chickens{Chicken{2}, Chicken{5}};

  cout << "W E L C O M E   T O   T H E   B A R N Y A R D !" << endl;
  for (int i=0; i<120; ++i) {
    for (auto& c: dogs) { c.count(); c.Critter::speak(); }
    for (auto& c: cows) { c.count(); c.Critter::speak(); }
    for (auto& c: chickens) { c.count(); c.Critter::speak(); }
    this_thread::sleep_for(chrono::milliseconds(50));
  }
}
