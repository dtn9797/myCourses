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
int main() {
  vector<Critter> critters{Critter{13}, Critter{11}, Critter{7}, Critter{3}};

  cout << "W E L C O M E   T O   T H E   B A R N Y A R D !" << endl;
  for (int i=0; i<20; ++i) {
    for (Critter& c: critters) { c.count(); c.speak(); }
    this_thread::sleep_for(chrono::milliseconds(50));
  }
}
