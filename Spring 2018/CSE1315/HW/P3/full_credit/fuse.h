#include <string>
using namespace std;

class Fuse {
  public:
    Fuse(int time);
    bool burn();  // true if any fuse remains
    string to_string();
  private:
    int _time;
};

